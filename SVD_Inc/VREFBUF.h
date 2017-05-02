// Voltage reference buffer
 extern struct {
// VREF control and status           register
 struct {
      unsigned int ENVR: 1; // Voltage reference buffer               enable
      unsigned int HIZ: 1; // High impedance mode
      unsigned int VRS: 1; // Voltage reference scale
      unsigned int VRR: 1; // Voltage reference buffer               ready
      unsigned int : 28; // Reserved
} CSR;
// calibration control register
 struct {
      unsigned int TRIM: 6; // Trimming code
      unsigned int : 26; // Reserved
} CCR;
} SVD_VREFBUF;
asm(".equ SVD_VREFBUF, 0x40010030");
