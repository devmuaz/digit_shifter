#ifndef DigitShifter_h
#define DigitShifter_h
#include "Arduino.h"

enum TYPE{
	CATHODE = 0,
	ANODE = 1
};
class DigitShifter
{
private:
	const byte _commonCathodeData[10] = {
  		0xfc,   // 0 - 0b11111100
  		0x60,   // 1 - 0b01100000
  		0xda,   // 2 - 0b11011010
  		0xf2,   // 3 - 0b11110010
  		0x66,   // 4 - 0b01100110
  		0xb6,   // 5 - 0b10110110
  		0xbe,   // 6 - 0b10111110
  		0xe0,   // 7 - 0b11100000
  		0xfe,   // 8 - 0b11111110
  		0xf6    // 9 - 0b11110110
  	};
	int _SHIFT_DATA;
	int _SHIFT_CLK;
	int _SHIFT_LATCH;
public:
	DigitShifter(int SHIFT_DATA = 2, int SHIFT_CLK = 3, int SHIFT_LATCH = 4);
	void displayDigit(int num, TYPE type);
};

#endif
