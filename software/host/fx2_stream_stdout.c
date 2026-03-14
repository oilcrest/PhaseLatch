// fx2_stream_stdout.c : libusb async reader -> stdout
// gcc fx2_stream_stdout.c -o fx2_stream_stdout -O2 -Wall -lusb-1.0

#include <libusb-1.0/libusb.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>

static volatile int g_run = 1;
static volatile int g_inflight = 0;

typedef struct {
  libusb_device_handle *devh;
  uint8_t ep;
  size_t  xfer_len;
  int     interface;
} ctx_t;

typedef struct {
  ctx_t *ctx;
  struct libusb_transfer *xfer;
  uint8_t *buf;
  int done;
} slot_t;

static void on_sigint(int s){ (void)s; g_run = 0; }

static void LIBUSB_CALL on_rx(struct libusb_transfer *xfer){
  slot_t *slot = (slot_t*)xfer->user_data;
  if (xfer->status == LIBUSB_TRANSFER_COMPLETED && xfer->actual_length > 0) {
    size_t off = 0; const uint8_t *p = xfer->buffer; size_t n = (size_t)xfer->actual_length;
    while (off < n) {
      ssize_t w = write(STDOUT_FILENO, p + off, n - off);
      if (w < 0) {
        if (errno == EINTR) continue;
        // Downstream closed the pipe (e.g. `head -c`, calibration tool reading N samples).
        // Treat as a clean stop.
        if (errno == EPIPE) {
          g_run = 0;
          break;
        }
        g_run = 0;
        break;
      }
      off += (size_t)w;
    }
  } else if (xfer->status != LIBUSB_TRANSFER_COMPLETED) {
    g_run = 0;
  }

  if (g_run) {
    int rc = libusb_submit_transfer(xfer);
    if (rc != 0) g_run = 0;
    return;
  }

  if (!slot->done) {
    slot->done = 1;
    g_inflight--;
  }
}

static void usage(const char* a0){
  fprintf(stderr,
    "Usage: %s [-v vid] [-p pid] [-e ep_in] [-i interface] [-t xfer_len] [-n inflight]\n"
    "Defaults: vid=0x04B4 pid=0x8613 ep=0x86 interface=0 xfer_len=16384 inflight=32\n", a0);
}

int main(int argc, char **argv){
  uint16_t vid = 0x04B4, pid = 0x8613; uint8_t ep = 0x86; int iface=0; size_t xlen=16384; int nin=32;
  int opt; while ((opt=getopt(argc,argv,"v:p:e:i:t:n:h"))!=-1){
    switch(opt){
      case 'v': vid = (uint16_t)strtoul(optarg,NULL,0); break;
      case 'p': pid = (uint16_t)strtoul(optarg,NULL,0); break;
      case 'e': ep  = (uint8_t) strtoul(optarg,NULL,0); break;
      case 'i': iface= atoi(optarg); break;
      case 't': xlen = (size_t)strtoul(optarg,NULL,0); break;
      case 'n': nin  = atoi(optarg); break;
      default: usage(argv[0]); return 1;
    }
  }
  signal(SIGINT,on_sigint); signal(SIGPIPE,SIG_IGN);
  if (libusb_init(NULL)!=0){ fprintf(stderr,"libusb_init failed\n"); return 2; }
  libusb_device_handle *devh = libusb_open_device_with_vid_pid(NULL,vid,pid);
  if(!devh){ fprintf(stderr,"open %04x:%04x failed\n",vid,pid); libusb_exit(NULL); return 3; }
  libusb_set_auto_detach_kernel_driver(devh,1);
  if(libusb_claim_interface(devh,iface)!=0){ fprintf(stderr,"claim interface failed\n"); return 4; }
  // After claiming interface, set alt setting 1 for interface 0
  libusb_set_interface_alt_setting(devh, iface, 1);
  setvbuf(stdout,NULL,_IONBF,0);

  slot_t *slots = calloc((size_t)nin,sizeof(slot_t));
  struct timeval tv = {0,50000};
  int submitted = 0;
  for(int i=0;i<nin;i++){
    slots[i].ctx=NULL; slots[i].buf=malloc(xlen); slots[i].xfer=libusb_alloc_transfer(0); slots[i].done = 0;
    libusb_fill_bulk_transfer(slots[i].xfer,devh,ep,slots[i].buf,(int)xlen,on_rx,&slots[i],0);
    int rc=libusb_submit_transfer(slots[i].xfer);
    if(rc){ fprintf(stderr,"submit failed %d\n",rc); g_run=0; break; }
    submitted++;
  }
  g_inflight = submitted;
  while(g_run){ if(libusb_handle_events_timeout_completed(NULL,&tv,NULL)!=0) break; }

  // Stop and drain: cancelling is async; continue handling events until callbacks run.
  g_run = 0;
  for(int i=0;i<nin;i++) if(slots[i].xfer && !slots[i].done) libusb_cancel_transfer(slots[i].xfer);
  while (g_inflight > 0) {
    (void)libusb_handle_events_timeout_completed(NULL,&tv,NULL);
  }

  for(int i=0;i<nin;i++){ if(slots[i].xfer) libusb_free_transfer(slots[i].xfer); free(slots[i].buf);} 
  free(slots);
  libusb_release_interface(devh,iface); libusb_close(devh); libusb_exit(NULL);
  return 0;
}
