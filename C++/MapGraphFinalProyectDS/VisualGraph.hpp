/*
Final Proyect Data Structures
Daniel Charua
Isaac Halabe
30/11/16
*/


#include <iostream>
#include <string>
#ifndef VISUAL_GRAPH_HPP
#define VISUAL_GRAPH_HPP


class VisualGraph{
  private:
    //Variables
    std::string city;
    float positionx;
    float positiony;
    float radius;

  public:
    //Constructor
    VisualGraph(std::string c="", float x=0, float y=0, float r=0);
    //Get methods
    float getX();
    float getY();
    float getRadius();
    std::string getCity();
};

VisualGraph::VisualGraph(std::string c, float x, float y, float r){
  city = c;
  positionx= x;
  positiony= y;
  radius= r;
}

//Get methods
float VisualGraph::getX(){
  return positionx;
}
float VisualGraph::getY(){
  return positiony;
}
float VisualGraph::getRadius(){
  return radius;
}

std::string VisualGraph::getCity(){
  return city;
}

#endif
