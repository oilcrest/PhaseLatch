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

all: fx2_stream_stdout

fx2_stream_stdout: fx2_stream_stdout.c
	$(CC) $(CFLAGS) $(INC_PATH) -o $@ $< $(LDFLAGS)

clean:
	rm -f fx2_stream_stdout

.PHONY: all clean
