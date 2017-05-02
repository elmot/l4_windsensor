// Serial peripheral interface/Inter-IC       sound
 extern struct {
// control register 1
 struct {
      unsigned int CPHA: 1; // Clock phase
      unsigned int CPOL: 1; // Clock polarity
      unsigned int MSTR: 1; // Master selection
      unsigned int BR: 3; // Baud rate control
      unsigned int SPE: 1; // SPI enable
      unsigned int LSBFIRST: 1; // Frame format
      unsigned int SSI: 1; // Internal slave select
      unsigned int SSM: 1; // Software slave management
      unsigned int RXONLY: 1; // Receive only
      unsigned int DFF: 1; // Data frame format
      unsigned int CRCNEXT: 1; // CRC transfer next
      unsigned int CRCEN: 1; // Hardware CRC calculation               enable
      unsigned int BIDIOE: 1; // Output enable in bidirectional               mode
      unsigned int BIDIMODE: 1; // Bidirectional data mode               enable
      unsigned int : 16; // Reserved
} CR1;
// control register 2
 struct {
      unsigned int RXDMAEN: 1; // Rx buffer DMA enable
      unsigned int TXDMAEN: 1; // Tx buffer DMA enable
      unsigned int SSOE: 1; // SS output enable
      unsigned int NSSP: 1; // NSS pulse management
      unsigned int FRF: 1; // Frame format
      unsigned int ERRIE: 1; // Error interrupt enable
      unsigned int RXNEIE: 1; // RX buffer not empty interrupt               enable
      unsigned int TXEIE: 1; // Tx buffer empty interrupt               enable
      unsigned int DS: 4; // Data size
      unsigned int FRXTH: 1; // FIFO reception threshold
      unsigned int LDMA_RX: 1; // Last DMA transfer for               reception
      unsigned int LDMA_TX: 1; // Last DMA transfer for               transmission
      unsigned int : 17; // Reserved
} CR2;
// status register
 struct {
      unsigned int RXNE: 1; // Receive buffer not empty
      unsigned int TXE: 1; // Transmit buffer empty
      unsigned int : 2; // Reserved
      unsigned int CRCERR: 1; // CRC error flag
      unsigned int MODF: 1; // Mode fault
      unsigned int OVR: 1; // Overrun flag
      unsigned int BSY: 1; // Busy flag
      unsigned int TIFRFE: 1; // TI frame format error
      unsigned int FRLVL: 2; // FIFO reception level
      unsigned int FTLVL: 2; // FIFO transmission level
      unsigned int : 19; // Reserved
} SR;
// data register
 struct {
      unsigned int DR: 16; // Data register
      unsigned int : 16; // Reserved
} DR;
// CRC polynomial register
 struct {
      unsigned int CRCPOLY: 16; // CRC polynomial register
      unsigned int : 16; // Reserved
} CRCPR;
// RX CRC register
 struct {
      unsigned int RxCRC: 16; // Rx CRC register
      unsigned int : 16; // Reserved
} RXCRCR;
// TX CRC register
 struct {
      unsigned int TxCRC: 16; // Tx CRC register
      unsigned int : 16; // Reserved
} TXCRCR;
} SVD_SPI1;
asm(".equ SVD_SPI1, 0x40013000");
