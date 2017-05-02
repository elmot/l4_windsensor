// Clock recovery system
 extern struct {
// control register
 struct {
      unsigned int SYNCOKIE: 1; // SYNC event OK interrupt               enable
      unsigned int SYNCWARNIE: 1; // SYNC warning interrupt               enable
      unsigned int ERRIE: 1; // Synchronization or trimming error               interrupt enable
      unsigned int ESYNCIE: 1; // Expected SYNC interrupt               enable
      unsigned int : 1; // Reserved
      unsigned int CEN: 1; // Frequency error counter               enable
      unsigned int AUTOTRIMEN: 1; // Automatic trimming enable
      unsigned int SWSYNC: 1; // Generate software SYNC               event
      unsigned int TRIM: 6; // HSI48 oscillator smooth               trimming
      unsigned int : 18; // Reserved
} CR;
// configuration register
 struct {
      unsigned int RELOAD: 16; // Counter reload value
      unsigned int FELIM: 8; // Frequency error limit
      unsigned int SYNCDIV: 3; // SYNC divider
      unsigned int : 1; // Reserved
      unsigned int SYNCSRC: 2; // SYNC signal source               selection
      unsigned int : 1; // Reserved
      unsigned int SYNCPOL: 1; // SYNC polarity selection
} CFGR;
// interrupt and status register
 struct {
      unsigned int SYNCOKF: 1; // SYNC event OK flag
      unsigned int SYNCWARNF: 1; // SYNC warning flag
      unsigned int ERRF: 1; // Error flag
      unsigned int ESYNCF: 1; // Expected SYNC flag
      unsigned int : 4; // Reserved
      unsigned int SYNCERR: 1; // SYNC error
      unsigned int SYNCMISS: 1; // SYNC missed
      unsigned int TRIMOVF: 1; // Trimming overflow or               underflow
      unsigned int : 4; // Reserved
      unsigned int FEDIR: 1; // Frequency error direction
      unsigned int FECAP: 16; // Frequency error capture
} ISR;
// interrupt flag clear register
 struct {
      unsigned int SYNCOKC: 1; // SYNC event OK clear flag
      unsigned int SYNCWARNC: 1; // SYNC warning clear flag
      unsigned int ERRC: 1; // Error clear flag
      unsigned int ESYNCC: 1; // Expected SYNC clear flag
      unsigned int : 28; // Reserved
} ICR;
} SVD_CRS;
asm(".equ SVD_CRS, 0x40006000");
