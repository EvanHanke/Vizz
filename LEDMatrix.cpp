#include "LEDMatrix.h"
#include "Arduino.h"
#include <SPI.h>

LEDMatrix::LEDMatrix(int a){
  cspin = a;
}

void LEDMatrix::init() {
  //Taken from in class example
  pinMode(cspin, OUTPUT);
  sendMessage(0x0C, 1);     //shutdown mode off (meaning... make the thing actually work)
  sendMessage(0x09, 0);     //decode mode off (i don't know what decode mode is)
  sendMessage(0x0A, 0x0f);  //intensity mode, brightest
  sendMessage(0x0B, 0x07);  //set scan limit to show all
  sendMessage(0x0F, 0x00);  //display test off  
}

void LEDMatrix::updateMatrix(bool matrix[8][8]){
  for(int i = 0; i < 8; i++){
    int sum = 0;
    for(int j = 0; j < 8; j++){
      if(matrix[i][j]){
        sum += pow(2, j);
      }
    }
    sendMessage(i+1, sum);
  }
}

void LEDMatrix::sendMessage(byte one, byte two) {
  digitalWrite(cspin, LOW);
  SPI.transfer(one);
  SPI.transfer(two);
  digitalWrite(cspin, HIGH);
}

void LEDMatrix::clearMatrix() {
  for (int i = 1; i <= 8; i++) {
    digitalWrite(cspin, LOW);
    SPI.transfer(i);
    SPI.transfer(0);
    digitalWrite(cspin, HIGH);
  }
}

void LEDMatrix::togglePixl(int x, int y) {
  sendMessage(x+1 , 1 << y);
}

void LEDMatrix::displayRow(int r){
    r = abs(r-8)-1;
    int row = pow(2, r);
    for(int i = 1; i < 9; i++){
      digitalWrite(cspin, LOW);
      SPI.transfer(i);
      SPI.transfer(row);
      digitalWrite(cspin, HIGH);
    }
}

void LEDMatrix::displayCollum(int c){
    digitalWrite(cspin, LOW);
    SPI.transfer(c);
    SPI.transfer(255);
    digitalWrite(cspin, HIGH);
}

void LEDMatrix::displayRandom(){
    for(int i = 1; i < 9; i++){
      digitalWrite(cspin, LOW);
      SPI.transfer(i);
      int r = random(0, 7);
      int num = pow(2,r);
      num += pow(4, r/2);
      SPI.transfer(num);
      Serial.println(r);
      digitalWrite(cspin, HIGH);
    }
}

void LEDMatrix::displayCollumRandom(int c){
    digitalWrite(cspin, LOW);
    SPI.transfer(c);
      int r = random(0, 7);
      int num = pow(2,r);
      num += pow(4, r/2);
      SPI.transfer(num);
      Serial.println(r);
      digitalWrite(cspin, HIGH);
}



