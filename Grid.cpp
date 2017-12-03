#include "Grid.h"
#include "arduino.h"

Grid::Grid(){
  //obj
}

void Grid::all(bool w){
  for(int x = 0; x< 8; x++){
      for(int y = 0; y< 8; y++){
        leds[x][y] = w;
      }
   }
}

void Grid::bounceLed(int x1, int y1, int x2, int y2, int s){

}


void Grid::checkerBoard(bool inverted, int s){
    for(int x = 0; x< 8; x++){
      for(int y = 0; y< 8; y++){
        if((y/s)%s != (x/s)%s) leds[x][y] = inverted;
        else leds[x][y] = !inverted;
    }
  }
}

void Grid::border(bool inverted, int o){
    int a = 0+o;
    int b = 7-o;
      for(int x = 0; x< 8; x++){
      for(int y = 0; y< 8; y++){
        if((x == a || y == b) || (x == b || y == a)) leds[x][y] = inverted;
        else leds[x][y] = !inverted;
    }
  }
}

void Grid::square(bool inverted, int s){
  all(inverted);
  for(int x = 4-(s/2); x < 4+(s/2); x++){
    for(int y = 4-(s/2); y < 4+(s/2); y++){
    leds[x][y] = !inverted;
    }
  }
}

void Grid::randPoints(bool inverted, int n){
  all(inverted);
  int rx = random(0, 8);
  int ry = random(0, 8);
  for(int i = 0; i < n; i++){
    while(leds[rx][ry] != inverted){
      rx = random(0, 8);
      ry = random(0, 8);
    }
    leds[rx][ry] = !inverted;
  }
}

void Grid::mirror(bool updown, bool leftright){
  if (updown){
    for(int x = 0; x< 4; x++){
      for(int y = 0; y< 8; y++){
        leds[7-x][y] = leds[x][y];
      }
    }
  }
  if (leftright){
     for(int y = 0; y< 4; y++){
      for(int x = 0; x < 8; x++){
        leds[x][7-y] = leds[x][y];
      }
    }
  }
  
}

void Grid::translate(int xx, int yy){
  for(int x = 0; x< 8; x++){
    for(int y = 0; y < 8; y++){
      int newX = x+xx;
      if (newX > 7) newX = abs(8-newX);
      if (newX < 0) newX = newX+8;

      int newY = y+yy;
      if (newY > 7) newY = abs(8-newY);
      if (newY < 0) newY = newY+8;
      
      temp[newX][newY] = leds[x][y]; 
    }
  }
    for(int x = 0; x< 8; x++){
      for(int y = 0; y < 8; y++){
        leds[x][y] = temp[x][y];
      }
    }
}

