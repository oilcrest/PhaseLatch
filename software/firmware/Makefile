# Firmware Makefile (SDCC + fx2lib)
# Set FX2LIB to your fx2lib install path (contains include/fx2regs.h etc.)
FX2LIB ?= /Users/abn/install/max2771_fx2lp/FX2LP/fx2lib
SDCC    ?= sdcc

PROJ = streamer
SRC  = src/main.c src/descriptors.c
INC  = -I$(FX2LIB)/include -Iinclude -Isrc
CFLAGS = -mmcs51 --std-sdcc11 --opt-code-size

BUILD = build
OBJ   = $(BUILD)/main.rel

all: $(BUILD)/$(PROJ).ihx

$(BUILD):
	mkdir -p $(BUILD)

$(BUILD)/main.rel: $(SRC) | $(BUILD)
	$(SDCC) $(CFLAGS) $(INC) -c $< -o $@

$(BUILD)/$(PROJ).ihx: $(OBJ)
	$(SDCC) $(CFLAGS) $(INC) $^ -o $@

flash: $(BUILD)/$(PROJ).ihx
	cycfx2prog prg:$< run

clean:
	rm -rf $(BUILD)

.PHONY: all clean flash
