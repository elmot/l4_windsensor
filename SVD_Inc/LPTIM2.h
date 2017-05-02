// Low power timer
 extern struct {
// Interrupt and Status Register
 struct {
      unsigned int CMPM: 1; // Compare match
      unsigned int ARRM: 1; // Autoreload match
      unsigned int EXTTRIG: 1; // External trigger edge               event
      unsigned int CMPOK: 1; // Compare register update OK
      unsigned int ARROK: 1; // Autoreload register update               OK
      unsigned int UP: 1; // Counter direction change down to               up
      unsigned int DOWN: 1; // Counter direction change up to               down
      unsigned int : 25; // Reserved
} ISR;
// Interrupt Clear Register
 struct {
      unsigned int CMPMCF: 1; // compare match Clear Flag
      unsigned int ARRMCF: 1; // Autoreload match Clear               Flag
      unsigned int EXTTRIGCF: 1; // External trigger valid edge Clear               Flag
      unsigned int CMPOKCF: 1; // Compare register update OK Clear               Flag
      unsigned int ARROKCF: 1; // Autoreload register update OK Clear               Flag
      unsigned int UPCF: 1; // Direction change to UP Clear               Flag
      unsigned int DOWNCF: 1; // Direction change to down Clear               Flag
      unsigned int : 25; // Reserved
} ICR;
// Interrupt Enable Register
 struct {
      unsigned int CMPMIE: 1; // Compare match Interrupt               Enable
      unsigned int ARRMIE: 1; // Autoreload match Interrupt               Enable
      unsigned int EXTTRIGIE: 1; // External trigger valid edge Interrupt               Enable
      unsigned int CMPOKIE: 1; // Compare register update OK Interrupt               Enable
      unsigned int ARROKIE: 1; // Autoreload register update OK Interrupt               Enable
      unsigned int UPIE: 1; // Direction change to UP Interrupt               Enable
      unsigned int DOWNIE: 1; // Direction change to down Interrupt               Enable
      unsigned int : 25; // Reserved
} IER;
// Configuration Register
 struct {
      unsigned int CKSEL: 1; // Clock selector
      unsigned int CKPOL: 2; // Clock Polarity
      unsigned int CKFLT: 2; // Configurable digital filter for external               clock
      unsigned int : 1; // Reserved
      unsigned int TRGFLT: 2; // Configurable digital filter for               trigger
      unsigned int : 1; // Reserved
      unsigned int PRESC: 3; // Clock prescaler
      unsigned int : 1; // Reserved
      unsigned int TRIGSEL: 3; // Trigger selector
      unsigned int : 1; // Reserved
      unsigned int TRIGEN: 2; // Trigger enable and               polarity
      unsigned int TIMOUT: 1; // Timeout enable
      unsigned int WAVE: 1; // Waveform shape
      unsigned int WAVPOL: 1; // Waveform shape polarity
      unsigned int PRELOAD: 1; // Registers update mode
      unsigned int COUNTMODE: 1; // counter mode enabled
      unsigned int ENC: 1; // Encoder mode enable
      unsigned int : 7; // Reserved
} CFGR;
// Control Register
 struct {
      unsigned int ENABLE: 1; // LPTIM Enable
      unsigned int SNGSTRT: 1; // LPTIM start in single mode
      unsigned int CNTSTRT: 1; // Timer start in continuous               mode
      unsigned int : 29; // Reserved
} CR;
// Compare Register
 struct {
      unsigned int CMP: 16; // Compare value
      unsigned int : 16; // Reserved
} CMP;
// Autoreload Register
 struct {
      unsigned int ARR: 16; // Auto reload value
      unsigned int : 16; // Reserved
} ARR;
// Counter Register
 struct {
      unsigned int CNT: 16; // Counter value
      unsigned int : 16; // Reserved
} CNT;
} SVD_LPTIM2;
asm(".equ SVD_LPTIM2, 0x40009400");
