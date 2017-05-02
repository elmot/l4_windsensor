// Digital-to-analog converter
 extern struct {
// control register
 struct {
      unsigned int EN1: 1; // DAC channel1 enable
      unsigned int : 1; // Reserved
      unsigned int TEN1: 1; // DAC channel1 trigger               enable
      unsigned int TSEL1: 3; // DAC channel1 trigger               selection
      unsigned int WAVE1: 2; // DAC channel1 noise/triangle wave               generation enable
      unsigned int MAMP1: 4; // DAC channel1 mask/amplitude               selector
      unsigned int DMAEN1: 1; // DAC channel1 DMA enable
      unsigned int DMAUDRIE1: 1; // DAC channel1 DMA Underrun Interrupt               enable
      unsigned int CEN1: 1; // DAC Channel 1 calibration               enable
      unsigned int : 1; // Reserved
      unsigned int EN2: 1; // DAC channel2 enable
      unsigned int : 1; // Reserved
      unsigned int TEN2: 1; // DAC channel2 trigger               enable
      unsigned int TSEL2: 3; // DAC channel2 trigger               selection
      unsigned int WAVE2: 2; // DAC channel2 noise/triangle wave               generation enable
      unsigned int MAMP2: 4; // DAC channel2 mask/amplitude               selector
      unsigned int DMAEN2: 1; // DAC channel2 DMA enable
      unsigned int DMAUDRIE2: 1; // DAC channel2 DMA underrun interrupt               enable
      unsigned int CEN2: 1; // DAC Channel 2 calibration               enable
      unsigned int : 1; // Reserved
} CR;
// software trigger register
 struct {
      unsigned int SWTRIG1: 1; // DAC channel1 software               trigger
      unsigned int SWTRIG2: 1; // DAC channel2 software               trigger
      unsigned int : 30; // Reserved
} SWTRIGR;
// channel1 12-bit right-aligned data holding           register
 struct {
      unsigned int DACC1DHR: 12; // DAC channel1 12-bit right-aligned               data
      unsigned int : 20; // Reserved
} DHR12R1;
// channel1 12-bit left-aligned data holding           register
 struct {
      unsigned int : 4; // Reserved
      unsigned int DACC1DHR: 12; // DAC channel1 12-bit left-aligned               data
      unsigned int : 16; // Reserved
} DHR12L1;
// channel1 8-bit right-aligned data holding           register
 struct {
      unsigned int DACC1DHR: 8; // DAC channel1 8-bit right-aligned               data
      unsigned int : 24; // Reserved
} DHR8R1;
// channel2 12-bit right aligned data holding           register
 struct {
      unsigned int DACC2DHR: 12; // DAC channel2 12-bit right-aligned               data
      unsigned int : 20; // Reserved
} DHR12R2;
// channel2 12-bit left aligned data holding           register
 struct {
      unsigned int : 4; // Reserved
      unsigned int DACC2DHR: 12; // DAC channel2 12-bit left-aligned               data
      unsigned int : 16; // Reserved
} DHR12L2;
// channel2 8-bit right-aligned data holding           register
 struct {
      unsigned int DACC2DHR: 8; // DAC channel2 8-bit right-aligned               data
      unsigned int : 24; // Reserved
} DHR8R2;
// Dual DAC 12-bit right-aligned data holding           register
 struct {
      unsigned int DACC1DHR: 12; // DAC channel1 12-bit right-aligned               data
      unsigned int : 4; // Reserved
      unsigned int DACC2DHR: 12; // DAC channel2 12-bit right-aligned               data
      unsigned int : 4; // Reserved
} DHR12RD;
// DUAL DAC 12-bit left aligned data holding           register
 struct {
      unsigned int : 4; // Reserved
      unsigned int DACC1DHR: 12; // DAC channel1 12-bit left-aligned               data
      unsigned int : 4; // Reserved
      unsigned int DACC2DHR: 12; // DAC channel2 12-bit left-aligned               data
} DHR12LD;
// DUAL DAC 8-bit right aligned data holding           register
 struct {
      unsigned int DACC1DHR: 8; // DAC channel1 8-bit right-aligned               data
      unsigned int DACC2DHR: 8; // DAC channel2 8-bit right-aligned               data
      unsigned int : 16; // Reserved
} DHR8RD;
// channel1 data output register
 struct {
      unsigned int DACC1DOR: 12; // DAC channel1 data output
      unsigned int : 20; // Reserved
} DOR1;
// channel2 data output register
 struct {
      unsigned int DACC2DOR: 12; // DAC channel2 data output
      unsigned int : 20; // Reserved
} DOR2;
// status register
 struct {
      unsigned int : 13; // Reserved
      unsigned int DMAUDR1: 1; // DAC channel1 DMA underrun               flag
      unsigned int CAL_FLAG1: 1; // DAC Channel 1 calibration offset               status
      unsigned int BWST1: 1; // DAC Channel 1 busy writing sample time               flag
      unsigned int : 13; // Reserved
      unsigned int DMAUDR2: 1; // DAC channel2 DMA underrun               flag
      unsigned int CAL_FLAG2: 1; // DAC Channel 2 calibration offset               status
      unsigned int BWST2: 1; // DAC Channel 2 busy writing sample time               flag
} SR;
// calibration control register
 struct {
      unsigned int OTRIM1: 5; // DAC Channel 1 offset trimming               value
      unsigned int : 11; // Reserved
      unsigned int OTRIM2: 5; // DAC Channel 2 offset trimming               value
      unsigned int : 11; // Reserved
} CCR;
// mode control register
 struct {
      unsigned int MODE1: 3; // DAC Channel 1 mode
      unsigned int : 13; // Reserved
      unsigned int MODE2: 3; // DAC Channel 2 mode
      unsigned int : 13; // Reserved
} MCR;
// Sample and Hold sample time register           1
 struct {
      unsigned int TSAMPLE1: 10; // DAC Channel 1 sample Time
      unsigned int : 22; // Reserved
} SHSR1;
// Sample and Hold sample time register           2
 struct {
      unsigned int TSAMPLE2: 10; // DAC Channel 2 sample Time
      unsigned int : 22; // Reserved
} SHSR2;
// Sample and Hold hold time           register
 struct {
      unsigned int THOLD1: 10; // DAC Channel 1 hold Time
      unsigned int : 6; // Reserved
      unsigned int THOLD2: 10; // DAC Channel 2 hold time
      unsigned int : 6; // Reserved
} SHHR;
// Sample and Hold refresh time           register
 struct {
      unsigned int TREFRESH1: 8; // DAC Channel 1 refresh Time
      unsigned int : 8; // Reserved
      unsigned int TREFRESH2: 8; // DAC Channel 2 refresh Time
      unsigned int : 8; // Reserved
} SHRR;
} SVD_DAC1;
asm(".equ SVD_DAC1, 0x40007400");
