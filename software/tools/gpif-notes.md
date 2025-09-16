# GPIF vs Slave FIFO notes

This project uses **Slave FIFO** with **external IFCLK** and a continuously asserted **SLWR=0** so the FX2 writes on every IFCLK edge. If you can’t generate `SLWR` externally, switch to **GPIF Master** and let the FX2 generate write strobes (use Cypress GPIF Designer to generate the waveform and register tables).

Refer to the **EZ‑USB FX2 TRM** for GPIF and Slave FIFO chapters:  
https://www.infineon.com/assets/row/public/documents/24/44/infineon-ez-usb-fx2-trm-version2-2-usermanual-en.pdf
