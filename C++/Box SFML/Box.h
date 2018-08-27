#include <iostream>

class Box{
  private:
    //Variables
    float positionx;
    float positiony;
    float height;
    float width;
    int red;
    int green;
    int blue;
  public:
    //Constructor
    Box(float x=0, float y=0, float h=0, float w=0, int r=0, int g=0, int b=0);
    //Get methods
    float getx();
    float gety();
    float geth();
    float getw();
    int getr();
    int getg();
    int getb();
};
