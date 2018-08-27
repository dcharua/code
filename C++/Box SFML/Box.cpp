#include "Box.h"

//Constructor
Box::Box(float x, float y, float h, float w, int r, int g, int b){
  positionx= x;
  positiony= y;
  height= h;
  width= w;
  red = r;
  green =g;
  blue = b;
}

//Get methods
float Box::getx(){
  return positionx;
}
float Box::gety(){
  return positiony;
}
float Box::geth(){
  return height;
}
float Box::getw(){
  return width;
}
int Box::getr(){
  return red;
}
int Box::getg(){
  return green;
}
int Box::getb(){
  return blue;
}
