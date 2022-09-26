/*
A physical, touch sensitive harp instrument. 

gawainhewitt.co.uk
https://github.com/gawainhewitt
*/

#include "constants.h"
#include "mpr121.h"
#include "reboot.h"

const int numberOfSensors = 12;

boolean updateDisplayFlag = true;

void setup() {
Serial.begin(9600);
init_mpr121();
pinMode(rebootButton, INPUT_PULLUP);
}

void loop() {
currtouched1 = mprBoard_A.touched();

if(digitalRead(rebootButton) == LOW){
    Serial.print("reboot");
    doReboot();
}

for (uint8_t i=0; i < numberOfSensors; i++) {
    if ((currtouched1 & _BV(i)) && !(lasttouched1 & _BV(i)) ) {
    Serial.print(i); Serial.println(" touched of A");
    }
}

lasttouched1 = currtouched1;
return;
}