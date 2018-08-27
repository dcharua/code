#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include "linkedList.h"
#include "Box.h"
#include <sstream>

//Global Variables
LinkedList<Box> box_list;
int index=0;

//Functions declarations
void randomBox();
void customBox();
void printInfo(int p);
sf::RectangleShape passData(int p);
sf::Text printIndex(int p, sf::Font font);


int main(){
  //Initializing Variables
    int boxNumber;
    sf::Font font;
    sf::Text text;
    std::string indexString;
    sf::RectangleShape rectangle;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Make a Box");


// Configurating Font, Text and Window
    font.loadFromFile("Akashi.ttf");
    text.setFont(font);
    text.setFillColor(sf::Color::Black);
    text.setOutlineColor(sf::Color::White);
    text.setOutlineThickness(3);
    text.setCharacterSize(24);
    window.clear(sf::Color::White);

    //Main menu
    char option = 'a';
    while(window.isOpen()){
        while (option != 'q'){
            std::cout << "\nUSER MENU\n";
            std::cout << "\ta. Make an Print Random box\n";
            std::cout << "\tb. Make and Print Custom box\n";
            std::cout << "\tc. Clear window\n";
            std::cout << "\td. Print a Box by number\n";
            std::cout << "\te. Print all Boxes\n";
            std::cout << "\tf. Get Boxes Data\n";
            std::cout << "\tq. Quit program\n";
            std::cout << "Choose an option: ";
            std::cin >> option;

            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close(); //Checks if window is closed
            }

            switch(option){
              //Make an Print Random box
              case 'a':
                randomBox();
                rectangle = passData(index-1);
                window.draw(rectangle);
                text.setPosition(rectangle.getPosition());
                indexString =  std::to_string(index-1);
                text.setString(indexString);
                //text = printIndex(index-1, font);
                window.draw(text);
                printInfo(index-1);
                  break;

              //Make and Print Custom box
              case 'b':
                customBox();
                rectangle = passData(index-1);
                window.draw(rectangle);
                text.setPosition(rectangle.getPosition());
                indexString =  std::to_string(index-1);
                text.setString(indexString);
                //text = printIndex(index-1, font);
                window.draw(text);
                printInfo(index-1);
                  break;

              //Clear window
              case 'c':
                window.clear(sf::Color::White);
                  break;

              //Print a Box by number
              case 'd':
                std::cout << "What Box number do you want to print?" << std::endl;
                std::cin >> boxNumber;
                if (boxNumber <= index){
                  rectangle = passData(boxNumber);
                  window.draw(rectangle);
                  text.setPosition(rectangle.getPosition());
                  indexString =  std::to_string(boxNumber);
                  text.setString(indexString);
                  //text = printIndex(index-1, font);
                  window.draw(text);
                  printInfo(boxNumber);
                }
                else std::cout << "The box does not exist" << std::endl;
                  break;

              //Print all Boxes
              case 'e':
                window.clear(sf::Color::Black);
                for(int i=0; i<index; i++){
                  rectangle = passData(i);
                  window.draw(rectangle);
                }
                  break;

              //Get Boxes Data
              case 'f':
                for(int i=0; i<index; i++){
                  std::cout << std::endl;
                  std::cout << "Box Number: " << i<< std::endl;
                  printInfo(i);
                  std::cout << std::endl;
                }
                  break;

              //Quit
              case 'q':
                std::cout << "Bye" << std::endl;
                return 0;
                break;

              default:
                std::cout << "Option unavailable!" << std::endl;
                break;
            }
            window.display();
        }
    }
  return 0;
}

//Function to make a Random Box
void randomBox(){
  float x, y, w, h;
  int r, g, b;
  srand(time(NULL));
  w = rand()%270+50;
  h = rand()%270+50;
  r = rand()%256;
  g = rand()%256;
  b = rand()%256;
  x = (rand()% 470);
  y = (rand()% 470);
  box_list.insertTail(Box(x, y, w, h, r, g, b)); //Passing random data to the LinkedList Box
  std::cout << "Box number: " << index;
  std::cout  << std::endl;
  index++;
}

//Function to make a Custom Box
void customBox(){
  float x, y, w, h;
  int r, g, b;
  std::cout << "Enter the x position of the left corner: (5-795) " << std::endl;
  std::cin >> x;
  while(x>799||x<5){
    std::cout << "invalid number try again" << std::endl;
    std::cin >> x;
  }
  std::cout << "Enter the y position of the left corner: (5-595)" << std::endl;
  std::cin >> y;
  while(y>599||y<5){
    std::cout << "invalid number try again" << std::endl;
    std::cin >> y;
  }
  std::cout << "Enter the width of the box: (5-795)" << std::endl;
  std::cin >> w;
  while(w>799||w<5){
    std::cout << "invalid number try again" << std::endl;
    std::cin >> w;
  }

  std::cout << "Enter the height of the box: (5-595)" << std::endl;
  std::cin >> h;
  while(h>599||h<5){
    std::cout << "invalid number try again" << std::endl;
    std::cin >> h;
  }
  std::cout << "Enter the color in (r,g,b) r(0-255): " << std::endl;
  std::cin >> r;
  while(r>255||r<0){
    std::cout << "invalid number try again" << std::endl;
    std::cin >> r;
  }
  std::cout << "Enter the color in (r,g,b) g(0-255): " << std::endl;
  std::cin >> g;
  while(g>255||g<0){
    std::cout << "invalid number try again" << std::endl;
    std::cin >> g;
  }
  std::cout << "Enter the color in (r,g,b) b(0-255): " << std::endl;
  std::cin >> b;
  while(b>255||b<0){
    std::cout << "invalid number try again" << std::endl;
    std::cin >> b;
  }
  std::cout << "Box number: " << index;
  std::cout  << std::endl;
  box_list.insertTail(Box(x, y, w, h, r, g, b)); //Passing custom data to the LinkedList Box
  index++;
}

//Function to read form the LinkedList Box and pass it to a rectangle shape
sf::RectangleShape passData(int p){
  Box box;
  box = box_list.getDataAtPosition(p);
  sf::RectangleShape rectangle;
  rectangle.setSize(sf::Vector2f(box.getw(), box.geth()));
  rectangle.setPosition(box.getx(),box.gety());
  rectangle.setFillColor(sf::Color(box.getr(), box.getg(), box.getb()));
  rectangle.setOutlineColor(sf::Color(box.getg(), box.getb(), box.getr()));
  rectangle.setOutlineThickness(5);
  return rectangle;
}

/* Function to set the index text (does not work)
sf::Text printIndex(int p, sf::Font font){
  Box box;
  box = box_list.getDataAtPosition(p);

  //std::string indexString =  std::to_string(p);
  sf::Text text;


  text.setFont(font);
  text.setColor(sf::Color::Black);
  text.setCharacterSize(24);
  text.setPosition((box.getx() + (box.getw()/2) -2 ), (box.gety() + (box.geth()/2)) - 2);
  text.setString("h");
  return text;
}*/

//Function to print information of a box
void printInfo(int p){
  Box box;
  box = box_list.getDataAtPosition(p);
  std::cout << "Position of the Box (x-y) : (" << box.getx() << "-" << box.gety()<<")"<<std::endl;
  std::cout << "Size of the Box (width-height) : (" << box.getw() << "-" << box.geth()<<")"<<std::endl;
  std::cout << "Color of the Box (r-g-b) : (" << box.getr() << "-" << box.getg()<<"-"<<box.getb()<<")"<<std::endl;
}
