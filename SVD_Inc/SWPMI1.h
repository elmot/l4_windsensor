// Single Wire Protocol Master       Interface
 extern struct {
// SWPMI Configuration/Control           register
 struct {
      unsigned int RXDMA: 1; // Reception DMA enable
      unsigned int TXDMA: 1; // Transmission DMA enable
      unsigned int RXMODE: 1; // Reception buffering mode
      unsigned int TXMODE: 1; // Transmission buffering               mode
      unsigned int LPBK: 1; // Loopback mode enable
      unsigned int SWPME: 1; // Single wire protocol master interface               enable
      unsigned int : 4; // Reserved
      unsigned int DEACT: 1; // Single wire protocol master interface               deactivate
      unsigned int : 21; // Reserved
} CR;
// SWPMI Bitrate register
 struct {
      unsigned int BR: 6; // Bitrate prescaler
      unsigned int : 26; // Reserved
} BRR;
      unsigned int : 32; // Reserved
// SWPMI Interrupt and Status           register
 struct {
      unsigned int RXBFF: 1; // Receive buffer full flag
      unsigned int TXBEF: 1; // Transmit buffer empty flag
      unsigned int RXBERF: 1; // Receive CRC error flag
      unsigned int RXOVRF: 1; // Receive overrun error flag
      unsigned int TXUNRF: 1; // Transmit underrun error               flag
      unsigned int RXNE: 1; // Receive data register not               empty
      unsigned int TXE: 1; // Transmit data register               empty
      unsigned int TCF: 1; // Transfer complete flag
      unsigned int SRF: 1; // Slave resume flag
      unsigned int SUSP: 1; // SUSPEND flag
      unsigned int DEACTF: 1; // DEACTIVATED flag
      unsigned int : 21; // Reserved
} ISR;
// SWPMI Interrupt Flag Clear           register
 struct {
      unsigned int CRXBFF: 1; // Clear receive buffer full               flag
      unsigned int CTXBEF: 1; // Clear transmit buffer empty               flag
      unsigned int CRXBERF: 1; // Clear receive CRC error               flag
      unsigned int CRXOVRF: 1; // Clear receive overrun error               flag
      unsigned int CTXUNRF: 1; // Clear transmit underrun error               flag
      unsigned int : 2; // Reserved
      unsigned int CTCF: 1; // Clear transfer complete               flag
      unsigned int CSRF: 1; // Clear slave resume flag
      unsigned int : 23; // Reserved
} ICR;
// SWPMI Interrupt Enable           register
 struct {
      unsigned int RXBFIE: 1; // Receive buffer full interrupt               enable
      unsigned int TXBEIE: 1; // Transmit buffer empty interrupt               enable
      unsigned int RXBERIE: 1; // Receive CRC error interrupt               enable
      unsigned int RXOVRIE: 1; // Receive overrun error interrupt               enable
      unsigned int TXUNRIE: 1; // Transmit underrun error interrupt               enable
      unsigned int RIE: 1; // Receive interrupt enable
      unsigned int TIE: 1; // Transmit interrupt enable
      unsigned int TCIE: 1; // Transmit complete interrupt               enable
      unsigned int SRIE: 1; // Slave resume interrupt               enable
      unsigned int : 23; // Reserved
} IER;
// SWPMI Receive Frame Length           register
 struct {
      unsigned int RFL: 5; // Receive frame length
      unsigned int : 27; // Reserved
} RFL;
// SWPMI Transmit data register
 struct {
      unsigned int TD: 32; // Transmit data
} TDR;
// SWPMI Receive data register
 struct {
      unsigned int RD: 32; // received data
} RDR;
} SVD_SWPMI1;
asm(".equ SVD_SWPMI1, 0x40008800");
