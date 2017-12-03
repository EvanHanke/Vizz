#include "Arduino.h"

class LEDMatrix{
  public:
    LEDMatrix(int a);
    int cspin;
    void init();
    
    void togglePixl(int x, int y);
    void displayRow(int r);
    void displayCollum(int c);
    void displayRandom();
    void displayCollumRandom(int c);

    void updateMatrix(bool matrix[8][8]);
    void sendMessage(byte one, byte two);
    void clearMatrix();
};

