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
// #include "encoder.h"

 int val = 4;
 int val1 = 7; 
 int encoder0PinA = 2;
 int encoder0PinB = 3;
 int encoder1PinA = 5;
 int encoder1PinB = 6;
 uint8_t encoder0Pos = 0;
 int encoder0PinALast = LOW;
 uint8_t encoder1Pos = 0;
 int encoder1PinALast = LOW;
 int n,m,o,p = LOW;
 int i,j,k,l = HIGH;
 int lastsensorValue = 0;
 int lastsensorValue2 = 0;

void setup() {

   pinMode (encoder0PinA,INPUT_PULLUP);
   pinMode (encoder0PinB,INPUT_PULLUP);
   pinMode (val, INPUT_PULLUP);
   
   pinMode (encoder1PinA,INPUT_PULLUP);
   pinMode (encoder1PinB,INPUT_PULLUP);
   pinMode (val1, INPUT_PULLUP);

  DMXSerial.maxChannel(512);

  DMXSerial.init(DMXController);
} // setup


// loop through the rainbow colors 
void loop() {
  
  n = digitalRead(encoder0PinA);
   if ((encoder0PinALast == LOW) && (n == HIGH)) {
     if (digitalRead(encoder0PinB) == LOW) {
       encoder0Pos--;
     } else {
       encoder0Pos++;
     }
     
   } 
   encoder0PinALast = n;
   
   i = digitalRead(val);
   if (i == LOW) {
    encoder0Pos = 95;
   }
   
   m = digitalRead(encoder1PinA);
   if ((encoder1PinALast == LOW) && (m == HIGH)) {
     if (digitalRead(encoder1PinB) == LOW) {
       encoder1Pos--;
     } else {
       encoder1Pos++;
     }
     
   } 
   encoder0PinALast = m;
   
   j = digitalRead(val1);
   if (j == LOW) {
    encoder1Pos = 95;
   }
  
  int sensorValue1 = analogRead(A0);
  if (sensorValue1 != lastsensorValue) {
  DMXSerial.write(2, sensorValue1 >> 2);
  }
  lastsensorValue = sensorValue1;
  
  int sensorValue2 = analogRead(A1);
  if (sensorValue2 != lastsensorValue2) {
  DMXSerial.write(2, sensorValue2 >> 2);
  }
  lastsensorValue2 = sensorValue2;
  
  // int sensorValue2 = analogRead(A1);
  DMXSerial.write(1, encoder0Pos);
  
 
  
} // loop
