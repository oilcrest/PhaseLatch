# Rate planning

- **Packetization:** 512 B/packet ⇒ 256 samples/packet at 16‑bit.
- **Throughput:** High‑speed bulk typically sustains ~40 MB/s on a good host/controller; exact numbers vary.
- **Budget:** If you stream both AD9201 channels interleaved at N MSPS each, data rate ≈ `2 * N * 2 B = 4N MB/s`.
  - Example: 4 MSPS/ch ⇒ ~16 MB/s — OK.
  - Example: 10 MSPS/ch ⇒ ~40 MB/s — near practical limit; consider decimation.
