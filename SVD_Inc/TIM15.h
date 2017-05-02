// General purpose timers
 extern struct {
// control register 1
 struct {
      unsigned int CEN: 1; // Counter enable
      unsigned int UDIS: 1; // Update disable
      unsigned int URS: 1; // Update request source
      unsigned int OPM: 1; // One-pulse mode
      unsigned int : 3; // Reserved
      unsigned int ARPE: 1; // Auto-reload preload enable
      unsigned int CKD: 2; // Clock division
      unsigned int : 1; // Reserved
      unsigned int UIFREMAP: 1; // UIF status bit remapping
      unsigned int : 20; // Reserved
} CR1;
// control register 2
 struct {
      unsigned int CCPC: 1; // Capture/compare preloaded               control
      unsigned int : 1; // Reserved
      unsigned int CCUS: 1; // Capture/compare control update               selection
      unsigned int CCDS: 1; // Capture/compare DMA               selection
      unsigned int : 4; // Reserved
      unsigned int OIS1: 1; // Output Idle state 1
      unsigned int OIS1N: 1; // Output Idle state 1
      unsigned int : 22; // Reserved
} CR2;
      unsigned int : 32; // Reserved
// DMA/Interrupt enable register
 struct {
      unsigned int UIE: 1; // Update interrupt enable
      unsigned int CC1IE: 1; // Capture/Compare 1 interrupt               enable
      unsigned int : 3; // Reserved
      unsigned int COMIE: 1; // COM interrupt enable
      unsigned int TIE: 1; // Trigger interrupt enable
      unsigned int BIE: 1; // Break interrupt enable
      unsigned int UDE: 1; // Update DMA request enable
      unsigned int CC1DE: 1; // Capture/Compare 1 DMA request               enable
      unsigned int : 3; // Reserved
      unsigned int COMDE: 1; // COM DMA request enable
      unsigned int TDE: 1; // Trigger DMA request enable
      unsigned int : 17; // Reserved
} DIER;
// status register
 struct {
      unsigned int UIF: 1; // Update interrupt flag
      unsigned int CC1IF: 1; // Capture/compare 1 interrupt               flag
      unsigned int : 3; // Reserved
      unsigned int COMIF: 1; // COM interrupt flag
      unsigned int TIF: 1; // Trigger interrupt flag
      unsigned int BIF: 1; // Break interrupt flag
      unsigned int : 1; // Reserved
      unsigned int CC1OF: 1; // Capture/Compare 1 overcapture               flag
      unsigned int : 22; // Reserved
} SR;
// event generation register
 struct {
      unsigned int UG: 1; // Update generation
      unsigned int CC1G: 1; // Capture/compare 1               generation
      unsigned int : 3; // Reserved
      unsigned int COMG: 1; // Capture/Compare control update               generation
      unsigned int TG: 1; // Trigger generation
      unsigned int BG: 1; // Break generation
      unsigned int : 24; // Reserved
} EGR;
  union {
// capture/compare mode register (output           mode)
 struct {
      unsigned int CC1S: 2; // Capture/Compare 1               selection
      unsigned int OC1FE: 1; // Output Compare 1 fast               enable
      unsigned int OC1PE: 1; // Output Compare 1 preload               enable
      unsigned int OC1M: 3; // Output Compare 1 mode
      unsigned int : 9; // Reserved
      unsigned int OC1M_2: 1; // Output Compare 1 mode
      unsigned int : 15; // Reserved
} CCMR1_Output;
// capture/compare mode register 1 (input           mode)
 struct {
      unsigned int CC1S: 2; // Capture/Compare 1               selection
      unsigned int IC1PSC: 2; // Input capture 1 prescaler
      unsigned int IC1F: 4; // Input capture 1 filter
      unsigned int : 24; // Reserved
} CCMR1_Input;
  } CCMR1_Output_CCMR1_Input;
      unsigned int : 32; // Reserved
// capture/compare enable           register
 struct {
      unsigned int CC1E: 1; // Capture/Compare 1 output               enable
      unsigned int CC1P: 1; // Capture/Compare 1 output               Polarity
      unsigned int CC1NE: 1; // Capture/Compare 1 complementary output               enable
      unsigned int CC1NP: 1; // Capture/Compare 1 output               Polarity
      unsigned int : 28; // Reserved
} CCER;
// counter
 struct {
      unsigned int CNT: 16; // counter value
      unsigned int : 15; // Reserved
      unsigned int UIFCPY: 1; // UIF Copy
} CNT;
// prescaler
 struct {
      unsigned int PSC: 16; // Prescaler value
      unsigned int : 16; // Reserved
} PSC;
// auto-reload register
 struct {
      unsigned int ARR: 16; // Auto-reload value
      unsigned int : 16; // Reserved
} ARR;
// repetition counter register
 struct {
      unsigned int REP: 8; // Repetition counter value
      unsigned int : 24; // Reserved
} RCR;
// capture/compare register 1
 struct {
      unsigned int CCR1: 16; // Capture/Compare 1 value
      unsigned int : 16; // Reserved
} CCR1;
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
// break and dead-time register
 struct {
      unsigned int DTG: 8; // Dead-time generator setup
      unsigned int LOCK: 2; // Lock configuration
      unsigned int OSSI: 1; // Off-state selection for Idle               mode
      unsigned int OSSR: 1; // Off-state selection for Run               mode
      unsigned int BKE: 1; // Break enable
      unsigned int BKP: 1; // Break polarity
      unsigned int AOE: 1; // Automatic output enable
      unsigned int MOE: 1; // Main output enable
      unsigned int BKF: 4; // Break filter
      unsigned int : 12; // Reserved
} BDTR;
// DMA control register
 struct {
      unsigned int DBA: 5; // DMA base address
      unsigned int : 3; // Reserved
      unsigned int DBL: 5; // DMA burst length
      unsigned int : 19; // Reserved
} DCR;
// DMA address for full transfer
 struct {
      unsigned int DMAB: 16; // DMA register for burst               accesses
      unsigned int : 16; // Reserved
} DMAR;
} SVD_TIM15;
asm(".equ SVD_TIM15, 0x40014000");
