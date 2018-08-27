/*
Final Proyect Data Structures
Daniel Charua
Isaac Halabe
30/11/16
*/


#include <iostream>
#include <string>
#ifndef HIGHWAY_HPP
#define HIGHWAY_HPP


class Highway{
  private:
    //Variables
    std::string from;
    std::string to;
    float cost;

  public:
    //Constructor
    Highway(std::string f="", std::string t="", float c=0);
    //Get methods
    std::string getFrom();
    std::string getTo();
    float getCost();
};

Highway::Highway(std::string f, std::string t, float c){
  from = f;
  to = t;
  cost = c;
}

//Get methods

std::string Highway::getFrom(){
  return from;
}

std::string Highway::getTo(){
  return to;
}

float Highway::getCost(){
  return cost;
}

#endif
