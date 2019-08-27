#include "DigitShifter.h"
#include "Arduino.h"

DigitShifter::DigitShifter(int SHIFT_DATA = 2, int SHIFT_CLK = 3, int SHIFT_LATCH = 4){
	// Initializing required pins
	_SHIFT_DATA = SHIFT_DATA;
	_SHIFT_CLK = SHIFT_CLK;
	_SHIFT_LATCH = SHIFT_LATCH;

	// Setting pinMode for each pin
	pinMode(_SHIFT_DATA, OUTPUT);
	pinMode(_SHIFT_CLK, OUTPUT);
	pinMode(_SHIFT_LATCH, OUTPUT);
}

void DigitShifter::displayDigit(int num, TYPE type){
	if(num >= 0 && num <= 9){
		if(type == CATHODE)
			shiftOut(_SHIFT_DATA, _SHIFT_CLK, LSBFIRST, _commonCathodeData[num]);
		else
			shiftOut(_SHIFT_DATA, _SHIFT_CLK, LSBFIRST, ~_commonCathodeData[num]);
  		digitalWrite(_SHIFT_LATCH, LOW);
  		digitalWrite(_SHIFT_LATCH, HIGH);
  		digitalWrite(_SHIFT_LATCH, LOW);
	}else{
	// DO NOTHING IF NOT DIGIT
	}
}


