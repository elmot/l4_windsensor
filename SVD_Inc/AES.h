// Advanced encryption standard hardware       accelerator
 extern struct {
// control register
 struct {
      unsigned int EN: 1; // AES enable
      unsigned int DATATYPE: 2; // Data type selection (for data in and               data out to/from the cryptographic               block)
      unsigned int MODE: 2; // AES operating mode
      unsigned int CHMOD: 2; // AES chaining mode
      unsigned int CCFC: 1; // Computation Complete Flag               Clear
      unsigned int ERRC: 1; // Error clear
      unsigned int CCFIE: 1; // CCF flag interrupt enable
      unsigned int ERRIE: 1; // Error interrupt enable
      unsigned int DMAINEN: 1; // Enable DMA management of data input               phase
      unsigned int DMAOUTEN: 1; // Enable DMA management of data output               phase
      unsigned int : 19; // Reserved
} CR;
// status register
 struct {
      unsigned int CCF: 1; // Computation complete flag
      unsigned int RDERR: 1; // Read error flag
      unsigned int WRERR: 1; // Write error flag
      unsigned int : 29; // Reserved
} SR;
// data input register
 struct {
      unsigned int AES_DINR: 32; // Data Input Register
} DINR;
// data output register
 struct {
      unsigned int AES_DOUTR: 32; // Data output register
} DOUTR;
// key register 0
 struct {
      unsigned int AES_KEYR0: 32; // Data Output Register (LSB key               [31:0])
} KEYR0;
// key register 1
 struct {
      unsigned int AES_KEYR1: 32; // AES key register (key               [63:32])
} KEYR1;
// key register 2
 struct {
      unsigned int AES_KEYR2: 32; // AES key register (key               [95:64])
} KEYR2;
// key register 3
 struct {
      unsigned int AES_KEYR3: 32; // AES key register (MSB key               [127:96])
} KEYR3;
// initialization vector register           0
 struct {
      unsigned int AES_IVR0: 32; // initialization vector register (LSB IVR               [31:0])
} IVR0;
// initialization vector register           1
 struct {
      unsigned int AES_IVR1: 32; // Initialization Vector Register (IVR               [63:32])
} IVR1;
// initialization vector register           2
 struct {
      unsigned int AES_IVR2: 32; // Initialization Vector Register (IVR               [95:64])
} IVR2;
// initialization vector register           3
 struct {
      unsigned int AES_IVR3: 32; // Initialization Vector Register (MSB IVR               [127:96])
} IVR3;
} SVD_AES;
asm(".equ SVD_AES, 0x50060000");
