// Secure digital input/output       interface
 extern struct {
// power control register
 struct {
      unsigned int PWRCTRL: 2; // PWRCTRL
      unsigned int : 30; // Reserved
} POWER;
// SDI clock control register
 struct {
      unsigned int CLKDIV: 8; // Clock divide factor
      unsigned int CLKEN: 1; // Clock enable bit
      unsigned int PWRSAV: 1; // Power saving configuration               bit
      unsigned int BYPASS: 1; // Clock divider bypass enable               bit
      unsigned int WIDBUS: 2; // Wide bus mode enable bit
      unsigned int NEGEDGE: 1; // SDIO_CK dephasing selection               bit
      unsigned int HWFC_EN: 1; // HW Flow Control enable
      unsigned int : 17; // Reserved
} CLKCR;
// argument register
 struct {
      unsigned int CMDARG: 32; // Command argument
} ARG;
// command register
 struct {
      unsigned int CMDINDEX: 6; // Command index
      unsigned int WAITRESP: 2; // Wait for response bits
      unsigned int WAITINT: 1; // CPSM waits for interrupt               request
      unsigned int WAITPEND: 1; // CPSM Waits for ends of data transfer               (CmdPend internal signal)
      unsigned int CPSMEN: 1; // Command path state machine (CPSM) Enable               bit
      unsigned int SDIOSuspend: 1; // SD I/O suspend command
      unsigned int ENCMDcompl: 1; // Enable CMD completion
      unsigned int nIEN: 1; // not Interrupt Enable
      unsigned int CE_ATACMD: 1; // CE-ATA command
      unsigned int : 17; // Reserved
} CMD;
// command response register
 struct {
      unsigned int RESPCMD: 6; // Response command index
      unsigned int : 26; // Reserved
} RESPCMD;
// response 1..4 register
 struct {
      unsigned int CARDSTATUS1: 32; // see Table 132
} RESP1;
// response 1..4 register
 struct {
      unsigned int CARDSTATUS2: 32; // see Table 132
} RESP2;
// response 1..4 register
 struct {
      unsigned int CARDSTATUS3: 32; // see Table 132
} RESP3;
// response 1..4 register
 struct {
      unsigned int CARDSTATUS4: 32; // see Table 132
} RESP4;
// data timer register
 struct {
      unsigned int DATATIME: 32; // Data timeout period
} DTIMER;
// data length register
 struct {
      unsigned int DATALENGTH: 25; // Data length value
      unsigned int : 7; // Reserved
} DLEN;
// data control register
 struct {
      unsigned int DTEN: 1; // DTEN
      unsigned int DTDIR: 1; // Data transfer direction               selection
      unsigned int DTMODE: 1; // Data transfer mode selection 1: Stream               or SDIO multibyte data transfer
      unsigned int DMAEN: 1; // DMA enable bit
      unsigned int DBLOCKSIZE: 4; // Data block size
      unsigned int RWSTART: 1; // Read wait start
      unsigned int RWSTOP: 1; // Read wait stop
      unsigned int RWMOD: 1; // Read wait mode
      unsigned int SDIOEN: 1; // SD I/O enable functions
      unsigned int : 20; // Reserved
} DCTRL;
// data counter register
 struct {
      unsigned int DATACOUNT: 25; // Data count value
      unsigned int : 7; // Reserved
} DCOUNT;
// status register
 struct {
      unsigned int CCRCFAIL: 1; // Command response received (CRC check               failed)
      unsigned int DCRCFAIL: 1; // Data block sent/received (CRC check               failed)
      unsigned int CTIMEOUT: 1; // Command response timeout
      unsigned int DTIMEOUT: 1; // Data timeout
      unsigned int TXUNDERR: 1; // Transmit FIFO underrun               error
      unsigned int RXOVERR: 1; // Received FIFO overrun               error
      unsigned int CMDREND: 1; // Command response received (CRC check               passed)
      unsigned int CMDSENT: 1; // Command sent (no response               required)
      unsigned int DATAEND: 1; // Data end (data counter, SDIDCOUNT, is               zero)
      unsigned int STBITERR: 1; // Start bit not detected on all data               signals in wide bus mode
      unsigned int DBCKEND: 1; // Data block sent/received (CRC check               passed)
      unsigned int CMDACT: 1; // Command transfer in               progress
      unsigned int TXACT: 1; // Data transmit in progress
      unsigned int RXACT: 1; // Data receive in progress
      unsigned int TXFIFOHE: 1; // Transmit FIFO half empty: at least 8               words can be written into the FIFO
      unsigned int RXFIFOHF: 1; // Receive FIFO half full: there are at               least 8 words in the FIFO
      unsigned int TXFIFOF: 1; // Transmit FIFO full
      unsigned int RXFIFOF: 1; // Receive FIFO full
      unsigned int TXFIFOE: 1; // Transmit FIFO empty
      unsigned int RXFIFOE: 1; // Receive FIFO empty
      unsigned int TXDAVL: 1; // Data available in transmit               FIFO
      unsigned int RXDAVL: 1; // Data available in receive               FIFO
      unsigned int SDIOIT: 1; // SDIO interrupt received
      unsigned int CEATAEND: 1; // CE-ATA command completion signal               received for CMD61
      unsigned int : 8; // Reserved
} STA;
// interrupt clear register
 struct {
      unsigned int CCRCFAILC: 1; // CCRCFAIL flag clear bit
      unsigned int DCRCFAILC: 1; // DCRCFAIL flag clear bit
      unsigned int CTIMEOUTC: 1; // CTIMEOUT flag clear bit
      unsigned int DTIMEOUTC: 1; // DTIMEOUT flag clear bit
      unsigned int TXUNDERRC: 1; // TXUNDERR flag clear bit
      unsigned int RXOVERRC: 1; // RXOVERR flag clear bit
      unsigned int CMDRENDC: 1; // CMDREND flag clear bit
      unsigned int CMDSENTC: 1; // CMDSENT flag clear bit
      unsigned int DATAENDC: 1; // DATAEND flag clear bit
      unsigned int STBITERRC: 1; // STBITERR flag clear bit
      unsigned int DBCKENDC: 1; // DBCKEND flag clear bit
      unsigned int : 11; // Reserved
      unsigned int SDIOITC: 1; // SDIOIT flag clear bit
      unsigned int CEATAENDC: 1; // CEATAEND flag clear bit
      unsigned int : 8; // Reserved
} ICR;
// mask register
 struct {
      unsigned int CCRCFAILIE: 1; // Command CRC fail interrupt               enable
      unsigned int DCRCFAILIE: 1; // Data CRC fail interrupt               enable
      unsigned int CTIMEOUTIE: 1; // Command timeout interrupt               enable
      unsigned int DTIMEOUTIE: 1; // Data timeout interrupt               enable
      unsigned int TXUNDERRIE: 1; // Tx FIFO underrun error interrupt               enable
      unsigned int RXOVERRIE: 1; // Rx FIFO overrun error interrupt               enable
      unsigned int CMDRENDIE: 1; // Command response received interrupt               enable
      unsigned int CMDSENTIE: 1; // Command sent interrupt               enable
      unsigned int DATAENDIE: 1; // Data end interrupt enable
      unsigned int STBITERRIE: 1; // Start bit error interrupt               enable
      unsigned int DBCKENDIE: 1; // Data block end interrupt               enable
      unsigned int CMDACTIE: 1; // Command acting interrupt               enable
      unsigned int TXACTIE: 1; // Data transmit acting interrupt               enable
      unsigned int RXACTIE: 1; // Data receive acting interrupt               enable
      unsigned int TXFIFOHEIE: 1; // Tx FIFO half empty interrupt               enable
      unsigned int RXFIFOHFIE: 1; // Rx FIFO half full interrupt               enable
      unsigned int TXFIFOFIE: 1; // Tx FIFO full interrupt               enable
      unsigned int RXFIFOFIE: 1; // Rx FIFO full interrupt               enable
      unsigned int TXFIFOEIE: 1; // Tx FIFO empty interrupt               enable
      unsigned int RXFIFOEIE: 1; // Rx FIFO empty interrupt               enable
      unsigned int TXDAVLIE: 1; // Data available in Tx FIFO interrupt               enable
      unsigned int RXDAVLIE: 1; // Data available in Rx FIFO interrupt               enable
      unsigned int SDIOITIE: 1; // SDIO mode interrupt received interrupt               enable
      unsigned int CEATAENDIE: 1; // CE-ATA command completion signal               received interrupt enable
      unsigned int : 8; // Reserved
} MASK;
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
// FIFO counter register
 struct {
      unsigned int FIFOCOUNT: 24; // Remaining number of words to be written               to or read from the FIFO
      unsigned int : 8; // Reserved
} FIFOCNT;
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
// data FIFO register
 struct {
      unsigned int FIFOData: 32; // Receive and transmit FIFO               data
} FIFO;
} SVD_SDMMC;
asm(".equ SVD_SDMMC, 0x40012800");
