# DigitShifter
Arduino library that controls the (7-segment 1-digit) display with 'Shift Register'


## Usage
Open up the arduino with a new blank project, then after hooking up everything.. copy/paste the following:

```c++
#include <DigitShifter.h>

// built by: AbdulMuaz Aqeel (Software and Hardware Developer)
// For More Please Visit: 
// https://github.com/devmuaz
// https://www.facebook.com/devmuaz
//
//
// DigitShifter is an Arduino C library that can easily control
// the 7-segment 1-digit displays for both (Anode and Cathode)
// 
//
//                      Shift Register (74HC595) PinOut
//
//                        SHIFT     __    SHIFT   SHIFT   _____
//         VCC     Q 0    DATA      OE    LATCH    CLK    RESET    Q 7'
//          |       |       |       |       |       |       |       |
//          ---------------------------------------------------------
//         |                                                         |
//         |__                                                       |
//         |__|                      74HC595                         |
//         |                                                         |
//         |                                                         |
//          ---------------------------------------------------------
//          |       |       |       |       |       |       |       |
//         Q 1     Q 2     Q 3     Q 4     Q 5     Q 6     Q 7     GND
//
// Hooking Up Table with both
// IC pinOut    |    display pinIn
// -------------------------------
//      Q 0     |        A
//      Q 1     |        B
//      Q 2     |        C
//      Q 3     |        D
//      Q 4     |        E
//      Q 5     |        F
//      Q 6     |        G
//      Q 7     |  DOT (OPTIONAL)
//
// By Default >
// DigitShifter ds(SHIFT_DATA = 2, SHIFT_CLK = 3, SHIFT_LATCH = 4);
//
// 1: connect pin 'SHIFT LATCH'  to pin 4 in Arduino
// 2: connect pin 'SHIFT CLK'    to pin 3 in Arduino
// 3: connect pin 'SHIFT DATA'   to pin 2 in Arduino
// Then in code just make an instance of DigitShifter (DigitShifter ds)
// 
// OR
//
// connect these pins in anywhere but in sequence
// DigitShifter ds(SHIFT_DATA, SHIFT_CLK, SHIFT_LATCH);

DigitShifter ds(
  2, // Pin 2 in Arduino connected to SHIFT DATA   in IC
  3, // Pin 3 in Arduino connected to SHIFT CLK    in IC
  4  // Pin 4 in Arduino connected to SHIFT LATCH  in IC
);

void setup() {
    // Then call member function displayDigit(int num, TYPE type)
    // Set the number you want to display (0 - 9)
    // Set display type (CATHODE or ANODE)
    ds.displayDigit(1, ANODE);
}

void loop() {
  for(int i = 0; i < 10; i++){
    ds.displayDigit(i, ANODE);
    delay(1000);
  }

  for(int i = 9; i >= 0; i--){
    ds.displayDigit(i, ANODE);
    delay(1000);
  }
}
```

## Enjoy
If you like it, star it ❤️
