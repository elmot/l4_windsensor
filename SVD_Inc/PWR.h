// Power control
 extern struct {
// Power control register 1
 struct {
      unsigned int LPMS: 3; // Low-power mode selection
      unsigned int : 5; // Reserved
      unsigned int DBP: 1; // Disable backup domain write               protection
      unsigned int VOS: 2; // Voltage scaling range               selection
      unsigned int : 3; // Reserved
      unsigned int LPR: 1; // Low-power run
      unsigned int : 17; // Reserved
} CR1;
// Power control register 2
 struct {
      unsigned int PVDE: 1; // Power voltage detector               enable
      unsigned int PLS: 3; // Power voltage detector level               selection
      unsigned int PVME1: 1; // Peripheral voltage monitoring 1 enable:               VDDUSB vs. 1.2V
      unsigned int PVME2: 1; // Peripheral voltage monitoring 2 enable:               VDDIO2 vs. 0.9V
      unsigned int PVME3: 1; // Peripheral voltage monitoring 3 enable:               VDDA vs. 1.62V
      unsigned int PVME4: 1; // Peripheral voltage monitoring 4 enable:               VDDA vs. 2.2V
      unsigned int : 1; // Reserved
      unsigned int IOSV: 1; // VDDIO2 Independent I/Os supply               valid
      unsigned int USV: 1; // VDDUSB USB supply valid
      unsigned int : 21; // Reserved
} CR2;
// Power control register 3
 struct {
      unsigned int EWUP1: 1; // Enable Wakeup pin WKUP1
      unsigned int EWUP2: 1; // Enable Wakeup pin WKUP2
      unsigned int EWUP3: 1; // Enable Wakeup pin WKUP3
      unsigned int EWUP4: 1; // Enable Wakeup pin WKUP4
      unsigned int EWUP5: 1; // Enable Wakeup pin WKUP5
      unsigned int : 3; // Reserved
      unsigned int RRS: 1; // SRAM2 retention in Standby               mode
      unsigned int : 1; // Reserved
      unsigned int APC: 1; // Apply pull-up and pull-down               configuration
      unsigned int : 4; // Reserved
      unsigned int EWF: 1; // Enable internal wakeup               line
      unsigned int : 16; // Reserved
} CR3;
// Power control register 4
 struct {
      unsigned int WP1: 1; // Wakeup pin WKUP1 polarity
      unsigned int WP2: 1; // Wakeup pin WKUP2 polarity
      unsigned int WP3: 1; // Wakeup pin WKUP3 polarity
      unsigned int WP4: 1; // Wakeup pin WKUP4 polarity
      unsigned int WP5: 1; // Wakeup pin WKUP5 polarity
      unsigned int : 3; // Reserved
      unsigned int VBE: 1; // VBAT battery charging               enable
      unsigned int VBRS: 1; // VBAT battery charging resistor               selection
      unsigned int : 22; // Reserved
} CR4;
// Power status register 1
 struct {
      unsigned int CWUF1: 1; // Wakeup flag 1
      unsigned int CWUF2: 1; // Wakeup flag 2
      unsigned int CWUF3: 1; // Wakeup flag 3
      unsigned int CWUF4: 1; // Wakeup flag 4
      unsigned int CWUF5: 1; // Wakeup flag 5
      unsigned int : 3; // Reserved
      unsigned int CSBF: 1; // Standby flag
      unsigned int : 6; // Reserved
      unsigned int WUFI: 1; // Wakeup flag internal
      unsigned int : 16; // Reserved
} SR1;
// Power status register 2
 struct {
      unsigned int : 8; // Reserved
      unsigned int REGLPS: 1; // Low-power regulator               started
      unsigned int REGLPF: 1; // Low-power regulator flag
      unsigned int VOSF: 1; // Voltage scaling flag
      unsigned int PVDO: 1; // Power voltage detector               output
      unsigned int PVMO1: 1; // Peripheral voltage monitoring output:               VDDUSB vs. 1.2 V
      unsigned int PVMO2: 1; // Peripheral voltage monitoring output:               VDDIO2 vs. 0.9 V
      unsigned int PVMO3: 1; // Peripheral voltage monitoring output:               VDDA vs. 1.62 V
      unsigned int PVMO4: 1; // Peripheral voltage monitoring output:               VDDA vs. 2.2 V
      unsigned int : 16; // Reserved
} SR2;
// Power status clear register
 struct {
      unsigned int WUF1: 1; // Clear wakeup flag 1
      unsigned int WUF2: 1; // Clear wakeup flag 2
      unsigned int WUF3: 1; // Clear wakeup flag 3
      unsigned int WUF4: 1; // Clear wakeup flag 4
      unsigned int WUF5: 1; // Clear wakeup flag 5
      unsigned int : 3; // Reserved
      unsigned int SBF: 1; // Clear standby flag
      unsigned int : 23; // Reserved
} SCR;
      unsigned int : 32; // Reserved
// Power Port A pull-up control           register
 struct {
      unsigned int PU0: 1; // Port A pull-up bit y               (y=0..15)
      unsigned int PU1: 1; // Port A pull-up bit y               (y=0..15)
      unsigned int PU2: 1; // Port A pull-up bit y               (y=0..15)
      unsigned int PU3: 1; // Port A pull-up bit y               (y=0..15)
      unsigned int PU4: 1; // Port A pull-up bit y               (y=0..15)
      unsigned int PU5: 1; // Port A pull-up bit y               (y=0..15)
      unsigned int PU6: 1; // Port A pull-up bit y               (y=0..15)
      unsigned int PU7: 1; // Port A pull-up bit y               (y=0..15)
      unsigned int PU8: 1; // Port A pull-up bit y               (y=0..15)
      unsigned int PU9: 1; // Port A pull-up bit y               (y=0..15)
      unsigned int PU10: 1; // Port A pull-up bit y               (y=0..15)
      unsigned int PU11: 1; // Port A pull-up bit y               (y=0..15)
      unsigned int PU12: 1; // Port A pull-up bit y               (y=0..15)
      unsigned int PU13: 1; // Port A pull-up bit y               (y=0..15)
      unsigned int PU14: 1; // Port A pull-up bit y               (y=0..15)
      unsigned int PU15: 1; // Port A pull-up bit y               (y=0..15)
      unsigned int : 16; // Reserved
} PUCRA;
// Power Port A pull-down control           register
 struct {
      unsigned int PD0: 1; // Port A pull-down bit y               (y=0..15)
      unsigned int PD1: 1; // Port A pull-down bit y               (y=0..15)
      unsigned int PD2: 1; // Port A pull-down bit y               (y=0..15)
      unsigned int PD3: 1; // Port A pull-down bit y               (y=0..15)
      unsigned int PD4: 1; // Port A pull-down bit y               (y=0..15)
      unsigned int PD5: 1; // Port A pull-down bit y               (y=0..15)
      unsigned int PD6: 1; // Port A pull-down bit y               (y=0..15)
      unsigned int PD7: 1; // Port A pull-down bit y               (y=0..15)
      unsigned int PD8: 1; // Port A pull-down bit y               (y=0..15)
      unsigned int PD9: 1; // Port A pull-down bit y               (y=0..15)
      unsigned int PD10: 1; // Port A pull-down bit y               (y=0..15)
      unsigned int PD11: 1; // Port A pull-down bit y               (y=0..15)
      unsigned int PD12: 1; // Port A pull-down bit y               (y=0..15)
      unsigned int PD13: 1; // Port A pull-down bit y               (y=0..15)
      unsigned int PD14: 1; // Port A pull-down bit y               (y=0..15)
      unsigned int PD15: 1; // Port A pull-down bit y               (y=0..15)
      unsigned int : 16; // Reserved
} PDCRA;
// Power Port B pull-up control           register
 struct {
      unsigned int PU0: 1; // Port B pull-up bit y               (y=0..15)
      unsigned int PU1: 1; // Port B pull-up bit y               (y=0..15)
      unsigned int PU2: 1; // Port B pull-up bit y               (y=0..15)
      unsigned int PU3: 1; // Port B pull-up bit y               (y=0..15)
      unsigned int PU4: 1; // Port B pull-up bit y               (y=0..15)
      unsigned int PU5: 1; // Port B pull-up bit y               (y=0..15)
      unsigned int PU6: 1; // Port B pull-up bit y               (y=0..15)
      unsigned int PU7: 1; // Port B pull-up bit y               (y=0..15)
      unsigned int PU8: 1; // Port B pull-up bit y               (y=0..15)
      unsigned int PU9: 1; // Port B pull-up bit y               (y=0..15)
      unsigned int PU10: 1; // Port B pull-up bit y               (y=0..15)
      unsigned int PU11: 1; // Port B pull-up bit y               (y=0..15)
      unsigned int PU12: 1; // Port B pull-up bit y               (y=0..15)
      unsigned int PU13: 1; // Port B pull-up bit y               (y=0..15)
      unsigned int PU14: 1; // Port B pull-up bit y               (y=0..15)
      unsigned int PU15: 1; // Port B pull-up bit y               (y=0..15)
      unsigned int : 16; // Reserved
} PUCRB;
// Power Port B pull-down control           register
 struct {
      unsigned int PD0: 1; // Port B pull-down bit y               (y=0..15)
      unsigned int PD1: 1; // Port B pull-down bit y               (y=0..15)
      unsigned int PD2: 1; // Port B pull-down bit y               (y=0..15)
      unsigned int PD3: 1; // Port B pull-down bit y               (y=0..15)
      unsigned int PD4: 1; // Port B pull-down bit y               (y=0..15)
      unsigned int PD5: 1; // Port B pull-down bit y               (y=0..15)
      unsigned int PD6: 1; // Port B pull-down bit y               (y=0..15)
      unsigned int PD7: 1; // Port B pull-down bit y               (y=0..15)
      unsigned int PD8: 1; // Port B pull-down bit y               (y=0..15)
      unsigned int PD9: 1; // Port B pull-down bit y               (y=0..15)
      unsigned int PD10: 1; // Port B pull-down bit y               (y=0..15)
      unsigned int PD11: 1; // Port B pull-down bit y               (y=0..15)
      unsigned int PD12: 1; // Port B pull-down bit y               (y=0..15)
      unsigned int PD13: 1; // Port B pull-down bit y               (y=0..15)
      unsigned int PD14: 1; // Port B pull-down bit y               (y=0..15)
      unsigned int PD15: 1; // Port B pull-down bit y               (y=0..15)
      unsigned int : 16; // Reserved
} PDCRB;
// Power Port C pull-up control           register
 struct {
      unsigned int PU0: 1; // Port C pull-up bit y               (y=0..15)
      unsigned int PU1: 1; // Port C pull-up bit y               (y=0..15)
      unsigned int PU2: 1; // Port C pull-up bit y               (y=0..15)
      unsigned int PU3: 1; // Port C pull-up bit y               (y=0..15)
      unsigned int PU4: 1; // Port C pull-up bit y               (y=0..15)
      unsigned int PU5: 1; // Port C pull-up bit y               (y=0..15)
      unsigned int PU6: 1; // Port C pull-up bit y               (y=0..15)
      unsigned int PU7: 1; // Port C pull-up bit y               (y=0..15)
      unsigned int PU8: 1; // Port C pull-up bit y               (y=0..15)
      unsigned int PU9: 1; // Port C pull-up bit y               (y=0..15)
      unsigned int PU10: 1; // Port C pull-up bit y               (y=0..15)
      unsigned int PU11: 1; // Port C pull-up bit y               (y=0..15)
      unsigned int PU12: 1; // Port C pull-up bit y               (y=0..15)
      unsigned int PU13: 1; // Port C pull-up bit y               (y=0..15)
      unsigned int PU14: 1; // Port C pull-up bit y               (y=0..15)
      unsigned int PU15: 1; // Port C pull-up bit y               (y=0..15)
      unsigned int : 16; // Reserved
} PUCRC;
// Power Port C pull-down control           register
 struct {
      unsigned int PD0: 1; // Port C pull-down bit y               (y=0..15)
      unsigned int PD1: 1; // Port C pull-down bit y               (y=0..15)
      unsigned int PD2: 1; // Port C pull-down bit y               (y=0..15)
      unsigned int PD3: 1; // Port C pull-down bit y               (y=0..15)
      unsigned int PD4: 1; // Port C pull-down bit y               (y=0..15)
      unsigned int PD5: 1; // Port C pull-down bit y               (y=0..15)
      unsigned int PD6: 1; // Port C pull-down bit y               (y=0..15)
      unsigned int PD7: 1; // Port C pull-down bit y               (y=0..15)
      unsigned int PD8: 1; // Port C pull-down bit y               (y=0..15)
      unsigned int PD9: 1; // Port C pull-down bit y               (y=0..15)
      unsigned int PD10: 1; // Port C pull-down bit y               (y=0..15)
      unsigned int PD11: 1; // Port C pull-down bit y               (y=0..15)
      unsigned int PD12: 1; // Port C pull-down bit y               (y=0..15)
      unsigned int PD13: 1; // Port C pull-down bit y               (y=0..15)
      unsigned int PD14: 1; // Port C pull-down bit y               (y=0..15)
      unsigned int PD15: 1; // Port C pull-down bit y               (y=0..15)
      unsigned int : 16; // Reserved
} PDCRC;
// Power Port D pull-up control           register
 struct {
      unsigned int PU0: 1; // Port D pull-up bit y               (y=0..15)
      unsigned int PU1: 1; // Port D pull-up bit y               (y=0..15)
      unsigned int PU2: 1; // Port D pull-up bit y               (y=0..15)
      unsigned int PU3: 1; // Port D pull-up bit y               (y=0..15)
      unsigned int PU4: 1; // Port D pull-up bit y               (y=0..15)
      unsigned int PU5: 1; // Port D pull-up bit y               (y=0..15)
      unsigned int PU6: 1; // Port D pull-up bit y               (y=0..15)
      unsigned int PU7: 1; // Port D pull-up bit y               (y=0..15)
      unsigned int PU8: 1; // Port D pull-up bit y               (y=0..15)
      unsigned int PU9: 1; // Port D pull-up bit y               (y=0..15)
      unsigned int PU10: 1; // Port D pull-up bit y               (y=0..15)
      unsigned int PU11: 1; // Port D pull-up bit y               (y=0..15)
      unsigned int PU12: 1; // Port D pull-up bit y               (y=0..15)
      unsigned int PU13: 1; // Port D pull-up bit y               (y=0..15)
      unsigned int PU14: 1; // Port D pull-up bit y               (y=0..15)
      unsigned int PU15: 1; // Port D pull-up bit y               (y=0..15)
      unsigned int : 16; // Reserved
} PUCRD;
// Power Port D pull-down control           register
 struct {
      unsigned int PD0: 1; // Port D pull-down bit y               (y=0..15)
      unsigned int PD1: 1; // Port D pull-down bit y               (y=0..15)
      unsigned int PD2: 1; // Port D pull-down bit y               (y=0..15)
      unsigned int PD3: 1; // Port D pull-down bit y               (y=0..15)
      unsigned int PD4: 1; // Port D pull-down bit y               (y=0..15)
      unsigned int PD5: 1; // Port D pull-down bit y               (y=0..15)
      unsigned int PD6: 1; // Port D pull-down bit y               (y=0..15)
      unsigned int PD7: 1; // Port D pull-down bit y               (y=0..15)
      unsigned int PD8: 1; // Port D pull-down bit y               (y=0..15)
      unsigned int PD9: 1; // Port D pull-down bit y               (y=0..15)
      unsigned int PD10: 1; // Port D pull-down bit y               (y=0..15)
      unsigned int PD11: 1; // Port D pull-down bit y               (y=0..15)
      unsigned int PD12: 1; // Port D pull-down bit y               (y=0..15)
      unsigned int PD13: 1; // Port D pull-down bit y               (y=0..15)
      unsigned int PD14: 1; // Port D pull-down bit y               (y=0..15)
      unsigned int PD15: 1; // Port D pull-down bit y               (y=0..15)
      unsigned int : 16; // Reserved
} PDCRD;
// Power Port E pull-up control           register
 struct {
      unsigned int PU0: 1; // Port E pull-up bit y               (y=0..15)
      unsigned int PU1: 1; // Port E pull-up bit y               (y=0..15)
      unsigned int PU2: 1; // Port E pull-up bit y               (y=0..15)
      unsigned int PU3: 1; // Port E pull-up bit y               (y=0..15)
      unsigned int PU4: 1; // Port E pull-up bit y               (y=0..15)
      unsigned int PU5: 1; // Port E pull-up bit y               (y=0..15)
      unsigned int PU6: 1; // Port E pull-up bit y               (y=0..15)
      unsigned int PU7: 1; // Port E pull-up bit y               (y=0..15)
      unsigned int PU8: 1; // Port E pull-up bit y               (y=0..15)
      unsigned int PU9: 1; // Port E pull-up bit y               (y=0..15)
      unsigned int PU10: 1; // Port E pull-up bit y               (y=0..15)
      unsigned int PU11: 1; // Port E pull-up bit y               (y=0..15)
      unsigned int PU12: 1; // Port E pull-up bit y               (y=0..15)
      unsigned int PU13: 1; // Port E pull-up bit y               (y=0..15)
      unsigned int PU14: 1; // Port E pull-up bit y               (y=0..15)
      unsigned int PU15: 1; // Port E pull-up bit y               (y=0..15)
      unsigned int : 16; // Reserved
} PUCRE;
// Power Port E pull-down control           register
 struct {
      unsigned int PD0: 1; // Port E pull-down bit y               (y=0..15)
      unsigned int PD1: 1; // Port E pull-down bit y               (y=0..15)
      unsigned int PD2: 1; // Port E pull-down bit y               (y=0..15)
      unsigned int PD3: 1; // Port E pull-down bit y               (y=0..15)
      unsigned int PD4: 1; // Port E pull-down bit y               (y=0..15)
      unsigned int PD5: 1; // Port E pull-down bit y               (y=0..15)
      unsigned int PD6: 1; // Port E pull-down bit y               (y=0..15)
      unsigned int PD7: 1; // Port E pull-down bit y               (y=0..15)
      unsigned int PD8: 1; // Port E pull-down bit y               (y=0..15)
      unsigned int PD9: 1; // Port E pull-down bit y               (y=0..15)
      unsigned int PD10: 1; // Port E pull-down bit y               (y=0..15)
      unsigned int PD11: 1; // Port E pull-down bit y               (y=0..15)
      unsigned int PD12: 1; // Port E pull-down bit y               (y=0..15)
      unsigned int PD13: 1; // Port E pull-down bit y               (y=0..15)
      unsigned int PD14: 1; // Port E pull-down bit y               (y=0..15)
      unsigned int PD15: 1; // Port E pull-down bit y               (y=0..15)
      unsigned int : 16; // Reserved
} PDCRE;
// Power Port F pull-up control           register
 struct {
      unsigned int PU0: 1; // Port F pull-up bit y               (y=0..15)
      unsigned int PU1: 1; // Port F pull-up bit y               (y=0..15)
      unsigned int PU2: 1; // Port F pull-up bit y               (y=0..15)
      unsigned int PU3: 1; // Port F pull-up bit y               (y=0..15)
      unsigned int PU4: 1; // Port F pull-up bit y               (y=0..15)
      unsigned int PU5: 1; // Port F pull-up bit y               (y=0..15)
      unsigned int PU6: 1; // Port F pull-up bit y               (y=0..15)
      unsigned int PU7: 1; // Port F pull-up bit y               (y=0..15)
      unsigned int PU8: 1; // Port F pull-up bit y               (y=0..15)
      unsigned int PU9: 1; // Port F pull-up bit y               (y=0..15)
      unsigned int PU10: 1; // Port F pull-up bit y               (y=0..15)
      unsigned int PU11: 1; // Port F pull-up bit y               (y=0..15)
      unsigned int PU12: 1; // Port F pull-up bit y               (y=0..15)
      unsigned int PU13: 1; // Port F pull-up bit y               (y=0..15)
      unsigned int PU14: 1; // Port F pull-up bit y               (y=0..15)
      unsigned int PU15: 1; // Port F pull-up bit y               (y=0..15)
      unsigned int : 16; // Reserved
} PUCRF;
// Power Port F pull-down control           register
 struct {
      unsigned int PD0: 1; // Port F pull-down bit y               (y=0..15)
      unsigned int PD1: 1; // Port F pull-down bit y               (y=0..15)
      unsigned int PD2: 1; // Port F pull-down bit y               (y=0..15)
      unsigned int PD3: 1; // Port F pull-down bit y               (y=0..15)
      unsigned int PD4: 1; // Port F pull-down bit y               (y=0..15)
      unsigned int PD5: 1; // Port F pull-down bit y               (y=0..15)
      unsigned int PD6: 1; // Port F pull-down bit y               (y=0..15)
      unsigned int PD7: 1; // Port F pull-down bit y               (y=0..15)
      unsigned int PD8: 1; // Port F pull-down bit y               (y=0..15)
      unsigned int PD9: 1; // Port F pull-down bit y               (y=0..15)
      unsigned int PD10: 1; // Port F pull-down bit y               (y=0..15)
      unsigned int PD11: 1; // Port F pull-down bit y               (y=0..15)
      unsigned int PD12: 1; // Port F pull-down bit y               (y=0..15)
      unsigned int PD13: 1; // Port F pull-down bit y               (y=0..15)
      unsigned int PD14: 1; // Port F pull-down bit y               (y=0..15)
      unsigned int PD15: 1; // Port F pull-down bit y               (y=0..15)
      unsigned int : 16; // Reserved
} PDCRF;
// Power Port G pull-up control           register
 struct {
      unsigned int PU0: 1; // Port G pull-up bit y               (y=0..15)
      unsigned int PU1: 1; // Port G pull-up bit y               (y=0..15)
      unsigned int PU2: 1; // Port G pull-up bit y               (y=0..15)
      unsigned int PU3: 1; // Port G pull-up bit y               (y=0..15)
      unsigned int PU4: 1; // Port G pull-up bit y               (y=0..15)
      unsigned int PU5: 1; // Port G pull-up bit y               (y=0..15)
      unsigned int PU6: 1; // Port G pull-up bit y               (y=0..15)
      unsigned int PU7: 1; // Port G pull-up bit y               (y=0..15)
      unsigned int PU8: 1; // Port G pull-up bit y               (y=0..15)
      unsigned int PU9: 1; // Port G pull-up bit y               (y=0..15)
      unsigned int PU10: 1; // Port G pull-up bit y               (y=0..15)
      unsigned int PU11: 1; // Port G pull-up bit y               (y=0..15)
      unsigned int PU12: 1; // Port G pull-up bit y               (y=0..15)
      unsigned int PU13: 1; // Port G pull-up bit y               (y=0..15)
      unsigned int PU14: 1; // Port G pull-up bit y               (y=0..15)
      unsigned int PU15: 1; // Port G pull-up bit y               (y=0..15)
      unsigned int : 16; // Reserved
} PUCRG;
// Power Port G pull-down control           register
 struct {
      unsigned int PD0: 1; // Port G pull-down bit y               (y=0..15)
      unsigned int PD1: 1; // Port G pull-down bit y               (y=0..15)
      unsigned int PD2: 1; // Port G pull-down bit y               (y=0..15)
      unsigned int PD3: 1; // Port G pull-down bit y               (y=0..15)
      unsigned int PD4: 1; // Port G pull-down bit y               (y=0..15)
      unsigned int PD5: 1; // Port G pull-down bit y               (y=0..15)
      unsigned int PD6: 1; // Port G pull-down bit y               (y=0..15)
      unsigned int PD7: 1; // Port G pull-down bit y               (y=0..15)
      unsigned int PD8: 1; // Port G pull-down bit y               (y=0..15)
      unsigned int PD9: 1; // Port G pull-down bit y               (y=0..15)
      unsigned int PD10: 1; // Port G pull-down bit y               (y=0..15)
      unsigned int PD11: 1; // Port G pull-down bit y               (y=0..15)
      unsigned int PD12: 1; // Port G pull-down bit y               (y=0..15)
      unsigned int PD13: 1; // Port G pull-down bit y               (y=0..15)
      unsigned int PD14: 1; // Port G pull-down bit y               (y=0..15)
      unsigned int PD15: 1; // Port G pull-down bit y               (y=0..15)
      unsigned int : 16; // Reserved
} PDCRG;
// Power Port H pull-up control           register
 struct {
      unsigned int PU0: 1; // Port H pull-up bit y               (y=0..1)
      unsigned int PU1: 1; // Port H pull-up bit y               (y=0..1)
      unsigned int : 30; // Reserved
} PUCRH;
// Power Port H pull-down control           register
 struct {
      unsigned int PD0: 1; // Port H pull-down bit y               (y=0..1)
      unsigned int PD1: 1; // Port H pull-down bit y               (y=0..1)
      unsigned int : 30; // Reserved
} PDCRH;
} SVD_PWR;
asm(".equ SVD_PWR, 0x40007000");
