// Firewall
 extern struct {
// Code segment start address
 struct {
      unsigned int : 8; // Reserved
      unsigned int ADD: 16; // code segment start address
      unsigned int : 8; // Reserved
} CSSA;
// Code segment length
 struct {
      unsigned int : 8; // Reserved
      unsigned int LENG: 14; // code segment length
      unsigned int : 10; // Reserved
} CSL;
// Non-volatile data segment start           address
 struct {
      unsigned int : 8; // Reserved
      unsigned int ADD: 16; // Non-volatile data segment start               address
      unsigned int : 8; // Reserved
} NVDSSA;
// Non-volatile data segment           length
 struct {
      unsigned int : 8; // Reserved
      unsigned int LENG: 14; // Non-volatile data segment               length
      unsigned int : 10; // Reserved
} NVDSL;
// Volatile data segment start           address
 struct {
      unsigned int : 6; // Reserved
      unsigned int ADD: 10; // Volatile data segment start               address
      unsigned int : 16; // Reserved
} VDSSA;
// Volatile data segment length
 struct {
      unsigned int : 6; // Reserved
      unsigned int LENG: 10; // Non-volatile data segment               length
      unsigned int : 16; // Reserved
} VDSL;
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
// Configuration register
 struct {
      unsigned int FPA: 1; // Firewall pre alarm
      unsigned int VDS: 1; // Volatile data shared
      unsigned int VDE: 1; // Volatile data execution
      unsigned int : 29; // Reserved
} CR;
} SVD_FIREWALL;
asm(".equ SVD_FIREWALL, 0x40011c00");
