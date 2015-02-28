// - - - - -
// DmxSerial - A hardware supported interface to DMX.
// DmxSerialSend.ino: Sample DMX application for sending 3 DMX values:
// address 1 (red) -> also available on PWM Port 9
// address 2 (green) -> also available on PWM Port 6
// address 3 (blue) -> also available on PWM Port 5
// 
// Copyright (c) 2011 by Matthias Hertel, http://www.mathertel.de
// This work is licensed under a BSD style license. See http://www.mathertel.de/License.aspx
// 
// Documentation and samples are available at http://www.mathertel.de/Arduino
// 25.07.2011 creation of the DmxSerial library.
// 10.09.2011 fully control the serial hardware register
//            without using the Arduino Serial (HardwareSerial) class to avoid ISR implementation conflicts.
// 01.12.2011 include file and extension changed to work with the Arduino 1.0 environment
// - - - - -

#include "DMXSerial.h"


void setup() {
  DMXSerial.maxChannel(512);

  DMXSerial.init(DMXController);
} // setup


// loop through the rainbow colors 
void loop() {
  
  int sensorValue1 = analogRead(A0);
  DMXSerial.write(1, sensorValue1 >> 2);
  
  int sensorValue2 = analogRead(A1);
  DMXSerial.write(2, sensorValue2 >> 2);
  
  
  
} // loop
