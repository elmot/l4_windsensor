// Advanced-timers
 extern struct {
// control register 1
 struct {
      unsigned int CEN: 1; // Counter enable
      unsigned int UDIS: 1; // Update disable
      unsigned int URS: 1; // Update request source
      unsigned int OPM: 1; // One-pulse mode
      unsigned int DIR: 1; // Direction
      unsigned int CMS: 2; // Center-aligned mode               selection
      unsigned int ARPE: 1; // Auto-reload preload enable
      unsigned int CKD: 2; // Clock division
      unsigned int : 22; // Reserved
} CR1;
// control register 2
 struct {
      unsigned int CCPC: 1; // Capture/compare preloaded               control
      unsigned int : 1; // Reserved
      unsigned int CCUS: 1; // Capture/compare control update               selection
      unsigned int CCDS: 1; // Capture/compare DMA               selection
      unsigned int MMS: 3; // Master mode selection
      unsigned int TI1S: 1; // TI1 selection
      unsigned int OIS1: 1; // Output Idle state 1
      unsigned int OIS1N: 1; // Output Idle state 1
      unsigned int OIS2: 1; // Output Idle state 2
      unsigned int OIS2N: 1; // Output Idle state 2
      unsigned int OIS3: 1; // Output Idle state 3
      unsigned int OIS3N: 1; // Output Idle state 3
      unsigned int OIS4: 1; // Output Idle state 4
      unsigned int : 17; // Reserved
} CR2;
// slave mode control register
 struct {
      unsigned int SMS: 3; // Slave mode selection
      unsigned int : 1; // Reserved
      unsigned int TS: 3; // Trigger selection
      unsigned int MSM: 1; // Master/Slave mode
      unsigned int ETF: 4; // External trigger filter
      unsigned int ETPS: 2; // External trigger prescaler
      unsigned int ECE: 1; // External clock enable
      unsigned int ETP: 1; // External trigger polarity
      unsigned int : 16; // Reserved
} SMCR;
// DMA/Interrupt enable register
 struct {
      unsigned int UIE: 1; // Update interrupt enable
      unsigned int CC1IE: 1; // Capture/Compare 1 interrupt               enable
      unsigned int CC2IE: 1; // Capture/Compare 2 interrupt               enable
      unsigned int CC3IE: 1; // Capture/Compare 3 interrupt               enable
      unsigned int CC4IE: 1; // Capture/Compare 4 interrupt               enable
      unsigned int COMIE: 1; // COM interrupt enable
      unsigned int TIE: 1; // Trigger interrupt enable
      unsigned int BIE: 1; // Break interrupt enable
      unsigned int UDE: 1; // Update DMA request enable
      unsigned int CC1DE: 1; // Capture/Compare 1 DMA request               enable
      unsigned int CC2DE: 1; // Capture/Compare 2 DMA request               enable
      unsigned int CC3DE: 1; // Capture/Compare 3 DMA request               enable
      unsigned int CC4DE: 1; // Capture/Compare 4 DMA request               enable
      unsigned int COMDE: 1; // COM DMA request enable
      unsigned int TDE: 1; // Trigger DMA request enable
      unsigned int : 17; // Reserved
} DIER;
// status register
 struct {
      unsigned int UIF: 1; // Update interrupt flag
      unsigned int CC1IF: 1; // Capture/compare 1 interrupt               flag
      unsigned int CC2IF: 1; // Capture/Compare 2 interrupt               flag
      unsigned int CC3IF: 1; // Capture/Compare 3 interrupt               flag
      unsigned int CC4IF: 1; // Capture/Compare 4 interrupt               flag
      unsigned int COMIF: 1; // COM interrupt flag
      unsigned int TIF: 1; // Trigger interrupt flag
      unsigned int BIF: 1; // Break interrupt flag
      unsigned int : 1; // Reserved
      unsigned int CC1OF: 1; // Capture/Compare 1 overcapture               flag
      unsigned int CC2OF: 1; // Capture/compare 2 overcapture               flag
      unsigned int CC3OF: 1; // Capture/Compare 3 overcapture               flag
      unsigned int CC4OF: 1; // Capture/Compare 4 overcapture               flag
      unsigned int : 19; // Reserved
} SR;
// event generation register
 struct {
      unsigned int UG: 1; // Update generation
      unsigned int CC1G: 1; // Capture/compare 1               generation
      unsigned int CC2G: 1; // Capture/compare 2               generation
      unsigned int CC3G: 1; // Capture/compare 3               generation
      unsigned int CC4G: 1; // Capture/compare 4               generation
      unsigned int COMG: 1; // Capture/Compare control update               generation
      unsigned int TG: 1; // Trigger generation
      unsigned int BG: 1; // Break generation
      unsigned int : 24; // Reserved
} EGR;
  union {
// capture/compare mode register 1 (output           mode)
 struct {
      unsigned int CC1S: 2; // Capture/Compare 1               selection
      unsigned int OC1FE: 1; // Output Compare 1 fast               enable
      unsigned int OC1PE: 1; // Output Compare 1 preload               enable
      unsigned int OC1M: 3; // Output Compare 1 mode
      unsigned int OC1CE: 1; // Output Compare 1 clear               enable
      unsigned int CC2S: 2; // Capture/Compare 2               selection
      unsigned int OC2FE: 1; // Output Compare 2 fast               enable
      unsigned int OC2PE: 1; // Output Compare 2 preload               enable
      unsigned int OC2M: 3; // Output Compare 2 mode
      unsigned int OC2CE: 1; // Output Compare 2 clear               enable
      unsigned int : 16; // Reserved
} CCMR1_Output;
// capture/compare mode register 1 (input           mode)
 struct {
      unsigned int CC1S: 2; // Capture/Compare 1               selection
      unsigned int ICPCS: 2; // Input capture 1 prescaler
      unsigned int IC1F: 4; // Input capture 1 filter
      unsigned int CC2S: 2; // Capture/Compare 2               selection
      unsigned int IC2PCS: 2; // Input capture 2 prescaler
      unsigned int IC2F: 4; // Input capture 2 filter
      unsigned int : 16; // Reserved
} CCMR1_Input;
  } CCMR1_Output_CCMR1_Input;
  union {
// capture/compare mode register 2 (output           mode)
 struct {
      unsigned int CC3S: 2; // Capture/Compare 3               selection
      unsigned int OC3FE: 1; // Output compare 3 fast               enable
      unsigned int OC3PE: 1; // Output compare 3 preload               enable
      unsigned int OC3M: 3; // Output compare 3 mode
      unsigned int OC3CE: 1; // Output compare 3 clear               enable
      unsigned int CC4S: 2; // Capture/Compare 4               selection
      unsigned int OC4FE: 1; // Output compare 4 fast               enable
      unsigned int OC4PE: 1; // Output compare 4 preload               enable
      unsigned int OC4M: 3; // Output compare 4 mode
      unsigned int OC4CE: 1; // Output compare 4 clear               enable
      unsigned int : 16; // Reserved
} CCMR2_Output;
// capture/compare mode register 2 (input           mode)
 struct {
      unsigned int CC3S: 2; // Capture/compare 3               selection
      unsigned int IC3PSC: 2; // Input capture 3 prescaler
      unsigned int IC3F: 4; // Input capture 3 filter
      unsigned int CC4S: 2; // Capture/Compare 4               selection
      unsigned int IC4PSC: 2; // Input capture 4 prescaler
      unsigned int IC4F: 4; // Input capture 4 filter
      unsigned int : 16; // Reserved
} CCMR2_Input;
  } CCMR2_Output_CCMR2_Input;
// capture/compare enable           register
 struct {
      unsigned int CC1E: 1; // Capture/Compare 1 output               enable
      unsigned int CC1P: 1; // Capture/Compare 1 output               Polarity
      unsigned int CC1NE: 1; // Capture/Compare 1 complementary output               enable
      unsigned int CC1NP: 1; // Capture/Compare 1 output               Polarity
      unsigned int CC2E: 1; // Capture/Compare 2 output               enable
      unsigned int CC2P: 1; // Capture/Compare 2 output               Polarity
      unsigned int CC2NE: 1; // Capture/Compare 2 complementary output               enable
      unsigned int CC2NP: 1; // Capture/Compare 2 output               Polarity
      unsigned int CC3E: 1; // Capture/Compare 3 output               enable
      unsigned int CC3P: 1; // Capture/Compare 3 output               Polarity
      unsigned int CC3NE: 1; // Capture/Compare 3 complementary output               enable
      unsigned int CC3NP: 1; // Capture/Compare 3 output               Polarity
      unsigned int CC4E: 1; // Capture/Compare 4 output               enable
      unsigned int CC4P: 1; // Capture/Compare 3 output               Polarity
      unsigned int : 18; // Reserved
} CCER;
// counter
 struct {
      unsigned int CNT: 16; // counter value
      unsigned int : 16; // Reserved
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
// capture/compare register 2
 struct {
      unsigned int CCR2: 16; // Capture/Compare 2 value
      unsigned int : 16; // Reserved
} CCR2;
// capture/compare register 3
 struct {
      unsigned int CCR3: 16; // Capture/Compare value
      unsigned int : 16; // Reserved
} CCR3;
// capture/compare register 4
 struct {
      unsigned int CCR4: 16; // Capture/Compare value
      unsigned int : 16; // Reserved
} CCR4;
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
      unsigned int : 16; // Reserved
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
// DMA address for full transfer
 struct {
      unsigned int ETR_ADC1_RMP: 2; // External trigger remap on ADC1 analog               watchdog
      unsigned int ETR_ADC3_RMP: 2; // External trigger remap on ADC3 analog               watchdog
      unsigned int TI1_RMP: 1; // Input Capture 1 remap
      unsigned int : 27; // Reserved
} OR1;
// capture/compare mode register 2 (output           mode)
 struct {
      unsigned int : 2; // Reserved
      unsigned int OC5FE: 1; // Output compare 5 fast               enable
      unsigned int OC5PE: 1; // Output compare 5 preload               enable
      unsigned int OC5M: 3; // Output compare 5 mode
      unsigned int OC5CE: 1; // Output compare 5 clear               enable
      unsigned int : 2; // Reserved
      unsigned int OC6FE: 1; // Output compare 6 fast               enable
      unsigned int OC6PE: 1; // Output compare 6 preload               enable
      unsigned int OC6M: 3; // Output compare 6 mode
      unsigned int OC6CE: 1; // Output compare 6 clear               enable
      unsigned int OC5M_bit3: 3; // Output Compare 5 mode bit               3
      unsigned int : 5; // Reserved
      unsigned int OC6M_bit3: 1; // Output Compare 6 mode bit               3
      unsigned int : 7; // Reserved
} CCMR3_Output;
// capture/compare register 4
 struct {
      unsigned int CCR5: 16; // Capture/Compare value
      unsigned int : 13; // Reserved
      unsigned int GC5C1: 1; // Group Channel 5 and Channel               1
      unsigned int GC5C2: 1; // Group Channel 5 and Channel               2
      unsigned int GC5C3: 1; // Group Channel 5 and Channel               3
} CCR5;
// capture/compare register 4
 struct {
      unsigned int CCR6: 16; // Capture/Compare value
      unsigned int : 16; // Reserved
} CCR6;
// DMA address for full transfer
 struct {
      unsigned int BKINE: 1; // BRK BKIN input enable
      unsigned int BKCMP1E: 1; // BRK COMP1 enable
      unsigned int BKCMP2E: 1; // BRK COMP2 enable
      unsigned int : 5; // Reserved
      unsigned int BKDFBK0E: 1; // BRK DFSDM_BREAK0 enable
      unsigned int BKINP: 1; // BRK BKIN input polarity
      unsigned int BKCMP1P: 1; // BRK COMP1 input polarity
      unsigned int BKCMP2P: 1; // BRK COMP2 input polarity
      unsigned int : 2; // Reserved
      unsigned int ETRSEL: 3; // ETR source selection
      unsigned int : 15; // Reserved
} OR2;
// DMA address for full transfer
 struct {
      unsigned int BK2INE: 1; // BRK2 BKIN input enable
      unsigned int BK2CMP1E: 1; // BRK2 COMP1 enable
      unsigned int BK2CMP2E: 1; // BRK2 COMP2 enable
      unsigned int : 5; // Reserved
      unsigned int BK2DFBK0E: 1; // BRK2 DFSDM_BREAK0 enable
      unsigned int BK2INP: 1; // BRK2 BKIN input polarity
      unsigned int BK2CMP1P: 1; // BRK2 COMP1 input polarity
      unsigned int BK2CMP2P: 1; // BRK2 COMP2 input polarity
      unsigned int : 20; // Reserved
} OR3;
} SVD_TIM1;
asm(".equ SVD_TIM1, 0x40012c00");
