// Liquid crystal display controller
 extern struct {
// control register
 struct {
      unsigned int LCDEN: 1; // LCD controller enable
      unsigned int VSEL: 1; // Voltage source selection
      unsigned int DUTY: 3; // Duty selection
      unsigned int BIAS: 2; // Bias selector
      unsigned int MUX_SEG: 1; // Mux segment enable
      unsigned int BUFEN: 1; // Voltage output buffer               enable
      unsigned int : 23; // Reserved
} CR;
// frame control register
 struct {
      unsigned int HD: 1; // High drive enable
      unsigned int SOFIE: 1; // Start of frame interrupt               enable
      unsigned int : 1; // Reserved
      unsigned int UDDIE: 1; // Update display done interrupt               enable
      unsigned int PON: 3; // Pulse ON duration
      unsigned int DEAD: 3; // Dead time duration
      unsigned int CC: 3; // Contrast control
      unsigned int BLINKF: 3; // Blink frequency selection
      unsigned int BLINK: 2; // Blink mode selection
      unsigned int DIV: 4; // DIV clock divider
      unsigned int PS: 4; // PS 16-bit prescaler
      unsigned int : 6; // Reserved
} FCR;
// status register
 struct {
      unsigned int ENS: 1; // ENS
      unsigned int SOF: 1; // Start of frame flag
      unsigned int UDR: 1; // Update display request
      unsigned int UDD: 1; // Update Display Done
      unsigned int RDY: 1; // Ready flag
      unsigned int FCRSF: 1; // LCD Frame Control Register               Synchronization flag
      unsigned int : 26; // Reserved
} SR;
// clear register
 struct {
      unsigned int : 1; // Reserved
      unsigned int SOFC: 1; // Start of frame flag clear
      unsigned int : 1; // Reserved
      unsigned int UDDC: 1; // Update display done clear
      unsigned int : 28; // Reserved
} CLR;
      unsigned int : 32; // Reserved
// display memory
 struct {
      unsigned int S00: 1; // S00
      unsigned int S01: 1; // S01
      unsigned int S02: 1; // S02
      unsigned int S03: 1; // S03
      unsigned int S04: 1; // S04
      unsigned int S05: 1; // S05
      unsigned int S06: 1; // S06
      unsigned int S07: 1; // S07
      unsigned int S08: 1; // S08
      unsigned int S09: 1; // S09
      unsigned int S10: 1; // S10
      unsigned int S11: 1; // S11
      unsigned int S12: 1; // S12
      unsigned int S13: 1; // S13
      unsigned int S14: 1; // S14
      unsigned int S15: 1; // S15
      unsigned int S16: 1; // S16
      unsigned int S17: 1; // S17
      unsigned int S18: 1; // S18
      unsigned int S19: 1; // S19
      unsigned int S20: 1; // S20
      unsigned int S21: 1; // S21
      unsigned int S22: 1; // S22
      unsigned int S23: 1; // S23
      unsigned int S24: 1; // S24
      unsigned int S25: 1; // S25
      unsigned int S26: 1; // S26
      unsigned int S27: 1; // S27
      unsigned int S28: 1; // S28
      unsigned int S29: 1; // S29
      unsigned int S30: 1; // S30
      unsigned int : 1; // Reserved
} RAM_COM0;
      unsigned int : 32; // Reserved
// display memory
 struct {
      unsigned int S00: 1; // S00
      unsigned int S01: 1; // S01
      unsigned int S02: 1; // S02
      unsigned int S03: 1; // S03
      unsigned int S04: 1; // S04
      unsigned int S05: 1; // S05
      unsigned int S06: 1; // S06
      unsigned int S07: 1; // S07
      unsigned int S08: 1; // S08
      unsigned int S09: 1; // S09
      unsigned int S10: 1; // S10
      unsigned int S11: 1; // S11
      unsigned int S12: 1; // S12
      unsigned int S13: 1; // S13
      unsigned int S14: 1; // S14
      unsigned int S15: 1; // S15
      unsigned int S16: 1; // S16
      unsigned int S17: 1; // S17
      unsigned int S18: 1; // S18
      unsigned int S19: 1; // S19
      unsigned int S20: 1; // S20
      unsigned int S21: 1; // S21
      unsigned int S22: 1; // S22
      unsigned int S23: 1; // S23
      unsigned int S24: 1; // S24
      unsigned int S25: 1; // S25
      unsigned int S26: 1; // S26
      unsigned int S27: 1; // S27
      unsigned int S28: 1; // S28
      unsigned int S29: 1; // S29
      unsigned int S30: 1; // S30
      unsigned int S31: 1; // S31
} RAM_COM1;
      unsigned int : 32; // Reserved
// display memory
 struct {
      unsigned int S00: 1; // S00
      unsigned int S01: 1; // S01
      unsigned int S02: 1; // S02
      unsigned int S03: 1; // S03
      unsigned int S04: 1; // S04
      unsigned int S05: 1; // S05
      unsigned int S06: 1; // S06
      unsigned int S07: 1; // S07
      unsigned int S08: 1; // S08
      unsigned int S09: 1; // S09
      unsigned int S10: 1; // S10
      unsigned int S11: 1; // S11
      unsigned int S12: 1; // S12
      unsigned int S13: 1; // S13
      unsigned int S14: 1; // S14
      unsigned int S15: 1; // S15
      unsigned int S16: 1; // S16
      unsigned int S17: 1; // S17
      unsigned int S18: 1; // S18
      unsigned int S19: 1; // S19
      unsigned int S20: 1; // S20
      unsigned int S21: 1; // S21
      unsigned int S22: 1; // S22
      unsigned int S23: 1; // S23
      unsigned int S24: 1; // S24
      unsigned int S25: 1; // S25
      unsigned int S26: 1; // S26
      unsigned int S27: 1; // S27
      unsigned int S28: 1; // S28
      unsigned int S29: 1; // S29
      unsigned int S30: 1; // S30
      unsigned int S31: 1; // S31
} RAM_COM2;
      unsigned int : 32; // Reserved
// display memory
 struct {
      unsigned int S00: 1; // S00
      unsigned int S01: 1; // S01
      unsigned int S02: 1; // S02
      unsigned int S03: 1; // S03
      unsigned int S04: 1; // S04
      unsigned int S05: 1; // S05
      unsigned int S06: 1; // S06
      unsigned int S07: 1; // S07
      unsigned int S08: 1; // S08
      unsigned int S09: 1; // S09
      unsigned int S10: 1; // S10
      unsigned int S11: 1; // S11
      unsigned int S12: 1; // S12
      unsigned int S13: 1; // S13
      unsigned int S14: 1; // S14
      unsigned int S15: 1; // S15
      unsigned int S16: 1; // S16
      unsigned int S17: 1; // S17
      unsigned int S18: 1; // S18
      unsigned int S19: 1; // S19
      unsigned int S20: 1; // S20
      unsigned int S21: 1; // S21
      unsigned int S22: 1; // S22
      unsigned int S23: 1; // S23
      unsigned int S24: 1; // S24
      unsigned int S25: 1; // S25
      unsigned int S26: 1; // S26
      unsigned int S27: 1; // S27
      unsigned int S28: 1; // S28
      unsigned int S29: 1; // S29
      unsigned int S30: 1; // S30
      unsigned int S31: 1; // S31
} RAM_COM3;
      unsigned int : 32; // Reserved
// display memory
 struct {
      unsigned int S00: 1; // S00
      unsigned int S01: 1; // S01
      unsigned int S02: 1; // S02
      unsigned int S03: 1; // S03
      unsigned int S04: 1; // S04
      unsigned int S05: 1; // S05
      unsigned int S06: 1; // S06
      unsigned int S07: 1; // S07
      unsigned int S08: 1; // S08
      unsigned int S09: 1; // S09
      unsigned int S10: 1; // S10
      unsigned int S11: 1; // S11
      unsigned int S12: 1; // S12
      unsigned int S13: 1; // S13
      unsigned int S14: 1; // S14
      unsigned int S15: 1; // S15
      unsigned int S16: 1; // S16
      unsigned int S17: 1; // S17
      unsigned int S18: 1; // S18
      unsigned int S19: 1; // S19
      unsigned int S20: 1; // S20
      unsigned int S21: 1; // S21
      unsigned int S22: 1; // S22
      unsigned int S23: 1; // S23
      unsigned int S24: 1; // S24
      unsigned int S25: 1; // S25
      unsigned int S26: 1; // S26
      unsigned int S27: 1; // S27
      unsigned int S28: 1; // S28
      unsigned int S29: 1; // S29
      unsigned int S30: 1; // S30
      unsigned int S31: 1; // S31
} RAM_COM4;
      unsigned int : 32; // Reserved
// display memory
 struct {
      unsigned int S00: 1; // S00
      unsigned int S01: 1; // S01
      unsigned int S02: 1; // S02
      unsigned int S03: 1; // S03
      unsigned int S04: 1; // S04
      unsigned int S05: 1; // S05
      unsigned int S06: 1; // S06
      unsigned int S07: 1; // S07
      unsigned int S08: 1; // S08
      unsigned int S09: 1; // S09
      unsigned int S10: 1; // S10
      unsigned int S11: 1; // S11
      unsigned int S12: 1; // S12
      unsigned int S13: 1; // S13
      unsigned int S14: 1; // S14
      unsigned int S15: 1; // S15
      unsigned int S16: 1; // S16
      unsigned int S17: 1; // S17
      unsigned int S18: 1; // S18
      unsigned int S19: 1; // S19
      unsigned int S20: 1; // S20
      unsigned int S21: 1; // S21
      unsigned int S22: 1; // S22
      unsigned int S23: 1; // S23
      unsigned int S24: 1; // S24
      unsigned int S25: 1; // S25
      unsigned int S26: 1; // S26
      unsigned int S27: 1; // S27
      unsigned int S28: 1; // S28
      unsigned int S29: 1; // S29
      unsigned int S30: 1; // S30
      unsigned int S31: 1; // S31
} RAM_COM5;
      unsigned int : 32; // Reserved
// display memory
 struct {
      unsigned int S00: 1; // S00
      unsigned int S01: 1; // S01
      unsigned int S02: 1; // S02
      unsigned int S03: 1; // S03
      unsigned int S04: 1; // S04
      unsigned int S05: 1; // S05
      unsigned int S06: 1; // S06
      unsigned int S07: 1; // S07
      unsigned int S08: 1; // S08
      unsigned int S09: 1; // S09
      unsigned int S10: 1; // S10
      unsigned int S11: 1; // S11
      unsigned int S12: 1; // S12
      unsigned int S13: 1; // S13
      unsigned int S14: 1; // S14
      unsigned int S15: 1; // S15
      unsigned int S16: 1; // S16
      unsigned int S17: 1; // S17
      unsigned int S18: 1; // S18
      unsigned int S19: 1; // S19
      unsigned int S20: 1; // S20
      unsigned int S21: 1; // S21
      unsigned int S22: 1; // S22
      unsigned int S23: 1; // S23
      unsigned int S24: 1; // S24
      unsigned int S25: 1; // S25
      unsigned int S26: 1; // S26
      unsigned int S27: 1; // S27
      unsigned int S28: 1; // S28
      unsigned int S29: 1; // S29
      unsigned int S30: 1; // S30
      unsigned int S31: 1; // S31
} RAM_COM6;
      unsigned int : 32; // Reserved
// display memory
 struct {
      unsigned int S00: 1; // S00
      unsigned int S01: 1; // S01
      unsigned int S02: 1; // S02
      unsigned int S03: 1; // S03
      unsigned int S04: 1; // S04
      unsigned int S05: 1; // S05
      unsigned int S06: 1; // S06
      unsigned int S07: 1; // S07
      unsigned int S08: 1; // S08
      unsigned int S09: 1; // S09
      unsigned int S10: 1; // S10
      unsigned int S11: 1; // S11
      unsigned int S12: 1; // S12
      unsigned int S13: 1; // S13
      unsigned int S14: 1; // S14
      unsigned int S15: 1; // S15
      unsigned int S16: 1; // S16
      unsigned int S17: 1; // S17
      unsigned int S18: 1; // S18
      unsigned int S19: 1; // S19
      unsigned int S20: 1; // S20
      unsigned int S21: 1; // S21
      unsigned int S22: 1; // S22
      unsigned int S23: 1; // S23
      unsigned int S24: 1; // S24
      unsigned int S25: 1; // S25
      unsigned int S26: 1; // S26
      unsigned int S27: 1; // S27
      unsigned int S28: 1; // S28
      unsigned int S29: 1; // S29
      unsigned int S30: 1; // S30
      unsigned int S31: 1; // S31
} RAM_COM7;
} SVD_LCD;
asm(".equ SVD_LCD, 0x40002400");
