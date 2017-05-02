// Serial audio interface
 extern struct {
      unsigned int : 32; // Reserved
// AConfiguration register 1
 struct {
      unsigned int MODE: 2; // Audio block mode
      unsigned int PRTCFG: 2; // Protocol configuration
      unsigned int : 1; // Reserved
      unsigned int DS: 3; // Data size
      unsigned int LSBFIRST: 1; // Least significant bit               first
      unsigned int CKSTR: 1; // Clock strobing edge
      unsigned int SYNCEN: 2; // Synchronization enable
      unsigned int MONO: 1; // Mono mode
      unsigned int OutDri: 1; // Output drive
      unsigned int : 2; // Reserved
      unsigned int SAIAEN: 1; // Audio block A enable
      unsigned int DMAEN: 1; // DMA enable
      unsigned int : 1; // Reserved
      unsigned int NODIV: 1; // No divider
      unsigned int MCJDIV: 4; // Master clock divider
      unsigned int : 8; // Reserved
} ACR1;
// AConfiguration register 2
 struct {
      unsigned int FTH: 3; // FIFO threshold
      unsigned int FFLUS: 1; // FIFO flush
      unsigned int TRIS: 1; // Tristate management on data               line
      unsigned int MUTE: 1; // Mute
      unsigned int MUTEVAL: 1; // Mute value
      unsigned int MUTECN: 6; // Mute counter
      unsigned int CPL: 1; // Complement bit
      unsigned int COMP: 2; // Companding mode
      unsigned int : 16; // Reserved
} ACR2;
// AFRCR
 struct {
      unsigned int FRL: 8; // Frame length
      unsigned int FSALL: 7; // Frame synchronization active level               length
      unsigned int : 1; // Reserved
      unsigned int FSDEF: 1; // Frame synchronization               definition
      unsigned int FSPOL: 1; // Frame synchronization               polarity
      unsigned int FSOFF: 1; // Frame synchronization               offset
      unsigned int : 13; // Reserved
} AFRCR;
// ASlot register
 struct {
      unsigned int FBOFF: 5; // First bit offset
      unsigned int : 1; // Reserved
      unsigned int SLOTSZ: 2; // Slot size
      unsigned int NBSLOT: 4; // Number of slots in an audio               frame
      unsigned int : 4; // Reserved
      unsigned int SLOTEN: 16; // Slot enable
} ASLOTR;
// AInterrupt mask register2
 struct {
      unsigned int OVRUDRIE: 1; // Overrun/underrun interrupt               enable
      unsigned int MUTEDET: 1; // Mute detection interrupt               enable
      unsigned int WCKCFG: 1; // Wrong clock configuration interrupt               enable
      unsigned int FREQIE: 1; // FIFO request interrupt               enable
      unsigned int CNRDYIE: 1; // Codec not ready interrupt               enable
      unsigned int AFSDETIE: 1; // Anticipated frame synchronization               detection interrupt enable
      unsigned int LFSDET: 1; // Late frame synchronization detection               interrupt enable
      unsigned int : 25; // Reserved
} AIM;
// AStatus register
 struct {
      unsigned int OVRUDR: 1; // Overrun / underrun
      unsigned int MUTEDET: 1; // Mute detection
      unsigned int WCKCFG: 1; // Wrong clock configuration flag. This bit               is read only
      unsigned int FREQ: 1; // FIFO request
      unsigned int CNRDY: 1; // Codec not ready
      unsigned int AFSDET: 1; // Anticipated frame synchronization               detection
      unsigned int LFSDET: 1; // Late frame synchronization               detection
      unsigned int : 9; // Reserved
      unsigned int FLVL: 3; // FIFO level threshold
      unsigned int : 13; // Reserved
} ASR;
// AClear flag register
 struct {
      unsigned int OVRUDR: 1; // Clear overrun / underrun
      unsigned int MUTEDET: 1; // Mute detection flag
      unsigned int WCKCFG: 1; // Clear wrong clock configuration               flag
      unsigned int : 1; // Reserved
      unsigned int CNRDY: 1; // Clear codec not ready flag
      unsigned int CAFSDET: 1; // Clear anticipated frame synchronization               detection flag
      unsigned int LFSDET: 1; // Clear late frame synchronization               detection flag
      unsigned int : 25; // Reserved
} ACLRFR;
// AData register
 struct {
      unsigned int DATA: 32; // Data
} ADR;
// BConfiguration register 1
 struct {
      unsigned int MODE: 2; // Audio block mode
      unsigned int PRTCFG: 2; // Protocol configuration
      unsigned int : 1; // Reserved
      unsigned int DS: 3; // Data size
      unsigned int LSBFIRST: 1; // Least significant bit               first
      unsigned int CKSTR: 1; // Clock strobing edge
      unsigned int SYNCEN: 2; // Synchronization enable
      unsigned int MONO: 1; // Mono mode
      unsigned int OutDri: 1; // Output drive
      unsigned int : 2; // Reserved
      unsigned int SAIBEN: 1; // Audio block B enable
      unsigned int DMAEN: 1; // DMA enable
      unsigned int : 1; // Reserved
      unsigned int NODIV: 1; // No divider
      unsigned int MCJDIV: 4; // Master clock divider
      unsigned int : 8; // Reserved
} BCR1;
// BConfiguration register 2
 struct {
      unsigned int FTH: 3; // FIFO threshold
      unsigned int FFLUS: 1; // FIFO flush
      unsigned int TRIS: 1; // Tristate management on data               line
      unsigned int MUTE: 1; // Mute
      unsigned int MUTEVAL: 1; // Mute value
      unsigned int MUTECN: 6; // Mute counter
      unsigned int CPL: 1; // Complement bit
      unsigned int COMP: 2; // Companding mode
      unsigned int : 16; // Reserved
} BCR2;
// BFRCR
 struct {
      unsigned int FRL: 8; // Frame length
      unsigned int FSALL: 7; // Frame synchronization active level               length
      unsigned int : 1; // Reserved
      unsigned int FSDEF: 1; // Frame synchronization               definition
      unsigned int FSPOL: 1; // Frame synchronization               polarity
      unsigned int FSOFF: 1; // Frame synchronization               offset
      unsigned int : 13; // Reserved
} BFRCR;
// BSlot register
 struct {
      unsigned int FBOFF: 5; // First bit offset
      unsigned int : 1; // Reserved
      unsigned int SLOTSZ: 2; // Slot size
      unsigned int NBSLOT: 4; // Number of slots in an audio               frame
      unsigned int : 4; // Reserved
      unsigned int SLOTEN: 16; // Slot enable
} BSLOTR;
// BInterrupt mask register2
 struct {
      unsigned int OVRUDRIE: 1; // Overrun/underrun interrupt               enable
      unsigned int MUTEDET: 1; // Mute detection interrupt               enable
      unsigned int WCKCFG: 1; // Wrong clock configuration interrupt               enable
      unsigned int FREQIE: 1; // FIFO request interrupt               enable
      unsigned int CNRDYIE: 1; // Codec not ready interrupt               enable
      unsigned int AFSDETIE: 1; // Anticipated frame synchronization               detection interrupt enable
      unsigned int LFSDETIE: 1; // Late frame synchronization detection               interrupt enable
      unsigned int : 25; // Reserved
} BIM;
// BStatus register
 struct {
      unsigned int OVRUDR: 1; // Overrun / underrun
      unsigned int MUTEDET: 1; // Mute detection
      unsigned int WCKCFG: 1; // Wrong clock configuration               flag
      unsigned int FREQ: 1; // FIFO request
      unsigned int CNRDY: 1; // Codec not ready
      unsigned int AFSDET: 1; // Anticipated frame synchronization               detection
      unsigned int LFSDET: 1; // Late frame synchronization               detection
      unsigned int : 9; // Reserved
      unsigned int FLVL: 3; // FIFO level threshold
      unsigned int : 13; // Reserved
} BSR;
// BClear flag register
 struct {
      unsigned int OVRUDR: 1; // Clear overrun / underrun
      unsigned int MUTEDET: 1; // Mute detection flag
      unsigned int WCKCFG: 1; // Clear wrong clock configuration               flag
      unsigned int : 1; // Reserved
      unsigned int CNRDY: 1; // Clear codec not ready flag
      unsigned int CAFSDET: 1; // Clear anticipated frame synchronization               detection flag
      unsigned int LFSDET: 1; // Clear late frame synchronization               detection flag
      unsigned int : 25; // Reserved
} BCLRFR;
// BData register
 struct {
      unsigned int DATA: 32; // Data
} BDR;
} SVD_SAI1;
asm(".equ SVD_SAI1, 0x40015400");
