#include "LEDMatrix.h"
#include "Grid.h"
#include <SPI.h>
#include <Audio.h>
#include <Wire.h>
#include <SD.h>
#include <SerialFlash.h>


// GUItool: begin automatically generated code
AudioInputAnalog         adc1;           //xy=115,117
AudioFilterStateVariable filter1;        //xy=324,81
AudioAnalyzeFFT256       fft256_1;       //xy=466,200
AudioAnalyzePeak         peak1;          //xy=527,79
AudioConnection          patchCord1(adc1, fft256_1);
AudioConnection          patchCord2(adc1, 0, filter1, 0);
AudioConnection          patchCord3(filter1, 0, peak1, 0);
// GUItool: end automatically generated code

int curr = 1;
bool leds[8][8];

LEDMatrix matrix(10);
Grid grid;

void setup() {
  SPI.begin();
  Serial.begin(9600);
  matrix.init();
  matrix.clearMatrix();
  filter1.frequency(500);
  AudioMemory(12);
  
  for(int x = 0; x< 8; x++){
    for(int y = 0; y< 8; y++){
      leds[x][y] = false;
    }
  }

}

void loop() {
  /*
    grid.randPoints(false, 15);
    grid.mirror(true, true);
    matrix.updateMatrix(grid.leds);
    delay(150);
    */
  /*
  if(peak1.available()){
    float p = peak1.read(); //0 - 1
    if (p > .99) curr = 1;
    int pp = floor(p*7);
    pp = abs(pp-8)+1;
    matrix.sendMessage(5-curr, pow(2, pp));
    matrix.sendMessage(4+curr, pow(2, pp));
    Serial.println(p);
    curr++;
    if (curr > 4) curr = 1;
    delay(50);
  }*/
}
