// QuadSPI interface
 extern struct {
// control register
 struct {
      unsigned int EN: 1; // Enable
      unsigned int ABORT: 1; // Abort request
      unsigned int DMAEN: 1; // DMA enable
      unsigned int TCEN: 1; // Timeout counter enable
      unsigned int SSHIFT: 1; // Sample shift
      unsigned int : 1; // Reserved
      unsigned int DFM: 1; // Dual-flash mode
      unsigned int FSEL: 1; // FLASH memory selection
      unsigned int FTHRES: 5; // IFO threshold level
      unsigned int : 3; // Reserved
      unsigned int TEIE: 1; // Transfer error interrupt enable
      unsigned int TCIE: 1; // Transfer complete interrupt enable
      unsigned int FTIE: 1; // FIFO threshold interrupt enable
      unsigned int SMIE: 1; // Status match interrupt enable
      unsigned int TOIE: 1; // TimeOut interrupt enable
      unsigned int : 1; // Reserved
      unsigned int APMS: 1; // Automatic poll mode stop
      unsigned int PMM: 1; // Polling match mode
      unsigned int PRESCALER: 8; // Clock prescaler
} CR;
// device configuration register
 struct {
      unsigned int CKMODE: 1; // Mode 0 / mode 3
      unsigned int : 7; // Reserved
      unsigned int CSHT: 3; // Chip select high time
      unsigned int : 5; // Reserved
      unsigned int FSIZE: 5; // FLASH memory size
      unsigned int : 11; // Reserved
} DCR;
// status register
 struct {
      unsigned int TEF: 1; // Transfer error flag
      unsigned int TCF: 1; // Transfer complete flag
      unsigned int FTF: 1; // FIFO threshold flag
      unsigned int SMF: 1; // Status match flag
      unsigned int TOF: 1; // Timeout flag
      unsigned int BUSY: 1; // Busy
      unsigned int : 2; // Reserved
      unsigned int FLEVEL: 7; // FIFO level
      unsigned int : 17; // Reserved
} SR;
// flag clear register
 struct {
      unsigned int CTEF: 1; // Clear transfer error flag
      unsigned int CTCF: 1; // Clear transfer complete flag
      unsigned int : 1; // Reserved
      unsigned int CSMF: 1; // Clear status match flag
      unsigned int CTOF: 1; // Clear timeout flag
      unsigned int : 27; // Reserved
} FCR;
// data length register
 struct {
      unsigned int DL: 32; // Data length
} DLR;
// communication configuration register
 struct {
      unsigned int INSTRUCTION: 8; // Instruction
      unsigned int IMODE: 2; // Instruction mode
      unsigned int ADMODE: 2; // Address mode
      unsigned int ADSIZE: 2; // Address size
      unsigned int ABMODE: 2; // Alternate bytes mode
      unsigned int ABSIZE: 2; // Alternate bytes size
      unsigned int DCYC: 5; // Number of dummy cycles
      unsigned int : 1; // Reserved
      unsigned int DMODE: 2; // Data mode
      unsigned int FMODE: 2; // Functional mode
      unsigned int SIOO: 1; // Send instruction only once mode
      unsigned int : 1; // Reserved
      unsigned int DHHC: 1; // DDR hold half cycle
      unsigned int DDRM: 1; // Double data rate mode
} CCR;
// address register
 struct {
      unsigned int ADDRESS: 32; // Address
} AR;
// ABR
 struct {
      unsigned int ALTERNATE: 32; // ALTERNATE
} ABR;
// data register
 struct {
      unsigned int DATA: 32; // Data
} DR;
// polling status mask register
 struct {
      unsigned int MASK: 32; // Status mask
} PSMKR;
// polling status match register
 struct {
      unsigned int MATCH: 32; // Status match
} PSMAR;
// polling interval register
 struct {
      unsigned int INTERVAL: 16; // Polling interval
      unsigned int : 16; // Reserved
} PIR;
// low-power timeout register
 struct {
      unsigned int TIMEOUT: 16; // Timeout period
      unsigned int : 16; // Reserved
} LPTR;
} SVD_QUADSPI;
asm(".equ SVD_QUADSPI, 0xa0001000");
