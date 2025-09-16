# GNU Radio Integration

**Option A: File Source**
1. `mkfifo /tmp/adc.pipe`
2. Run the host reader to fill it.
3. In GRC, add a **File Source**:
   - File: `/tmp/adc.pipe`
   - Repeat: `No`
   - **Item size**: 2 (unsigned/signed short)
4. Convert to float (`UShort to Float` or `Short to Float`) and scale (e.g., `/ 1023.0`).
5. View with a `QT GUI Sink`.

**Option B: TCP bridge**
If you prefer sockets, wrap the host reader stdout with `socat`:
```bash
mkfifo /tmp/adc.pipe
../host/fx2_stream_stdout > /tmp/adc.pipe &
socat -u FILE:/tmp/adc.pipe,ignoreeof TCP-LISTEN:9001,reuseaddr
```
Then use a **TCP Source** in GRC.
