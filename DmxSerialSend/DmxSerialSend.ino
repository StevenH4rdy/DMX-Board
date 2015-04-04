#include "DMXSerial.h"

 int val=4;
 int val0 = 7;
 int val1 = 10; 
 int val2 = 13;
 int encoder0PinA = 2;
 int encoder0PinB = 3;
 int encoder1PinA = 5;
 int encoder1PinB = 6;
 int encoder2PinA = 8;
 int encoder2PinB = 9;
 int encoder3PinA = 11;
 int encoder3PinB = 12;
 uint8_t encoder0Pos = 0;
 int encoder0PinALast = LOW;
 uint8_t encoder1Pos = 0;
 int encoder1PinALast = LOW;
 uint8_t encoder2Pos = 0;
 int encoder2PinALast = LOW;
 uint8_t encoder3Pos = 0;
 int encoder3PinALast = LOW;
 int n,m,o,p,q = LOW;
 int i,j,k,l = HIGH;
 int lastsensorValue = 0;
 int lastsensorValue2 = 0;
 int a,b,c,d,e,f;
 
 
void setup() {

   pinMode (encoder0PinA,INPUT_PULLUP);
   pinMode (encoder0PinB,INPUT_PULLUP);
   pinMode (val, INPUT_PULLUP);
   
   pinMode (encoder1PinA,INPUT_PULLUP);
   pinMode (encoder1PinB,INPUT_PULLUP);
   pinMode (val0, INPUT_PULLUP);
   
   pinMode (encoder2PinA,INPUT_PULLUP);
   pinMode (encoder2PinB,INPUT_PULLUP);
   pinMode (val1, INPUT_PULLUP);
   
   pinMode (encoder3PinA,INPUT_PULLUP);
   pinMode (encoder3PinB,INPUT_PULLUP);
   pinMode (val2, INPUT_PULLUP);

  DMXSerial.maxChannel(512);

  DMXSerial.init(DMXController);
} // setup


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
   
   n = digitalRead(val); 
    }
  
  
   m = digitalRead(encoder1PinA);   //encoder 2
   if ((encoder1PinALast == LOW) && (m == HIGH)) {
     if (digitalRead(encoder1PinB) == LOW) {
       encoder1Pos--;
     } else {
       encoder1Pos++;
     }
     
   } 
   encoder1PinALast = m;
   
   m = digitalRead(val0);
   if (m == LOW) {
    encoder1Pos = 0;
   }
   
   o = digitalRead(encoder2PinA);   //encoder 2
   if ((encoder2PinALast == LOW) && (o == HIGH)) {
     if (digitalRead(encoder1PinB) == LOW) {
       encoder2Pos--;
     } else {
       encoder2Pos++;
     }
     
   } 
   encoder2PinALast = o;
   
   o = digitalRead(val1);
   if (o == LOW) {
    encoder2Pos = 0;
   }
   
   
   p = digitalRead(encoder3PinA);   //encoder 2
   if ((encoder3PinALast == LOW) && (p == HIGH)) {
     if (digitalRead(encoder3PinB) == LOW) {
       encoder3Pos--;
     } else {
       encoder3Pos++;
     }
     
   } 
   encoder3PinALast = p;
   
   p = digitalRead(val2);
   if (p == LOW) {
    encoder3Pos = 0;
   }
  
  
  
  
  
  
  int sensorValue1 = analogRead(A0);
  if (sensorValue1 != lastsensorValue) {
  DMXSerial.write(3, sensorValue1 >> 2);
  }
  lastsensorValue = sensorValue1;
  
  int sensorValue2 = analogRead(A1);
  if (sensorValue2 != lastsensorValue2) {
  DMXSerial.write(4, sensorValue2 >> 2);
  }
  lastsensorValue2 = sensorValue2;
  
  
  DMXSerial.write(1, encoder1Pos);
  
  DMXSerial.write(2, encoder2Pos);
  
  DMXSerial.write(5, encoder3Pos);
  
  
  
  
} // loop
