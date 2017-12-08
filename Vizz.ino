#include "LEDMatrix.h"
#include "Grid.h"
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

int buttonPin = 15;
bool buttonState = false;
bool lastButtonState = false;

int curr = 1;
bool leds[8][8];

int seed = 666;
int count = 0;

LEDMatrix matrix(10);
Grid grid;

void setup() {
  SPI.begin();
  Serial.begin(9600);
  matrix.init();
  matrix.clearMatrix();
  pinMode(buttonPin, INPUT);
  
  for(int x = 0; x< 8; x++){
    for(int y = 0; y< 8; y++){
      leds[x][y] = false;
    }
  }
  grid.all(true);
  Serial.println("online");
}

void loop() {
  //check button
  lastButtonState = buttonState;
  buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState){
    Serial.println("new seed ");
    seed = random(1000);
    Serial.print(seed);
  }
  //check serial
  if (Serial.available() >= 3){
    count++;
    grid.all(false);
    for(int i = 0; i < 3; i++){
      int v = Serial.read();
      int numPoints = map(v, 0, 255, 0, 8);
      Serial.println(v);
      grid.randPoints(false, numPoints, seed*i);
    }
    grid.translate(0, count%8);
    grid.mirror(true, true);
    matrix.updateMatrix(grid.leds);
  }
}
