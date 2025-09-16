#!/usr/bin/env bash
set -euo pipefail
if [[ ! -p /tmp/adc.pipe ]]; then
    mkfifo /tmp/adc.pipe
fi
# Change VID/PID/EP/interface as needed
#../host/fx2_stream_stdout -v 0x04B4 -p 0x8613 -e 0x86 -i 0 -t 16384 -n 32 > /tmp/adc.pipe
../host/fx2_stream_stdout -v 0x04B4 -p 0x8613 -e 0x86 -i 0 -t 16384 -n 32 | pv > /dev/null