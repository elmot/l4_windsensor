// Universal synchronous asynchronous receiver       transmitter
 extern struct {
// Control register 1
 struct {
      unsigned int UE: 1; // USART enable
      unsigned int UESM: 1; // USART enable in Stop mode
      unsigned int RE: 1; // Receiver enable
      unsigned int TE: 1; // Transmitter enable
      unsigned int IDLEIE: 1; // IDLE interrupt enable
      unsigned int RXNEIE: 1; // RXNE interrupt enable
      unsigned int TCIE: 1; // Transmission complete interrupt               enable
      unsigned int TXEIE: 1; // interrupt enable
      unsigned int PEIE: 1; // PE interrupt enable
      unsigned int PS: 1; // Parity selection
      unsigned int PCE: 1; // Parity control enable
      unsigned int WAKE: 1; // Receiver wakeup method
      unsigned int M0: 1; // Word length
      unsigned int MME: 1; // Mute mode enable
      unsigned int CMIE: 1; // Character match interrupt               enable
      unsigned int : 1; // Reserved
      unsigned int DEDT0: 1; // DEDT0
      unsigned int DEDT1: 1; // DEDT1
      unsigned int DEDT2: 1; // DEDT2
      unsigned int DEDT3: 1; // DEDT3
      unsigned int DEDT4: 1; // Driver Enable de-assertion               time
      unsigned int DEAT0: 1; // DEAT0
      unsigned int DEAT1: 1; // DEAT1
      unsigned int DEAT2: 1; // DEAT2
      unsigned int DEAT3: 1; // DEAT3
      unsigned int DEAT4: 1; // Driver Enable assertion               time
      unsigned int : 2; // Reserved
      unsigned int M1: 1; // Word length
      unsigned int : 3; // Reserved
} CR1;
// Control register 2
 struct {
      unsigned int : 4; // Reserved
      unsigned int ADDM7: 1; // 7-bit Address Detection/4-bit Address               Detection
      unsigned int : 6; // Reserved
      unsigned int CLKEN: 1; // Clock enable
      unsigned int STOP: 2; // STOP bits
      unsigned int : 1; // Reserved
      unsigned int SWAP: 1; // Swap TX/RX pins
      unsigned int RXINV: 1; // RX pin active level               inversion
      unsigned int TXINV: 1; // TX pin active level               inversion
      unsigned int TAINV: 1; // Binary data inversion
      unsigned int MSBFIRST: 1; // Most significant bit first
      unsigned int : 4; // Reserved
      unsigned int ADD0_3: 4; // Address of the USART node
      unsigned int ADD4_7: 4; // Address of the USART node
} CR2;
// Control register 3
 struct {
      unsigned int EIE: 1; // Error interrupt enable
      unsigned int : 2; // Reserved
      unsigned int HDSEL: 1; // Half-duplex selection
      unsigned int : 2; // Reserved
      unsigned int DMAR: 1; // DMA enable receiver
      unsigned int DMAT: 1; // DMA enable transmitter
      unsigned int RTSE: 1; // RTS enable
      unsigned int CTSE: 1; // CTS enable
      unsigned int CTSIE: 1; // CTS interrupt enable
      unsigned int : 1; // Reserved
      unsigned int OVRDIS: 1; // Overrun Disable
      unsigned int DDRE: 1; // DMA Disable on Reception               Error
      unsigned int DEM: 1; // Driver enable mode
      unsigned int DEP: 1; // Driver enable polarity               selection
      unsigned int : 4; // Reserved
      unsigned int WUS: 2; // Wakeup from Stop mode interrupt flag               selection
      unsigned int WUFIE: 1; // Wakeup from Stop mode interrupt               enable
      unsigned int : 9; // Reserved
} CR3;
// Baud rate register
 struct {
      unsigned int BRR: 20; // BRR
      unsigned int : 12; // Reserved
} BRR;
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
// Request register
 struct {
      unsigned int : 1; // Reserved
      unsigned int SBKRQ: 1; // Send break request
      unsigned int MMRQ: 1; // Mute mode request
      unsigned int RXFRQ: 1; // Receive data flush request
      unsigned int : 28; // Reserved
} RQR;
// Interrupt & status           register
 struct {
      unsigned int PE: 1; // PE
      unsigned int FE: 1; // FE
      unsigned int NF: 1; // NF
      unsigned int ORE: 1; // ORE
      unsigned int IDLE: 1; // IDLE
      unsigned int RXNE: 1; // RXNE
      unsigned int TC: 1; // TC
      unsigned int TXE: 1; // TXE
      unsigned int : 1; // Reserved
      unsigned int CTSIF: 1; // CTSIF
      unsigned int CTS: 1; // CTS
      unsigned int : 5; // Reserved
      unsigned int BUSY: 1; // BUSY
      unsigned int CMF: 1; // CMF
      unsigned int SBKF: 1; // SBKF
      unsigned int RWU: 1; // RWU
      unsigned int WUF: 1; // WUF
      unsigned int TEACK: 1; // TEACK
      unsigned int REACK: 1; // REACK
      unsigned int : 9; // Reserved
} ISR;
// Interrupt flag clear register
 struct {
      unsigned int PECF: 1; // Parity error clear flag
      unsigned int FECF: 1; // Framing error clear flag
      unsigned int NCF: 1; // Noise detected clear flag
      unsigned int ORECF: 1; // Overrun error clear flag
      unsigned int IDLECF: 1; // Idle line detected clear               flag
      unsigned int : 1; // Reserved
      unsigned int TCCF: 1; // Transmission complete clear               flag
      unsigned int : 2; // Reserved
      unsigned int CTSCF: 1; // CTS clear flag
      unsigned int : 7; // Reserved
      unsigned int CMCF: 1; // Character match clear flag
      unsigned int : 2; // Reserved
      unsigned int WUCF: 1; // Wakeup from Stop mode clear               flag
      unsigned int : 11; // Reserved
} ICR;
// Receive data register
 struct {
      unsigned int RDR: 9; // Receive data value
      unsigned int : 23; // Reserved
} RDR;
// Transmit data register
 struct {
      unsigned int TDR: 9; // Transmit data value
      unsigned int : 23; // Reserved
} TDR;
} SVD_LPUART1;
asm(".equ SVD_LPUART1, 0x40008000");
