class Grid{
  public:
    Grid();
    bool leds[8][8];
    void all(bool w);
    void checkerBoard(bool inverted, int s);
    void border(bool inverted, int o);
    void square(bool inverted, int s);
    void translate(int xx, int yy);
    void randPoints(bool inverted, int n);
    void mirror(bool updown, bool leftright);
    void bounceLed(int x1, int y1, int x2, int y2, int s);
   private:
    bool temp[8][8];
};

