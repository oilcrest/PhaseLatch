CC ?= gcc
CFLAGS ?= -O2 -Wall
LDFLAGS ?= -L/opt/homebrew/lib -lusb-1.0

# Add Homebrew libusb include path if present
HOMEBREW_INC := /opt/homebrew/include
USRLOCAL_INC := /usr/local/include

ifeq (,$(wildcard $(HOMEBREW_INC)/libusb-1.0/libusb.h))
  ifeq (,$(wildcard $(USRLOCAL_INC)/libusb-1.0/libusb.h))
    INC_PATH :=
  else
    INC_PATH := -I$(USRLOCAL_INC)
  endif
else
  INC_PATH := -I$(HOMEBREW_INC)
endif

all: fx2_stream_stdout iq_to_cf32 iq_dc_block iq_dc_cal iq_dc_apply iq_iqbal_tone_cal_cf32 iq_iqbal_apply_cf32

fx2_stream_stdout: fx2_stream_stdout.c
	$(CC) $(CFLAGS) $(INC_PATH) -o $@ $< $(LDFLAGS)

clean:
	rm -f fx2_stream_stdout iq_to_cf32 iq_dc_block iq_dc_cal iq_dc_apply iq_iqbal_tone_cal_cf32 iq_iqbal_apply_cf32

iq_to_cf32: iq_to_cf32.c
	$(CC) $(CFLAGS) -o $@ $<

iq_dc_block: iq_dc_block.c
	$(CC) $(CFLAGS) -o $@ $< -lm

iq_dc_cal: iq_dc_cal.c
	$(CC) $(CFLAGS) -o $@ $< -lm

iq_dc_apply: iq_dc_apply.c
	$(CC) $(CFLAGS) -o $@ $<

iq_iqbal_tone_cal_cf32: iq_iqbal_tone_cal_cf32.c
	$(CC) $(CFLAGS) -o $@ $< -lm

iq_iqbal_apply_cf32: iq_iqbal_apply_cf32.c
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: all clean
