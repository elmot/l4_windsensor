// Comparator
 extern struct {
// Comparator 1 control and status           register
 struct {
      unsigned int COMP1_EN: 1; // Comparator 1 enable bit
      unsigned int : 1; // Reserved
      unsigned int COMP1_PWRMODE: 2; // Power Mode of the comparator               1
      unsigned int COMP1_INMSEL: 3; // Comparator 1 Input Minus connection               configuration bit
      unsigned int COMP1_INPSEL: 1; // Comparator1 input plus selection               bit
      unsigned int : 7; // Reserved
      unsigned int COMP1_POLARITY: 1; // Comparator 1 polarity selection               bit
      unsigned int COMP1_HYST: 2; // Comparator 1 hysteresis selection               bits
      unsigned int COMP1_BLANKING: 3; // Comparator 1 blanking source selection               bits
      unsigned int : 1; // Reserved
      unsigned int COMP1_BRGEN: 1; // Scaler bridge enable
      unsigned int COMP1_SCALEN: 1; // Voltage scaler enable bit
      unsigned int : 6; // Reserved
      unsigned int COMP1_VALUE: 1; // Comparator 1 output status               bit
      unsigned int COMP1_LOCK: 1; // COMP1_CSR register lock               bit
} COMP1_CSR;
// Comparator 2 control and status           register
 struct {
      unsigned int COMP2_EN: 1; // Comparator 2 enable bit
      unsigned int : 1; // Reserved
      unsigned int COMP2_PWRMODE: 2; // Power Mode of the comparator               2
      unsigned int COMP2_INMSEL: 3; // Comparator 2 Input Minus connection               configuration bit
      unsigned int COMP2_INPSEL: 1; // Comparator 2 Input Plus connection               configuration bit
      unsigned int : 1; // Reserved
      unsigned int COMP2_WINMODE: 1; // Windows mode selection bit
      unsigned int : 5; // Reserved
      unsigned int COMP2_POLARITY: 1; // Comparator 2 polarity selection               bit
      unsigned int COMP2_HYST: 2; // Comparator 2 hysteresis selection               bits
      unsigned int COMP2_BLANKING: 3; // Comparator 2 blanking source selection               bits
      unsigned int : 1; // Reserved
      unsigned int COMP2_BRGEN: 1; // Scaler bridge enable
      unsigned int COMP2_SCALEN: 1; // Voltage scaler enable bit
      unsigned int : 6; // Reserved
      unsigned int COMP2_VALUE: 1; // Comparator 2 output status               bit
      unsigned int COMP2_LOCK: 1; // COMP2_CSR register lock               bit
} COMP2_CSR;
} SVD_COMP;
asm(".equ SVD_COMP, 0x40010200");
