# Wiring (AD9201 → FX2 in Slave FIFO mode)

**Clocks**
- `IFCLK` (from your ADC sampling clock) → FX2 `IFCLK` pin (external clock). Use the rate you need.

**Data**
- FX2 `D[15:10]` = tie to `0` (or use for Q if you interleave differently)
- FX2 `D[9:0]`   = `AD9201[9:0]` (one channel). If using both I/Q channels at once, interleave externally and map into 16‑bit words.

**Control**
- `SLWR`   → **tie low** for continuous write on each IFCLK edge (simplest). Alternatively, drive from a CPLD/FPGA per sample.
- `PKTEND` → tie high (unused; AUTOIN commits every 512 B).
- `SLRD`/`SLOE` → tie high (unused; we don’t read from FX2).
- Optional `FLAGB/FLAGC` → monitor FIFO status if you implement flow control.

> Ensure setup/hold relative to IFCLK meets FX2 timing (TRM timing tables). If running close to USB limits, consider an FPGA shim to safely time‑align and optionally decimate.
