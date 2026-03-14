# FX2 AD9201 Streamer (16‑bit padded, 512‑byte USB bulk packets)

This project streams 10‑bit samples from an **AD9201** (or similar) into a **Cypress/Infineon EZ‑USB FX2/FX2LP** using an **external IFCLK**, pads them to **16‑bit**, and sends them to the host in **512‑byte** USB bulk packets (the high‑speed bulk max packet size). The host app reads with **libusb** and writes raw bytes to **stdout**, so you can `mkfifo` and pipe into GNU Radio or other tools.

> **Highlights**
> - Firmware: **Slave FIFO + AUTOIN** on **EP6 IN** (512‑byte auto‑commit), **16‑bit bus**, **external IFCLK**.
> - Host: **asynchronous libusb** reader → **stdout** (acts like a FIFO you can pipe from).
> - Wiring: Minimal — data bus, IFCLK, **SLWR** (low for continuous writes), optional FLAGs.

## Why 512‑byte packets?
On **USB 2.0 high‑speed**, the **maximum packet size for bulk endpoints is 512 bytes**. Controllers/OS will split larger transfers into 512‑byte transactions automatically.  
References: Microsoft Learn (USB bulk) and Keil USB bulk docs. 

## FX2 specifics (firmware design)
We configure **IFCONFIG** for **external IFCLK**, **Slave FIFO (IFCFG=01)**, **16‑bit WORDWIDE**, **synchronous** mode, and use **EP6 IN** with **AUTOIN** so the hardware commits 512‑byte packets without 8051 intervention. See the **EZ‑USB FX2 Technical Reference Manual** for register details (IFCONFIG, EPxCFG, EPxAUTOINLEN, EPxFIFOCFG, REVCTL, etc.).  
- EZ‑USB FX2 TRM (Infineon, formerly Cypress): https://www.infineon.com/assets/row/public/documents/24/44/infineon-ez-usb-fx2-trm-version2-2-usermanual-en.pdf

The Cypress getting‑started/Bulkloop flow is a useful sanity check if you need to test USB pipe basics:  
- https://www.manualslib.com/manual/2875994/Cypress-Ez-Usb-Fx2lp.html

## Repository layout
```
fx2-ad9201-streamer/
├── firmware/
│   ├── include/
│   │   └── config.h
│   ├── src/
│   │   └── main.c
│   ├── udev/
│   │   └── 99-fx2.rules
│   └── Makefile
├── host/
│   ├── fx2_stream_stdout.c
│   └── Makefile
├── examples/
│   ├── pipeline.sh
│   └── grc-integration.md
├── tools/
│   └── gpif-notes.md
├── doc/
│   ├── wiring.md
│   └── rate-planning.md
└── LICENSE
```

## Build & Run
### Prereqs
- **Firmware:** SDCC + **fx2lib** headers (`fx2regs.h`, `fx2macros.h`, `syncdelay.h`). Set `FX2LIB` in `firmware/Makefile` to your install path.
- **Host:** libusb‑1.0 dev package (e.g., `sudo apt install libusb-1.0-0-dev`).

### Firmware
```bash
cd firmware
make
# produces build/streamer.ihx
# Load to RAM (choose your tool):
#   fxload  : sudo fxload -t fx2 -I build/streamer.ihx -D /dev/bus/usb/BBB/DDD
#   cycfx2prog: sudo cycfx2prog prg:build/streamer.ihx run
#   Cypress Control Center: Program RAM with .hex/.ihx
```

### Host reader
```bash
cd host
make
mkfifo /tmp/adc.pipe
./fx2_stream_stdout -v 0x04B4 -p 0x8613 -e 0x86 -i 0 -t 16384 -n 32 > /tmp/adc.pipe
```

### GNU Radio quick test
Use a **File Source** reading `/tmp/adc.pipe` with **item size = 2** (u16 or s16 depending on your interpretation; the upper 6 bits are zero). You can re‑interpret to float with a cast/scale block.

See `examples/grc-integration.md` for more options.

## Notes on rates & limits
- Each 512‑byte packet carries **256 samples** at 16‑bit padded.
- Typical sustained USB2 HS bulk throughput is **~40 MB/s** on a good host. Plan your IFCLK accordingly (or decimate in front of FX2).  

## Demo cheat sheet (PhaseLatch → Gqrx)

This is a minimal “copy/paste” workflow to get a live stream into **Gqrx** via the FIFO at `/tmp/iq.fifo`.

### 0) Build host tools
```bash
cd host
make
```

### 1) Create the FIFO (once)
```bash
mkfifo /tmp/iq.fifo
```

### 2) Start streaming to Gqrx (no calibration)
If your raw stream is interleaved unsigned 8‑bit IQ (u8 I,Q), convert to CF32 and write to the FIFO:
```bash
./fx2_stream_stdout -i 0 -t 16384 -n 32 \
	| ./iq_to_cf32 -m 8u \
	> /tmp/iq.fifo
```

### 3) Apply DC correction (run-once calibration, then hardcode)
Measure (run while input is silent):
```bash
./fx2_stream_stdout -i 0 -t 16384 -n 32 \
	| ./iq_dc_cal --samples 65536
```

Then stream with the measured values:
```bash
./fx2_stream_stdout -i 0 -t 16384 -n 32 \
	| ./iq_dc_apply --dcI 3 --dcQ 3 \
	| ./iq_to_cf32 -m 8u \
	> /tmp/iq.fifo
```

### 4) Apply IQ balance (tone calibration, then hardcode)
Tone calibration (example numbers):
```bash
./fx2_stream_stdout -i 0 -t 16384 -n 32 \
	| ./iq_to_cf32 -m 8u \
	| ./iq_iqbal_tone_cal_cf32 --tone-hz 2657000 --fs-hz 20000000 --samples 65536
```

Then stream with correction enabled:
```bash
./fx2_stream_stdout -i 0 -t 16384 -n 32 \
	| ./iq_dc_apply --dcI 3 --dcQ 3 \
	| ./iq_to_cf32 -m 8u \
	| ./iq_iqbal_apply_cf32 --kRe -0.0378 --kIm 0.4850 \
	> /tmp/iq.fifo
```

### Notes
- The writer will block unless **Gqrx is actively reading** `/tmp/iq.fifo`.
- If you want a single command wrapper, see `examples/pipeline.sh`.

## License
MIT (for this repository’s sources). 