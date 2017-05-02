// Flash
 extern struct {
// Access control register
 struct {
      unsigned int LATENCY: 3; // Latency
      unsigned int : 5; // Reserved
      unsigned int PRFTEN: 1; // Prefetch enable
      unsigned int ICEN: 1; // Instruction cache enable
      unsigned int DCEN: 1; // Data cache enable
      unsigned int ICRST: 1; // Instruction cache reset
      unsigned int DCRST: 1; // Data cache reset
      unsigned int RUN_PD: 1; // Flash Power-down mode during Low-power               run mode
      unsigned int SLEEP_PD: 1; // Flash Power-down mode during Low-power               sleep mode
      unsigned int : 17; // Reserved
} ACR;
// Power down key register
 struct {
      unsigned int PDKEYR: 32; // RUN_PD in FLASH_ACR key
} PDKEYR;
// Flash key register
 struct {
      unsigned int KEYR: 32; // KEYR
} KEYR;
// Option byte key register
 struct {
      unsigned int OPTKEYR: 32; // Option byte key
} OPTKEYR;
// Status register
 struct {
      unsigned int EOP: 1; // End of operation
      unsigned int OPERR: 1; // Operation error
      unsigned int : 1; // Reserved
      unsigned int PROGERR: 1; // Programming error
      unsigned int WRPERR: 1; // Write protected error
      unsigned int PGAERR: 1; // Programming alignment               error
      unsigned int SIZERR: 1; // Size error
      unsigned int PGSERR: 1; // Programming sequence error
      unsigned int MISERR: 1; // Fast programming data miss               error
      unsigned int FASTERR: 1; // Fast programming error
      unsigned int : 4; // Reserved
      unsigned int RDERR: 1; // PCROP read error
      unsigned int OPTVERR: 1; // Option validity error
      unsigned int BSY: 1; // Busy
      unsigned int : 15; // Reserved
} SR;
// Flash control register
 struct {
      unsigned int PG: 1; // Programming
      unsigned int PER: 1; // Page erase
      unsigned int MER1: 1; // Bank 1 Mass erase
      unsigned int PNB: 8; // Page number
      unsigned int BKER: 1; // Bank erase
      unsigned int : 3; // Reserved
      unsigned int MER2: 1; // Bank 2 Mass erase
      unsigned int START: 1; // Start
      unsigned int OPTSTRT: 1; // Options modification start
      unsigned int FSTPG: 1; // Fast programming
      unsigned int : 5; // Reserved
      unsigned int EOPIE: 1; // End of operation interrupt               enable
      unsigned int ERRIE: 1; // Error interrupt enable
      unsigned int RDERRIE: 1; // PCROP read error interrupt               enable
      unsigned int OBL_LAUNCH: 1; // Force the option byte               loading
      unsigned int : 2; // Reserved
      unsigned int OPTLOCK: 1; // Options Lock
      unsigned int LOCK: 1; // FLASH_CR Lock
} CR;
// Flash ECC register
 struct {
      unsigned int ADDR_ECC: 19; // ECC fail address
      unsigned int BK_ECC: 1; // ECC fail bank
      unsigned int SYSF_ECC: 1; // System Flash ECC fail
      unsigned int : 3; // Reserved
      unsigned int ECCIE: 1; // ECC correction interrupt               enable
      unsigned int : 5; // Reserved
      unsigned int ECCC: 1; // ECC correction
      unsigned int ECCD: 1; // ECC detection
} ECCR;
      unsigned int : 32; // Reserved
// Flash option register
 struct {
      unsigned int RDP: 8; // Read protection level
      unsigned int BOR_LEV: 3; // BOR reset Level
      unsigned int : 1; // Reserved
      unsigned int nRST_STOP: 1; // nRST_STOP
      unsigned int nRST_STDBY: 1; // nRST_STDBY
      unsigned int : 2; // Reserved
      unsigned int IDWG_SW: 1; // Independent watchdog               selection
      unsigned int IWDG_STOP: 1; // Independent watchdog counter freeze in               Stop mode
      unsigned int IWDG_STDBY: 1; // Independent watchdog counter freeze in               Standby mode
      unsigned int WWDG_SW: 1; // Window watchdog selection
      unsigned int BFB2: 1; // Dual-bank boot
      unsigned int DUALBANK: 1; // Dual-Bank on 512 KB or 256 KB Flash               memory devices
      unsigned int : 1; // Reserved
      unsigned int nBOOT1: 1; // Boot configuration
      unsigned int SRAM2_PE: 1; // SRAM2 parity check enable
      unsigned int SRAM2_RST: 1; // SRAM2 Erase when system               reset
      unsigned int : 6; // Reserved
} OPTR;
// Flash Bank 1 PCROP Start address           register
 struct {
      unsigned int PCROP1_STRT: 16; // Bank 1 PCROP area start               offset
      unsigned int : 16; // Reserved
} PCROP1SR;
// Flash Bank 1 PCROP End address           register
 struct {
      unsigned int PCROP1_END: 16; // Bank 1 PCROP area end               offset
      unsigned int : 15; // Reserved
      unsigned int PCROP_RDP: 1; // PCROP area preserved when RDP level               decreased
} PCROP1ER;
// Flash Bank 1 WRP area A address           register
 struct {
      unsigned int WRP1A_STRT: 8; // Bank 1 WRP first area               ???????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????A????????????????????????????????????????????????????????????????????????????????????????????????????????????????               start offset
      unsigned int : 8; // Reserved
      unsigned int WRP1A_END: 8; // Bank 1 WRP first area A end               offset
      unsigned int : 8; // Reserved
} WRP1AR;
// Flash Bank 1 WRP area B address           register
 struct {
      unsigned int WRP1B_END: 8; // Bank 1 WRP second area B start               offset
      unsigned int : 8; // Reserved
      unsigned int WRP1B_STRT: 8; // Bank 1 WRP second area B end               offset
      unsigned int : 8; // Reserved
} WRP1BR;
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
      unsigned int : 32; // Reserved
// Flash Bank 2 PCROP Start address           register
 struct {
      unsigned int PCROP2_STRT: 16; // Bank 2 PCROP area start               offset
      unsigned int : 16; // Reserved
} PCROP2SR;
// Flash Bank 2 PCROP End address           register
 struct {
      unsigned int PCROP2_END: 16; // Bank 2 PCROP area end               offset
      unsigned int : 16; // Reserved
} PCROP2ER;
// Flash Bank 2 WRP area A address           register
 struct {
      unsigned int WRP2A_STRT: 8; // Bank 2 WRP first area A start               offset
      unsigned int : 8; // Reserved
      unsigned int WRP2A_END: 8; // Bank 2 WRP first area A end               offset
      unsigned int : 8; // Reserved
} WRP2AR;
// Flash Bank 2 WRP area B address           register
 struct {
      unsigned int WRP2B_STRT: 8; // Bank 2 WRP second area B start               offset
      unsigned int : 8; // Reserved
      unsigned int WRP2B_END: 8; // Bank 2 WRP second area B end               offset
      unsigned int : 8; // Reserved
} WRP2BR;
} SVD_FLASH;
asm(".equ SVD_FLASH, 0x40022000");
