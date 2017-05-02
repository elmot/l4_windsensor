// Random number generator
 extern struct {
// control register
 struct {
      unsigned int : 2; // Reserved
      unsigned int RNGEN: 1; // Random number generator               enable
      unsigned int IE: 1; // Interrupt enable
      unsigned int : 28; // Reserved
} CR;
// status register
 struct {
      unsigned int DRDY: 1; // Data ready
      unsigned int CECS: 1; // Clock error current status
      unsigned int SECS: 1; // Seed error current status
      unsigned int : 2; // Reserved
      unsigned int CEIS: 1; // Clock error interrupt               status
      unsigned int SEIS: 1; // Seed error interrupt               status
      unsigned int : 25; // Reserved
} SR;
// data register
 struct {
      unsigned int RNDATA: 32; // Random data
} DR;
} SVD_RNG;
asm(".equ SVD_RNG, 0x50060800");
