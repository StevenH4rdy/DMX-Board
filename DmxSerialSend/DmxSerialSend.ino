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

 int bank;
 int val=4;
 int val0 = 7;
 int val1 = 10; 
 int encoder0PinA = 2;
 int encoder0PinB = 3;
 int encoder1PinA = 5;
 int encoder1PinB = 6;
 int encoder2PinA = 8;
 int encoder2PinB = 9;
 uint8_t encoder0Pos = 0;
 int encoder0PinALast = LOW;
 uint8_t encoder1Pos = 0;
 int encoder1PinALast = LOW;
 uint8_t encoder2Pos = 0;
 int encoder2PinALast = LOW;
 int n,m,o,p = LOW;
 int i,j,k,l = HIGH;
 int lastsensorValue = 0;
 int lastsensorValue2 = 0;
 int a,b,c,d,x,y;
 
 
void setup() {

   pinMode (encoder0PinA,INPUT_PULLUP);
   pinMode (encoder0PinB,INPUT_PULLUP);
   pinMode (val, INPUT_PULLUP);
   
   pinMode (encoder1PinA,INPUT_PULLUP);
   pinMode (encoder1PinB,INPUT_PULLUP);
   pinMode (val0, INPUT_PULLUP);

  DMXSerial.maxChannel(512);

  DMXSerial.init(DMXController);
} // setup

void dmxchannel(){
  i = bank+1;
  x = i+(bank*5);
  y = (i+1)+(bank*5);
  a = (i+2)+(bank*5);
  b = (i+3)+(bank*5);
  c = (i+4)+(bank*5);
}


void loop() {
  
   
  n = digitalRead(encoder0PinA);  // encoder 1
   if ((encoder0PinALast == LOW) && (n == HIGH)) {
     if (digitalRead(encoder0PinB) == LOW) {
       encoder0Pos--;
     } else {
       encoder0Pos++;
     }
       
   encoder0PinALast = n;  
    encoder0Pos = 0;
    
    if(n<0, n==4);
    if(n>4, n==0);
   
   n = digitalRead(val); 
    }
  
  bank = n;
  
   m = digitalRead(encoder1PinA);   //encoder 2
   if ((encoder1PinALast == LOW) && (m == HIGH)) {
     if (digitalRead(encoder1PinB) == LOW) {
       encoder1Pos--;
     } else {
       encoder1Pos++;
     }
     
   } 
   encoder1PinALast = m;
   
   j = digitalRead(val0);
   if (j == LOW) {
    encoder1Pos = 127;
   }
   
   o = digitalRead(encoder2PinA);   //encoder 2
   if ((encoder2PinALast == LOW) && (m == HIGH)) {
     if (digitalRead(encoder1PinB) == LOW) {
       encoder2Pos--;
     } else {
       encoder2Pos++;
     }
     
   } 
   encoder2PinALast = o;
   
   k = digitalRead(val1);
   if (k == LOW) {
    encoder2Pos = 127;
   }
  
  
  
  
  
  
  int sensorValue1 = analogRead(A0);
  if (sensorValue1 != lastsensorValue) {
  DMXSerial.write(x, sensorValue1 >> 2);
  }
  lastsensorValue = sensorValue1;
  
  int sensorValue2 = analogRead(A1);
  if (sensorValue2 != lastsensorValue2) {
  DMXSerial.write(y, sensorValue2 >> 2);
  }
  lastsensorValue2 = sensorValue2;
  
  // int sensorValue2 = analogRead(A1);
  DMXSerial.write(a, encoder0Pos);
  
  DMXSerial.write(b, encoder1Pos);
  
  DMXSerial.write(c, encoder2Pos);
  
  
  
  
} // loop

