// Direct memory access controller
 extern struct {
// interrupt status register
 struct {
      unsigned int GIF1: 1; // Channel x global interrupt flag (x = 1               ..7)
      unsigned int TCIF1: 1; // Channel x transfer complete flag (x = 1               ..7)
      unsigned int HTIF1: 1; // Channel x half transfer flag (x = 1               ..7)
      unsigned int TEIF1: 1; // Channel x transfer error flag (x = 1               ..7)
      unsigned int GIF2: 1; // Channel x global interrupt flag (x = 1               ..7)
      unsigned int TCIF2: 1; // Channel x transfer complete flag (x = 1               ..7)
      unsigned int HTIF2: 1; // Channel x half transfer flag (x = 1               ..7)
      unsigned int TEIF2: 1; // Channel x transfer error flag (x = 1               ..7)
      unsigned int GIF3: 1; // Channel x global interrupt flag (x = 1               ..7)
      unsigned int TCIF3: 1; // Channel x transfer complete flag (x = 1               ..7)
      unsigned int HTIF3: 1; // Channel x half transfer flag (x = 1               ..7)
      unsigned int TEIF3: 1; // Channel x transfer error flag (x = 1               ..7)
      unsigned int GIF4: 1; // Channel x global interrupt flag (x = 1               ..7)
      unsigned int TCIF4: 1; // Channel x transfer complete flag (x = 1               ..7)
      unsigned int HTIF4: 1; // Channel x half transfer flag (x = 1               ..7)
      unsigned int TEIF4: 1; // Channel x transfer error flag (x = 1               ..7)
      unsigned int GIF5: 1; // Channel x global interrupt flag (x = 1               ..7)
      unsigned int TCIF5: 1; // Channel x transfer complete flag (x = 1               ..7)
      unsigned int HTIF5: 1; // Channel x half transfer flag (x = 1               ..7)
      unsigned int TEIF5: 1; // Channel x transfer error flag (x = 1               ..7)
      unsigned int GIF6: 1; // Channel x global interrupt flag (x = 1               ..7)
      unsigned int TCIF6: 1; // Channel x transfer complete flag (x = 1               ..7)
      unsigned int HTIF6: 1; // Channel x half transfer flag (x = 1               ..7)
      unsigned int TEIF6: 1; // Channel x transfer error flag (x = 1               ..7)
      unsigned int GIF7: 1; // Channel x global interrupt flag (x = 1               ..7)
      unsigned int TCIF7: 1; // Channel x transfer complete flag (x = 1               ..7)
      unsigned int HTIF7: 1; // Channel x half transfer flag (x = 1               ..7)
      unsigned int TEIF7: 1; // Channel x transfer error flag (x = 1               ..7)
      unsigned int : 4; // Reserved
} ISR;
// interrupt flag clear register
 struct {
      unsigned int CGIF1: 1; // Channel x global interrupt clear (x = 1               ..7)
      unsigned int CTCIF1: 1; // Channel x transfer complete clear (x = 1               ..7)
      unsigned int CHTIF1: 1; // Channel x half transfer clear (x = 1               ..7)
      unsigned int CTEIF1: 1; // Channel x transfer error clear (x = 1               ..7)
      unsigned int CGIF2: 1; // Channel x global interrupt clear (x = 1               ..7)
      unsigned int CTCIF2: 1; // Channel x transfer complete clear (x = 1               ..7)
      unsigned int CHTIF2: 1; // Channel x half transfer clear (x = 1               ..7)
      unsigned int CTEIF2: 1; // Channel x transfer error clear (x = 1               ..7)
      unsigned int CGIF3: 1; // Channel x global interrupt clear (x = 1               ..7)
      unsigned int CTCIF3: 1; // Channel x transfer complete clear (x = 1               ..7)
      unsigned int CHTIF3: 1; // Channel x half transfer clear (x = 1               ..7)
      unsigned int CTEIF3: 1; // Channel x transfer error clear (x = 1               ..7)
      unsigned int CGIF4: 1; // Channel x global interrupt clear (x = 1               ..7)
      unsigned int CTCIF4: 1; // Channel x transfer complete clear (x = 1               ..7)
      unsigned int CHTIF4: 1; // Channel x half transfer clear (x = 1               ..7)
      unsigned int CTEIF4: 1; // Channel x transfer error clear (x = 1               ..7)
      unsigned int CGIF5: 1; // Channel x global interrupt clear (x = 1               ..7)
      unsigned int CTCIF5: 1; // Channel x transfer complete clear (x = 1               ..7)
      unsigned int CHTIF5: 1; // Channel x half transfer clear (x = 1               ..7)
      unsigned int CTEIF5: 1; // Channel x transfer error clear (x = 1               ..7)
      unsigned int CGIF6: 1; // Channel x global interrupt clear (x = 1               ..7)
      unsigned int CTCIF6: 1; // Channel x transfer complete clear (x = 1               ..7)
      unsigned int CHTIF6: 1; // Channel x half transfer clear (x = 1               ..7)
      unsigned int CTEIF6: 1; // Channel x transfer error clear (x = 1               ..7)
      unsigned int CGIF7: 1; // Channel x global interrupt clear (x = 1               ..7)
      unsigned int CTCIF7: 1; // Channel x transfer complete clear (x = 1               ..7)
      unsigned int CHTIF7: 1; // Channel x half transfer clear (x = 1               ..7)
      unsigned int CTEIF7: 1; // Channel x transfer error clear (x = 1               ..7)
      unsigned int : 4; // Reserved
} IFCR;
// channel x configuration           register
 struct {
      unsigned int EN: 1; // Channel enable
      unsigned int TCIE: 1; // Transfer complete interrupt               enable
      unsigned int HTIE: 1; // Half transfer interrupt               enable
      unsigned int TEIE: 1; // Transfer error interrupt               enable
      unsigned int DIR: 1; // Data transfer direction
      unsigned int CIRC: 1; // Circular mode
      unsigned int PINC: 1; // Peripheral increment mode
      unsigned int MINC: 1; // Memory increment mode
      unsigned int PSIZE: 2; // Peripheral size
      unsigned int MSIZE: 2; // Memory size
      unsigned int PL: 2; // Channel priority level
      unsigned int MEM2MEM: 1; // Memory to memory mode
      unsigned int : 17; // Reserved
} CCR1;
// channel x number of data           register
 struct {
      unsigned int NDT: 16; // Number of data to transfer
      unsigned int : 16; // Reserved
} CNDTR1;
// channel x peripheral address           register
 struct {
      unsigned int PA: 32; // Peripheral address
} CPAR1;
// channel x memory address           register
 struct {
      unsigned int MA: 32; // Memory address
} CMAR1;
      unsigned int : 32; // Reserved
// channel x configuration           register
 struct {
      unsigned int EN: 1; // Channel enable
      unsigned int TCIE: 1; // Transfer complete interrupt               enable
      unsigned int HTIE: 1; // Half transfer interrupt               enable
      unsigned int TEIE: 1; // Transfer error interrupt               enable
      unsigned int DIR: 1; // Data transfer direction
      unsigned int CIRC: 1; // Circular mode
      unsigned int PINC: 1; // Peripheral increment mode
      unsigned int MINC: 1; // Memory increment mode
      unsigned int PSIZE: 2; // Peripheral size
      unsigned int MSIZE: 2; // Memory size
      unsigned int PL: 2; // Channel priority level
      unsigned int MEM2MEM: 1; // Memory to memory mode
      unsigned int : 17; // Reserved
} CCR2;
// channel x number of data           register
 struct {
      unsigned int NDT: 16; // Number of data to transfer
      unsigned int : 16; // Reserved
} CNDTR2;
// channel x peripheral address           register
 struct {
      unsigned int PA: 32; // Peripheral address
} CPAR2;
// channel x memory address           register
 struct {
      unsigned int MA: 32; // Memory address
} CMAR2;
      unsigned int : 32; // Reserved
// channel x configuration           register
 struct {
      unsigned int EN: 1; // Channel enable
      unsigned int TCIE: 1; // Transfer complete interrupt               enable
      unsigned int HTIE: 1; // Half transfer interrupt               enable
      unsigned int TEIE: 1; // Transfer error interrupt               enable
      unsigned int DIR: 1; // Data transfer direction
      unsigned int CIRC: 1; // Circular mode
      unsigned int PINC: 1; // Peripheral increment mode
      unsigned int MINC: 1; // Memory increment mode
      unsigned int PSIZE: 2; // Peripheral size
      unsigned int MSIZE: 2; // Memory size
      unsigned int PL: 2; // Channel priority level
      unsigned int MEM2MEM: 1; // Memory to memory mode
      unsigned int : 17; // Reserved
} CCR3;
// channel x number of data           register
 struct {
      unsigned int NDT: 16; // Number of data to transfer
      unsigned int : 16; // Reserved
} CNDTR3;
// channel x peripheral address           register
 struct {
      unsigned int PA: 32; // Peripheral address
} CPAR3;
// channel x memory address           register
 struct {
      unsigned int MA: 32; // Memory address
} CMAR3;
      unsigned int : 32; // Reserved
// channel x configuration           register
 struct {
      unsigned int EN: 1; // Channel enable
      unsigned int TCIE: 1; // Transfer complete interrupt               enable
      unsigned int HTIE: 1; // Half transfer interrupt               enable
      unsigned int TEIE: 1; // Transfer error interrupt               enable
      unsigned int DIR: 1; // Data transfer direction
      unsigned int CIRC: 1; // Circular mode
      unsigned int PINC: 1; // Peripheral increment mode
      unsigned int MINC: 1; // Memory increment mode
      unsigned int PSIZE: 2; // Peripheral size
      unsigned int MSIZE: 2; // Memory size
      unsigned int PL: 2; // Channel priority level
      unsigned int MEM2MEM: 1; // Memory to memory mode
      unsigned int : 17; // Reserved
} CCR4;
// channel x number of data           register
 struct {
      unsigned int NDT: 16; // Number of data to transfer
      unsigned int : 16; // Reserved
} CNDTR4;
// channel x peripheral address           register
 struct {
      unsigned int PA: 32; // Peripheral address
} CPAR4;
// channel x memory address           register
 struct {
      unsigned int MA: 32; // Memory address
} CMAR4;
      unsigned int : 32; // Reserved
// channel x configuration           register
 struct {
      unsigned int EN: 1; // Channel enable
      unsigned int TCIE: 1; // Transfer complete interrupt               enable
      unsigned int HTIE: 1; // Half transfer interrupt               enable
      unsigned int TEIE: 1; // Transfer error interrupt               enable
      unsigned int DIR: 1; // Data transfer direction
      unsigned int CIRC: 1; // Circular mode
      unsigned int PINC: 1; // Peripheral increment mode
      unsigned int MINC: 1; // Memory increment mode
      unsigned int PSIZE: 2; // Peripheral size
      unsigned int MSIZE: 2; // Memory size
      unsigned int PL: 2; // Channel priority level
      unsigned int MEM2MEM: 1; // Memory to memory mode
      unsigned int : 17; // Reserved
} CCR5;
// channel x number of data           register
 struct {
      unsigned int NDT: 16; // Number of data to transfer
      unsigned int : 16; // Reserved
} CNDTR5;
// channel x peripheral address           register
 struct {
      unsigned int PA: 32; // Peripheral address
} CPAR5;
// channel x memory address           register
 struct {
      unsigned int MA: 32; // Memory address
} CMAR5;
      unsigned int : 32; // Reserved
// channel x configuration           register
 struct {
      unsigned int EN: 1; // Channel enable
      unsigned int TCIE: 1; // Transfer complete interrupt               enable
      unsigned int HTIE: 1; // Half transfer interrupt               enable
      unsigned int TEIE: 1; // Transfer error interrupt               enable
      unsigned int DIR: 1; // Data transfer direction
      unsigned int CIRC: 1; // Circular mode
      unsigned int PINC: 1; // Peripheral increment mode
      unsigned int MINC: 1; // Memory increment mode
      unsigned int PSIZE: 2; // Peripheral size
      unsigned int MSIZE: 2; // Memory size
      unsigned int PL: 2; // Channel priority level
      unsigned int MEM2MEM: 1; // Memory to memory mode
      unsigned int : 17; // Reserved
} CCR6;
// channel x number of data           register
 struct {
      unsigned int NDT: 16; // Number of data to transfer
      unsigned int : 16; // Reserved
} CNDTR6;
// channel x peripheral address           register
 struct {
      unsigned int PA: 32; // Peripheral address
} CPAR6;
// channel x memory address           register
 struct {
      unsigned int MA: 32; // Memory address
} CMAR6;
      unsigned int : 32; // Reserved
// channel x configuration           register
 struct {
      unsigned int EN: 1; // Channel enable
      unsigned int TCIE: 1; // Transfer complete interrupt               enable
      unsigned int HTIE: 1; // Half transfer interrupt               enable
      unsigned int TEIE: 1; // Transfer error interrupt               enable
      unsigned int DIR: 1; // Data transfer direction
      unsigned int CIRC: 1; // Circular mode
      unsigned int PINC: 1; // Peripheral increment mode
      unsigned int MINC: 1; // Memory increment mode
      unsigned int PSIZE: 2; // Peripheral size
      unsigned int MSIZE: 2; // Memory size
      unsigned int PL: 2; // Channel priority level
      unsigned int MEM2MEM: 1; // Memory to memory mode
      unsigned int : 17; // Reserved
} CCR7;
// channel x number of data           register
 struct {
      unsigned int NDT: 16; // Number of data to transfer
      unsigned int : 16; // Reserved
} CNDTR7;
// channel x peripheral address           register
 struct {
      unsigned int PA: 32; // Peripheral address
} CPAR7;
// channel x memory address           register
 struct {
      unsigned int MA: 32; // Memory address
} CMAR7;
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
// channel selection register
 struct {
      unsigned int C1S: 4; // DMA channel 1 selection
      unsigned int C2S: 4; // DMA channel 2 selection
      unsigned int C3S: 4; // DMA channel 3 selection
      unsigned int C4S: 4; // DMA channel 4 selection
      unsigned int C5S: 4; // DMA channel 5 selection
      unsigned int C6S: 4; // DMA channel 6 selection
      unsigned int C7S: 4; // DMA channel 7 selection
      unsigned int : 4; // Reserved
} CSELR;
} SVD_DMA2;
asm(".equ SVD_DMA2, 0x40020400");
