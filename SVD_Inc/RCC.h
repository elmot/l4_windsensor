// Reset and clock control
 extern struct {
// Clock control register
 struct {
      unsigned int MSION: 1; // MSI clock enable
      unsigned int MSIRDY: 1; // MSI clock ready flag
      unsigned int MSIPLLEN: 1; // MSI clock PLL enable
      unsigned int MSIRGSEL: 1; // MSI clock range selection
      unsigned int MSIRANGE: 4; // MSI clock ranges
      unsigned int HSION: 1; // HSI clock enable
      unsigned int HSIKERON: 1; // HSI always enable for peripheral               kernels
      unsigned int HSIRDY: 1; // HSI clock ready flag
      unsigned int HSIASFS: 1; // HSI automatic start from               Stop
      unsigned int : 4; // Reserved
      unsigned int HSEON: 1; // HSE clock enable
      unsigned int HSERDY: 1; // HSE clock ready flag
      unsigned int HSEBYP: 1; // HSE crystal oscillator               bypass
      unsigned int CSSON: 1; // Clock security system               enable
      unsigned int : 4; // Reserved
      unsigned int PLLON: 1; // Main PLL enable
      unsigned int PLLRDY: 1; // Main PLL clock ready flag
      unsigned int PLLSAI1ON: 1; // SAI1 PLL enable
      unsigned int PLLSAI1RDY: 1; // SAI1 PLL clock ready flag
      unsigned int : 4; // Reserved
} CR;
// Internal clock sources calibration           register
 struct {
      unsigned int MSICAL: 8; // MSI clock calibration
      unsigned int MSITRIM: 8; // MSI clock trimming
      unsigned int HSICAL: 8; // HSI clock calibration
      unsigned int HSITRIM: 5; // HSI clock trimming
      unsigned int : 3; // Reserved
} ICSCR;
// Clock configuration register
 struct {
      unsigned int SW: 2; // System clock switch
      unsigned int SWS: 2; // System clock switch status
      unsigned int HPRE: 4; // AHB prescaler
      unsigned int PPRE1: 3; // PB low-speed prescaler               (APB1)
      unsigned int PPRE2: 3; // APB high-speed prescaler               (APB2)
      unsigned int : 1; // Reserved
      unsigned int STOPWUCK: 1; // Wakeup from Stop and CSS backup clock               selection
      unsigned int : 8; // Reserved
      unsigned int MCOSEL: 3; // Microcontroller clock               output
      unsigned int : 1; // Reserved
      unsigned int MCOPRE: 3; // Microcontroller clock output               prescaler
      unsigned int : 1; // Reserved
} CFGR;
// PLL configuration register
 struct {
      unsigned int PLLSRC: 2; // Main PLL, PLLSAI1 and PLLSAI2 entry               clock source
      unsigned int : 2; // Reserved
      unsigned int PLLM: 3; // Division factor for the main PLL and               audio PLL (PLLSAI1 and PLLSAI2) input               clock
      unsigned int : 1; // Reserved
      unsigned int PLLN: 7; // Main PLL multiplication factor for               VCO
      unsigned int : 1; // Reserved
      unsigned int PLLPEN: 1; // Main PLL PLLSAI3CLK output               enable
      unsigned int PLLP: 1; // Main PLL division factor for PLLSAI3CLK               (SAI1 and SAI2 clock)
      unsigned int : 2; // Reserved
      unsigned int PLLQEN: 1; // Main PLL PLLUSB1CLK output               enable
      unsigned int PLLQ: 2; // Main PLL division factor for               PLLUSB1CLK(48 MHz clock)
      unsigned int : 1; // Reserved
      unsigned int PLLREN: 1; // Main PLL PLLCLK output               enable
      unsigned int PLLR: 2; // Main PLL division factor for PLLCLK               (system clock)
      unsigned int : 5; // Reserved
} PLLCFGR;
// PLLSAI1 configuration register
 struct {
      unsigned int : 8; // Reserved
      unsigned int PLLSAI1N: 7; // SAI1PLL multiplication factor for               VCO
      unsigned int : 1; // Reserved
      unsigned int PLLSAI1PEN: 1; // SAI1PLL PLLSAI1CLK output               enable
      unsigned int PLLSAI1P: 1; // SAI1PLL division factor for PLLSAI1CLK               (SAI1 or SAI2 clock)
      unsigned int : 2; // Reserved
      unsigned int PLLSAI1QEN: 1; // SAI1PLL PLLUSB2CLK output               enable
      unsigned int PLLSAI1Q: 2; // SAI1PLL division factor for PLLUSB2CLK               (48 MHz clock)
      unsigned int : 1; // Reserved
      unsigned int PLLSAI1REN: 1; // PLLSAI1 PLLADC1CLK output               enable
      unsigned int PLLSAI1R: 2; // PLLSAI1 division factor for PLLADC1CLK               (ADC clock)
      unsigned int : 5; // Reserved
} PLLSAI1CFGR;
      unsigned int : 32; // Reserved
// Clock interrupt enable           register
 struct {
      unsigned int LSIRDYIE: 1; // LSI ready interrupt enable
      unsigned int LSERDYIE: 1; // LSE ready interrupt enable
      unsigned int MSIRDYIE: 1; // MSI ready interrupt enable
      unsigned int HSIRDYIE: 1; // HSI ready interrupt enable
      unsigned int HSERDYIE: 1; // HSE ready interrupt enable
      unsigned int PLLRDYIE: 1; // PLL ready interrupt enable
      unsigned int PLLSAI1RDYIE: 1; // PLLSAI1 ready interrupt               enable
      unsigned int : 2; // Reserved
      unsigned int LSECSSIE: 1; // LSE clock security system interrupt               enable
      unsigned int HSI48RDYIE: 1; // HSI48 ready interrupt               enable
      unsigned int : 21; // Reserved
} CIER;
// Clock interrupt flag register
 struct {
      unsigned int LSIRDYF: 1; // LSI ready interrupt flag
      unsigned int LSERDYF: 1; // LSE ready interrupt flag
      unsigned int MSIRDYF: 1; // MSI ready interrupt flag
      unsigned int HSIRDYF: 1; // HSI ready interrupt flag
      unsigned int HSERDYF: 1; // HSE ready interrupt flag
      unsigned int PLLRDYF: 1; // PLL ready interrupt flag
      unsigned int PLLSAI1RDYF: 1; // PLLSAI1 ready interrupt               flag
      unsigned int : 1; // Reserved
      unsigned int CSSF: 1; // Clock security system interrupt               flag
      unsigned int LSECSSF: 1; // LSE Clock security system interrupt               flag
      unsigned int HSI48RDYF: 1; // HSI48 ready interrupt flag
      unsigned int : 21; // Reserved
} CIFR;
// Clock interrupt clear register
 struct {
      unsigned int LSIRDYC: 1; // LSI ready interrupt clear
      unsigned int LSERDYC: 1; // LSE ready interrupt clear
      unsigned int MSIRDYC: 1; // MSI ready interrupt clear
      unsigned int HSIRDYC: 1; // HSI ready interrupt clear
      unsigned int HSERDYC: 1; // HSE ready interrupt clear
      unsigned int PLLRDYC: 1; // PLL ready interrupt clear
      unsigned int PLLSAI1RDYC: 1; // PLLSAI1 ready interrupt               clear
      unsigned int : 1; // Reserved
      unsigned int CSSC: 1; // Clock security system interrupt               clear
      unsigned int LSECSSC: 1; // LSE Clock security system interrupt               clear
      unsigned int HSI48RDYC: 1; // HSI48 oscillator ready interrupt               clear
      unsigned int : 21; // Reserved
} CICR;
      unsigned int : 32; // Reserved
// AHB1 peripheral reset register
 struct {
      unsigned int DMA1RST: 1; // DMA1 reset
      unsigned int DMA2RST: 1; // DMA2 reset
      unsigned int : 6; // Reserved
      unsigned int FLASHRST: 1; // Flash memory interface               reset
      unsigned int : 2; // Reserved
      unsigned int CRCRST: 1; // Reserved
      unsigned int : 4; // Reserved
      unsigned int TSCRST: 1; // Touch Sensing Controller               reset
      unsigned int : 15; // Reserved
} AHB1RSTR;
// AHB2 peripheral reset register
 struct {
      unsigned int GPIOARST: 1; // IO port A reset
      unsigned int GPIOBRST: 1; // IO port B reset
      unsigned int GPIOCRST: 1; // IO port C reset
      unsigned int GPIODRST: 1; // IO port D reset
      unsigned int GPIOERST: 1; // IO port E reset
      unsigned int : 2; // Reserved
      unsigned int GPIOHRST: 1; // IO port H reset
      unsigned int : 5; // Reserved
      unsigned int ADCRST: 1; // ADC reset
      unsigned int : 2; // Reserved
      unsigned int AESRST: 1; // AES hardware accelerator               reset
      unsigned int : 1; // Reserved
      unsigned int RNGRST: 1; // Random number generator               reset
      unsigned int : 13; // Reserved
} AHB2RSTR;
// AHB3 peripheral reset register
 struct {
      unsigned int : 8; // Reserved
      unsigned int QSPIRST: 1; // Quad SPI memory interface               reset
      unsigned int : 23; // Reserved
} AHB3RSTR;
      unsigned int : 32; // Reserved
// APB1 peripheral reset register           1
 struct {
      unsigned int TIM2RST: 1; // TIM2 timer reset
      unsigned int : 3; // Reserved
      unsigned int TIM6RST: 1; // TIM6 timer reset
      unsigned int TIM7RST: 1; // TIM7 timer reset
      unsigned int : 3; // Reserved
      unsigned int LCDRST: 1; // LCD interface reset
      unsigned int : 4; // Reserved
      unsigned int SPI2RST: 1; // SPI2 reset
      unsigned int SPI3RST: 1; // SPI3 reset
      unsigned int : 1; // Reserved
      unsigned int USART2RST: 1; // USART2 reset
      unsigned int USART1RST: 1; // USART1 reset
      unsigned int : 2; // Reserved
      unsigned int I2C1RST: 1; // I2C1 reset
      unsigned int : 1; // Reserved
      unsigned int I2C3RST: 1; // I2C3 reset
      unsigned int : 1; // Reserved
      unsigned int CAN1RST: 1; // CAN1 reset
      unsigned int : 2; // Reserved
      unsigned int PWRRST: 1; // Power interface reset
      unsigned int DAC1RST: 1; // DAC1 interface reset
      unsigned int OPAMPRST: 1; // OPAMP interface reset
      unsigned int LPTIM1RST: 1; // Low Power Timer 1 reset
} APB1RSTR1;
// APB1 peripheral reset register           2
 struct {
      unsigned int LPUART1RST: 1; // Low-power UART 1 reset
      unsigned int : 1; // Reserved
      unsigned int SWPMI1RST: 1; // Single wire protocol reset
      unsigned int : 2; // Reserved
      unsigned int LPTIM2RST: 1; // Low-power timer 2 reset
      unsigned int : 26; // Reserved
} APB1RSTR2;
// APB2 peripheral reset register
 struct {
      unsigned int SYSCFGRST: 1; // System configuration (SYSCFG)               reset
      unsigned int : 9; // Reserved
      unsigned int SDMMCRST: 1; // SDMMC reset
      unsigned int TIM1RST: 1; // TIM1 timer reset
      unsigned int SPI1RST: 1; // SPI1 reset
      unsigned int : 1; // Reserved
      unsigned int USART1RST: 1; // USART1 reset
      unsigned int : 1; // Reserved
      unsigned int TIM15RST: 1; // TIM15 timer reset
      unsigned int TIM16RST: 1; // TIM16 timer reset
      unsigned int : 3; // Reserved
      unsigned int SAI1RST: 1; // Serial audio interface 1 (SAI1)               reset
      unsigned int : 10; // Reserved
} APB2RSTR;
      unsigned int : 32; // Reserved
// AHB1 peripheral clock enable           register
 struct {
      unsigned int DMA1EN: 1; // DMA1 clock enable
      unsigned int DMA2EN: 1; // DMA2 clock enable
      unsigned int : 6; // Reserved
      unsigned int FLASHEN: 1; // Flash memory interface clock               enable
      unsigned int : 2; // Reserved
      unsigned int CRCEN: 1; // Reserved
      unsigned int : 4; // Reserved
      unsigned int TSCEN: 1; // Touch Sensing Controller clock               enable
      unsigned int : 15; // Reserved
} AHB1ENR;
// AHB2 peripheral clock enable           register
 struct {
      unsigned int GPIOAEN: 1; // IO port A clock enable
      unsigned int GPIOBEN: 1; // IO port B clock enable
      unsigned int GPIOCEN: 1; // IO port C clock enable
      unsigned int GPIODEN: 1; // IO port D clock enable
      unsigned int GPIOEEN: 1; // IO port E clock enable
      unsigned int : 2; // Reserved
      unsigned int GPIOHEN: 1; // IO port H clock enable
      unsigned int : 5; // Reserved
      unsigned int ADCEN: 1; // ADC clock enable
      unsigned int : 2; // Reserved
      unsigned int AESEN: 1; // AES accelerator clock               enable
      unsigned int : 1; // Reserved
      unsigned int RNGEN: 1; // Random Number Generator clock               enable
      unsigned int : 13; // Reserved
} AHB2ENR;
// AHB3 peripheral clock enable           register
 struct {
      unsigned int : 8; // Reserved
      unsigned int QSPIEN: 1; // QSPIEN
      unsigned int : 23; // Reserved
} AHB3ENR;
      unsigned int : 32; // Reserved
// APB1ENR1
 struct {
      unsigned int TIM2EN: 1; // TIM2 timer clock enable
      unsigned int : 3; // Reserved
      unsigned int TIM6EN: 1; // TIM6 timer clock enable
      unsigned int TIM7EN: 1; // TIM7 timer clock enable
      unsigned int : 3; // Reserved
      unsigned int LCDEN: 1; // LCD clock enable
      unsigned int RTCAPBEN: 1; // RTC APB clock enable
      unsigned int WWDGEN: 1; // Window watchdog clock               enable
      unsigned int : 2; // Reserved
      unsigned int SPI1EN: 1; // SPI1 clock enable
      unsigned int SPI3EN: 1; // SPI3 clock enable
      unsigned int : 1; // Reserved
      unsigned int USART2EN: 1; // USART2 clock enable
      unsigned int USART1EN: 1; // USART1 clock enable
      unsigned int : 2; // Reserved
      unsigned int I2C1EN: 1; // I2C1 clock enable
      unsigned int : 1; // Reserved
      unsigned int I2C3EN: 1; // I2C3 clock enable
      unsigned int CRSEN: 1; // CRS clock enable
      unsigned int CAN1EN: 1; // CAN1 clock enable
      unsigned int USBF: 1; // USB FS clock enable
      unsigned int : 1; // Reserved
      unsigned int PWREN: 1; // Power interface clock               enable
      unsigned int DAC1EN: 1; // DAC1 interface clock               enable
      unsigned int OPAMPEN: 1; // OPAMP interface clock               enable
      unsigned int LPTIM1EN: 1; // Low power timer 1 clock               enable
} APB1ENR1;
// APB1 peripheral clock enable register           2
 struct {
      unsigned int LPUART1EN: 1; // Low power UART 1 clock               enable
      unsigned int : 1; // Reserved
      unsigned int SWPMI1EN: 1; // Single wire protocol clock               enable
      unsigned int : 2; // Reserved
      unsigned int LPTIM2EN: 1; // LPTIM2EN
      unsigned int : 26; // Reserved
} APB1ENR2;
// APB2ENR
 struct {
      unsigned int SYSCFGEN: 1; // SYSCFG clock enable
      unsigned int : 6; // Reserved
      unsigned int FIREWALLEN: 1; // Firewall clock enable
      unsigned int : 2; // Reserved
      unsigned int SDMMCEN: 1; // SDMMC clock enable
      unsigned int TIM1EN: 1; // TIM1 timer clock enable
      unsigned int SPI1EN: 1; // SPI1 clock enable
      unsigned int : 1; // Reserved
      unsigned int USART1EN: 1; // USART1clock enable
      unsigned int : 1; // Reserved
      unsigned int TIM15EN: 1; // TIM15 timer clock enable
      unsigned int TIM16EN: 1; // TIM16 timer clock enable
      unsigned int : 3; // Reserved
      unsigned int SAI1EN: 1; // SAI1 clock enable
      unsigned int : 10; // Reserved
} APB2ENR;
      unsigned int : 32; // Reserved
// AHB1 peripheral clocks enable in Sleep and           Stop modes register
 struct {
      unsigned int DMA1SMEN: 1; // DMA1 clocks enable during Sleep and Stop               modes
      unsigned int DMA2SMEN: 1; // DMA2 clocks enable during Sleep and Stop               modes
      unsigned int : 6; // Reserved
      unsigned int FLASHSMEN: 1; // Flash memory interface clocks enable               during Sleep and Stop modes
      unsigned int SRAM1SMEN: 1; // SRAM1 interface clocks enable during               Sleep and Stop modes
      unsigned int : 1; // Reserved
      unsigned int CRCSMEN: 1; // CRCSMEN
      unsigned int : 4; // Reserved
      unsigned int TSCSMEN: 1; // Touch Sensing Controller clocks enable               during Sleep and Stop modes
      unsigned int : 15; // Reserved
} AHB1SMENR;
// AHB2 peripheral clocks enable in Sleep and           Stop modes register
 struct {
      unsigned int GPIOASMEN: 1; // IO port A clocks enable during Sleep and               Stop modes
      unsigned int GPIOBSMEN: 1; // IO port B clocks enable during Sleep and               Stop modes
      unsigned int GPIOCSMEN: 1; // IO port C clocks enable during Sleep and               Stop modes
      unsigned int GPIODSMEN: 1; // IO port D clocks enable during Sleep and               Stop modes
      unsigned int GPIOESMEN: 1; // IO port E clocks enable during Sleep and               Stop modes
      unsigned int : 2; // Reserved
      unsigned int GPIOHSMEN: 1; // IO port H clocks enable during Sleep and               Stop modes
      unsigned int : 1; // Reserved
      unsigned int SRAM2SMEN: 1; // SRAM2 interface clocks enable during               Sleep and Stop modes
      unsigned int : 3; // Reserved
      unsigned int ADCFSSMEN: 1; // ADC clocks enable during Sleep and Stop               modes
      unsigned int : 2; // Reserved
      unsigned int AESSMEN: 1; // AES accelerator clocks enable during               Sleep and Stop modes
      unsigned int : 1; // Reserved
      unsigned int RNGSMEN: 1; // Random Number Generator clocks enable               during Sleep and Stop modes
      unsigned int : 13; // Reserved
} AHB2SMENR;
// AHB3 peripheral clocks enable in Sleep and           Stop modes register
 struct {
      unsigned int : 8; // Reserved
      unsigned int QSPISMEN: 1; // QSPISMEN
      unsigned int : 23; // Reserved
} AHB3SMENR;
      unsigned int : 32; // Reserved
// APB1SMENR1
 struct {
      unsigned int TIM2SMEN: 1; // TIM2 timer clocks enable during Sleep               and Stop modes
      unsigned int : 3; // Reserved
      unsigned int TIM6SMEN: 1; // TIM6 timer clocks enable during Sleep               and Stop modes
      unsigned int TIM7SMEN: 1; // TIM7 timer clocks enable during Sleep               and Stop modes
      unsigned int : 3; // Reserved
      unsigned int LCDSMEN: 1; // LCD clocks enable during Sleep and Stop               modes
      unsigned int RTCAPBSMEN: 1; // RTC APB clock enable during Sleep and               Stop modes
      unsigned int WWDGSMEN: 1; // Window watchdog clocks enable during               Sleep and Stop modes
      unsigned int : 2; // Reserved
      unsigned int SPI2SMEN: 1; // SPI2 clocks enable during Sleep and Stop               modes
      unsigned int SP3SMEN: 1; // SPI3 clocks enable during Sleep and Stop               modes
      unsigned int : 1; // Reserved
      unsigned int USART1SMEN: 1; // USART1 clocks enable during Sleep and               Stop modes
      unsigned int USART2SMEN: 1; // USART2 clocks enable during Sleep and               Stop modes
      unsigned int : 2; // Reserved
      unsigned int I2C1SMEN: 1; // I2C1 clocks enable during Sleep and Stop               modes
      unsigned int : 1; // Reserved
      unsigned int I2C3SMEN: 1; // I2C3 clocks enable during Sleep and Stop               modes
      unsigned int : 1; // Reserved
      unsigned int CAN1SMEN: 1; // CAN1 clocks enable during Sleep and Stop               modes
      unsigned int USBFSSMEN: 1; // USB FS clock enable during Sleep and               Stop modes
      unsigned int : 1; // Reserved
      unsigned int PWRSMEN: 1; // Power interface clocks enable during               Sleep and Stop modes
      unsigned int DAC1SMEN: 1; // DAC1 interface clocks enable during               Sleep and Stop modes
      unsigned int OPAMPSMEN: 1; // OPAMP interface clocks enable during               Sleep and Stop modes
      unsigned int LPTIM1SMEN: 1; // Low power timer 1 clocks enable during               Sleep and Stop modes
} APB1SMENR1;
// APB1 peripheral clocks enable in Sleep and           Stop modes register 2
 struct {
      unsigned int LPUART1SMEN: 1; // Low power UART 1 clocks enable during               Sleep and Stop modes
      unsigned int : 1; // Reserved
      unsigned int SWPMI1SMEN: 1; // Single wire protocol clocks enable               during Sleep and Stop modes
      unsigned int : 2; // Reserved
      unsigned int LPTIM2SMEN: 1; // LPTIM2SMEN
      unsigned int : 26; // Reserved
} APB1SMENR2;
// APB2SMENR
 struct {
      unsigned int SYSCFGSMEN: 1; // SYSCFG clocks enable during Sleep and               Stop modes
      unsigned int : 9; // Reserved
      unsigned int SDMMCSMEN: 1; // SDMMC clocks enable during Sleep and               Stop modes
      unsigned int TIM1SMEN: 1; // TIM1 timer clocks enable during Sleep               and Stop modes
      unsigned int SPI1SMEN: 1; // SPI1 clocks enable during Sleep and Stop               modes
      unsigned int : 1; // Reserved
      unsigned int USART1SMEN: 1; // USART1clocks enable during Sleep and               Stop modes
      unsigned int : 1; // Reserved
      unsigned int TIM15SMEN: 1; // TIM15 timer clocks enable during Sleep               and Stop modes
      unsigned int TIM16SMEN: 1; // TIM16 timer clocks enable during Sleep               and Stop modes
      unsigned int : 3; // Reserved
      unsigned int SAI1SMEN: 1; // SAI1 clocks enable during Sleep and Stop               modes
      unsigned int : 10; // Reserved
} APB2SMENR;
      unsigned int : 32; // Reserved
// CCIPR
 struct {
      unsigned int USART1SEL: 2; // USART1 clock source               selection
      unsigned int USART2SEL: 2; // USART2 clock source               selection
      unsigned int : 6; // Reserved
      unsigned int LPUART1SEL: 2; // LPUART1 clock source               selection
      unsigned int I2C1SEL: 2; // I2C1 clock source               selection
      unsigned int : 2; // Reserved
      unsigned int I2C3SEL: 2; // I2C3 clock source               selection
      unsigned int LPTIM1SEL: 2; // Low power timer 1 clock source               selection
      unsigned int LPTIM2SEL: 2; // Low power timer 2 clock source               selection
      unsigned int SAI1SEL: 2; // SAI1 clock source               selection
      unsigned int : 2; // Reserved
      unsigned int CLK48SEL: 2; // 48 MHz clock source               selection
      unsigned int ADCSEL: 2; // ADCs clock source               selection
      unsigned int SWPMI1SEL: 1; // SWPMI1 clock source               selection
      unsigned int : 1; // Reserved
} CCIPR;
      unsigned int : 32; // Reserved
// BDCR
 struct {
      unsigned int LSEON: 1; // LSE oscillator enable
      unsigned int LSERDY: 1; // LSE oscillator ready
      unsigned int LSEBYP: 1; // LSE oscillator bypass
      unsigned int LSEDRV: 2; // SE oscillator drive               capability
      unsigned int LSECSSON: 1; // LSECSSON
      unsigned int LSECSSD: 1; // LSECSSD
      unsigned int : 1; // Reserved
      unsigned int RTCSEL: 2; // RTC clock source selection
      unsigned int : 5; // Reserved
      unsigned int RTCEN: 1; // RTC clock enable
      unsigned int BDRST: 1; // Backup domain software               reset
      unsigned int : 7; // Reserved
      unsigned int LSCOEN: 1; // Low speed clock output               enable
      unsigned int LSCOSEL: 1; // Low speed clock output               selection
      unsigned int : 6; // Reserved
} BDCR;
// CSR
 struct {
      unsigned int LSION: 1; // LSI oscillator enable
      unsigned int LSIRDY: 1; // LSI oscillator ready
      unsigned int : 6; // Reserved
      unsigned int MSISRANGE: 4; // SI range after Standby               mode
      unsigned int : 11; // Reserved
      unsigned int RMVF: 1; // Remove reset flag
      unsigned int FIREWALLRSTF: 1; // Firewall reset flag
      unsigned int OBLRSTF: 1; // Option byte loader reset               flag
      unsigned int PINRSTF: 1; // Pin reset flag
      unsigned int BORRSTF: 1; // BOR flag
      unsigned int SFTRSTF: 1; // Software reset flag
      unsigned int IWDGRSTF: 1; // Independent window watchdog reset               flag
      unsigned int WWDGRSTF: 1; // Window watchdog reset flag
      unsigned int LPWRSTF: 1; // Low-power reset flag
} CSR;
} SVD_RCC;
asm(".equ SVD_RCC, 0x40021000");
