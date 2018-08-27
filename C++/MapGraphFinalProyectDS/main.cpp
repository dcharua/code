/*
Final Proyect Data Structures
Daniel Charua
Isaac Halabe
30/11/16
*/

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Graph.hpp"
#include "VisualGraph.hpp"
#include "Highway.hpp"
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

//Golbal Variables

sf::Font font;
sf::Text text;
sf::Event event;
Graph<string, float> graph;
Vertex<string, float> * vertex;
std::vector<VisualGraph> v;
std::vector<Highway> h;

//-------------Function declarations--------------
// Configure Functions
void configure();
void setMap(sf::RenderWindow& window);
void setCities();
void setHighways();
void setFont();
void setStart();
void openMap();

//City Functions
void addNewCity(sf::Vector2i position, sf::RenderWindow& window);
void addNewCityManual();
void addNewCitytoFile(VisualGraph city);
bool checkCity(string city);

//Highway Functions
void addNewHighway();
void addNewHighwaytoFile(string from, string to, float cost);

//Path Functions
void cheapestpath();
float calculateCost(LinkedList<Vertex<std::string, float> *> * path);
float getCost(string from, string to);
void getHighwayCost();

VisualGraph getVisualGraph(string city);

//Paint Functions
void printCities();
void paintPath(LinkedList<Vertex<std::string, float> *> * path, float cost);
void drawPath(VisualGraph city1, VisualGraph city2, sf::RenderWindow& window);
void drawAllCities(sf::RenderWindow& window);
void drawAllHighways(sf::RenderWindow& window);
void drawCity(VisualGraph settings, sf::RenderWindow& window);

//Main Functions
int main(){
	configure();
	char option = 'a';
			//Main menu
			while (option != 'q'){
				std::cout << "\nUSER MENU\n";
				std::cout << "\ta. Open the map\n";
				std::cout << "\tb. Add a City by Coordinates\n";
				std::cout << "\tc. Built a highway\n";
				std::cout << "\td. Calculate cheapest path\n";
				std::cout << "\te. Get a Highway cost\n";
				std::cout << "\tf. Print BreadthFirst\n";
				std::cout << "\tg. Print DepthFirst\n";
				std::cout << "\tq. Quit program\n";
				std::cout << "Choose an option: ";
				std::cin >> option;


				switch(option){
					//Open the map
					case 'a':
						openMap();
					break;

					//Add a city by Coordinates
					case 'b':
					 addNewCityManual();
					 openMap();
					break;

					//Built a Highway
					case 'c':
						addNewHighway();
						openMap();
					break;

					//Calculate cheapestpath
					case 'd':
						cheapestpath();
					break;

					//Get Highway cost
					case 'e':
						getHighwayCost();
					break;

					//Print the graph BreadthFirst
					case 'f':
						setStart();
						graph.printBreadthFirst();
					break;

					//Print the Graph DepthFirst
					case 'g':
						setStart();
						graph.printDepthFirst();
					break;

					//Quit
					case 'q':
						std::cout << "Thank you for using CheapHighway system, Goodbye!" << std::endl;
						return 0;
					break;

					//Wrong input manager
					default:
						std::cout << "Option unavailable!" << std::endl;
					break;

				}
			}
}

// -----------Functions--------------
//Configure Function with all the configure functions
void configure(){
	setFont();
	setCities();
	setHighways();
	graph.setStart("Mexico");
}

//Function to Configurate Font, and Text
void setFont(){
	font.loadFromFile("Akashi.ttf");
	text.setFont(font);
	text.setFillColor(sf::Color::Black);
	text.setOutlineColor(sf::Color::White);
	text.setOutlineThickness(3);
	text.setCharacterSize(24);
}

//Function to load map background
void setMap(sf::RenderWindow& window){
  sf::Texture texture;
  if (!texture.loadFromFile("map.png"))
  {
    std::cout << "Error loading map image!" << std::endl;
  }
  sf::Sprite background(texture);
  window.draw(background);
}

//Function to read the cities from the file
void setCities(){
  string city;
  float x, y, r;
  char line[200];
  //Reading  from file
  ifstream in;
	in.open("cities.txt",ios::in);
  if (in.is_open()){
    while (in.getline(line, sizeof(line))){
      string str(line);
      istringstream iss(str);
      iss >> city;
      iss >> x;
      iss >> y;
      iss >> r;
      VisualGraph visualGraph(city, x, y, r);
			v.push_back(visualGraph);//pushing to the VisualGraph vector
      vertex = new Vertex<string, float>(city);
      graph.addVertex(vertex);//adding to the graph
		}
		in.close();
  }
}

//Function to draw a city on the Map
void drawCity(VisualGraph settings, sf::RenderWindow& window){
	sf::CircleShape circle;
	circle.setPosition(settings.getX(),settings.getY());
	circle.setRadius(settings.getRadius());
	circle.setFillColor(sf::Color::Blue);
	circle.setOutlineColor(sf::Color::Black);
	circle.setOutlineThickness(1);
	text.setPosition(circle.getPosition());
	text.setString(settings.getCity());
	window.draw(circle); //Draw circle with the above settings
	window.draw(text);//Draw city name with the above settings
}

//Function to draw all cities on the map
void drawAllCities(sf::RenderWindow& window){
	sf::CircleShape circle;
	//Interate the VisualGraph Vector to find all cities
	for(std::vector<VisualGraph>::iterator it = v.begin(); it != v.end(); ++it){
	circle.setPosition(it->getX(),it->getY());
	circle.setRadius(it->getRadius());
	circle.setFillColor(sf::Color::Blue);
	circle.setOutlineColor(sf::Color::Black);
	circle.setOutlineThickness(1);
	text.setPosition(circle.getPosition());
	text.setString(it->getCity());
	window.draw(circle); //Draw circle with the above settings
	window.draw(text); //Draw city name with the above settings
	}
}

//Function to load map, print all cities and all highways
void openMap(){
	sf::RenderWindow window (sf::VideoMode(1100, 800), "CheapHighway");
	window.clear(sf::Color::White);
	setMap(window); //set map background
	drawAllCities(window); //paint cities from vector info.
	drawAllHighways(window); //paint highways from vector info.

	text.setPosition(500, 20);
	text.setString("Close the window to go back to the menu");
	window.draw(text);
	text.setPosition(400, 70);
	text.setString("Or right click on the map to add a new city in that point");
	window.draw(text);

	window.display();

	std::cout << "Close the window to go back to the menu" << std::endl;
	std::cout << "Or right click on the map to add a new city in that point" << std::endl;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				//Checks if window is closed
				window.close();
				std::cout << "Map Closed!" << std::endl;
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
			{
				//Function to add new City with rightPress
				sf::Vector2i position = sf::Mouse::getPosition(window);//gets mouse position
				addNewCity(position, window);
				window.display();
			}
		}
	}
}

//Function to add a new city by Coordinates
void addNewCityManual(){
	float x, y, radius;
	string city;
	std::cout << "What is the name of the city?" << std::endl;
	std::cin >> city;
	std::cout << "What is the x coordinate of the city(0-1100)?" << std::endl;
	std::cin >> x;
	while (x>1100 || x<0) { //Error check
		std::cout << "x Coordinates must be from 0 to 1100, Try again" << std::endl;
		std::cout << "What is the x coordinate of the city(0-1100)?" << std::endl;
		std::cin >> x;
	}
	std::cout << "What is the y coordinate of the city(0-800)?" << std::endl;
	std::cin >> y;
	while (y>800 || y<0) { //Error check
		std::cout << "y Coordinates must be from 0 to 800, Try again" << std::endl;
		std::cout << "What is the y coordinate of the city(0-800)?" << std::endl;
		std::cin >> y;
	}
	std::cout << "What is the radius of the city (1 for every millon)" << std::endl;
	std::cin >> radius;
	if (radius<1) radius=1; //Can't be less than 1
	VisualGraph visualGraph(city, x, y, radius);
	v.push_back(visualGraph); //Push new city to the vector
	vertex = new Vertex<string, float>(city);
	graph.addVertex(vertex); //Add new city to graph
	addNewCitytoFile(visualGraph);  // Add new city to the file
	std::cout <<city<< " has been added" << std::endl;
}

//Function to add a new city by right clickind on the map
void addNewCity(sf::Vector2i position, sf::RenderWindow& window){
	char option;
	std::cout << "would you like to add a new city here? (y/n)" << std::endl;
	std::cin >> option;
	while(option != 'y' && option != 'n'){//Error check
		std::cout << "option unavailable try again" << std::endl;
		std::cin >> option;
	}
	if(option == 'y'){
		std::string city;
		float radius;
		std::cout << "What is the name of the city?" << std::endl;
		std::cin >> city;
		std::cout << "What is the radius of the city (1 for every millon)" << std::endl;
		std::cin >> radius;
		if (radius<1) radius=1; //Can't be less than 1
		VisualGraph visualGraph(city, position.x, position.y, radius);
		v.push_back(visualGraph); //Push new city to the vector
		vertex = new Vertex<string, float>(city);
		graph.addVertex(vertex); //Add new city to the graph
		drawCity(visualGraph, window); //Draw new city
		addNewCitytoFile(visualGraph); //Add new city to the map
		std::cout <<city<< " has been added, Close the map to go back to the main menu" << std::endl;
	}
	if(option == 'n')
		std::cout << "Won't add city, Close the map to go back to the main menu" <<std::endl;
}

//Function to add new city to the file
void addNewCitytoFile(VisualGraph city){
	ofstream out("cities.txt", ios::out |ios::app);
	if (out.is_open()) {
		out << city.getCity() << " " <<city.getX() << " " << city.getY()  << " " << city.getRadius() <<endl;
	}
	out.close();
}

//Function to read highways form the file
void setHighways(){
	string from, to;
	float cost;
	char line[200];
	ifstream in;
	in.open("highways.txt",ios::in);
	if (in.is_open()){//Error check
	  while (in.getline(line, sizeof(line))){ //File reading
	    string str(line);
	    istringstream iss(str);
	    iss >> from;
	    iss >> to;
	    iss >> cost;
			graph.addEdge(from, to, cost);//Add Highway as an Edge to the graph
			graph.addEdge(to, from, cost);//Highway is back and forth add Edge back
			Highway highway(from, to, cost);
			h.push_back(highway); //Push highway to highway vector
		}
		in.close();//File closing
  }
}

//Function to add a new highway
void addNewHighway(){
	string from, to;
	float cost;
	printCities();
	std::cout << "From what city does the highway starts?" << std::endl;
	std::cin >> from;
	while(!checkCity(from)){ //Error Check
		std::cout << "City does not exist, Try again!" << std::endl;
		std::cout << "From what city does the highway starts?" << std::endl;
		std::cin >> from;
	}
	std::cout << "In what city does the highway ends?" << std::endl;
	std::cin >> to;
	while(!checkCity(to)){// Error check
		std::cout << "City does not exist, Try again!" << std::endl;
		std::cout << "In what city does the highway ends?" << std::endl;
		std::cin >> to;
	}
	std::cout << "What's the cost of the new highway?" << std::endl;
	std::cin >> cost;
	while(cost<0){ //Error check
		std::cout << "Cost can NOT be negative, Try again1" << std::endl;
		std::cout << "What's the cost of the new highway?" << std::endl;
		std::cin >> cost;
	}
	graph.addEdge(from, to, cost); //Add Highway as an Edge to the graph
	graph.addEdge(to, from, cost); //Highway is back and forth and Edge back
	Highway highway(from, to, cost);
	h.push_back(highway); //Push highway to highway vector
	addNewHighwaytoFile(from, to, cost); //Add highway to the file
}

//Function to draw all highways
void drawAllHighways(sf::RenderWindow& window){
 ///Loop the haighway vector to drawAllHighways
	for(std::vector<Highway>::iterator it = h.begin(); it != h.end(); ++it){
		sf::Vertex line[] =
		{
	  	sf::Vertex(sf::Vector2f(getVisualGraph(it->getFrom()).getX(), getVisualGraph(it->getFrom()).getY()),sf::Color::Black ), //Set inital point of the line
		  sf::Vertex(sf::Vector2f(getVisualGraph(it->getTo()).getX(), getVisualGraph(it->getTo()).getY()), sf::Color::Black), //Set end point of the line
		};
	window.draw(line, 2, sf::Lines); //draw line on Map
	}
}


//Function to add new Highway to the file
void addNewHighwaytoFile(string from, string to, float cost){
	ofstream out("highways.txt", ios::out |ios::app);
	if (out.is_open()) {
		out << from << " " <<to << " " << cost <<endl;
	}
	out.close();
}

//Function to get the VisualGraph settings form city name
VisualGraph getVisualGraph(string city){
	//Loop the vector to find the VisualGraph Class form the city name given
	for(std::vector<VisualGraph>::iterator it = v.begin(); it != v.end(); ++it) {
		if (city == it->getCity())
	    return *it;
	}
	VisualGraph visualGraph("error", -1, -1, -1); //Error handler, error VisualGraph if city no found,
	return  visualGraph; //Should not happen if checkCity() Function is run first
}

//Function to check if city exists
bool checkCity(string city){
	//Loop the VisualGraph vector to find if city exists
	for(std::vector<VisualGraph>::iterator it = v.begin(); it != v.end(); ++it) {
		if (city == it->getCity())
	    return true;
	}
	return false;
}

//Function to print the name of all the cities
void printCities(){
	std::cout << std::endl;
	std::cout << "Current cities: " << std::endl;
	//Loop vector to print all city names
	for(std::vector<VisualGraph>::iterator it = v.begin(); it != v.end(); ++it)
		std::cout << it->getCity() << std::endl;
	std::cout << std::endl;
}

//Function to Calculate the cheapest path
void cheapestpath(){
	string from, to;
	float cost;
	LinkedList<Vertex<std::string, float> *> * path = nullptr;
	printCities();
	std::cout << "Where are you starting your trip from?" << std::endl;
	std::cin >> from;
	while (!checkCity(from)) {//Error check
		std::cout << "City does not exist, Try again!" << std::endl;
		std::cout << "Where are you starting your trip from?" << std::endl;
		std::cin >> from;
	}
	std::cout << "Where are you traveling to?" << std::endl;
	std::cin >> to;
	while(!checkCity(to)){//Error check
		std::cout << "City does not exist, Try again!" << std::endl;
		std::cout << "Where are you traveling to?" << std::endl;
		std::cin >> to;
	}
	path = graph.findPath(from, to);//Dijkstra Function to find cheapestpath
	std::cout << "Resulting path from " << from<< " to " << to<< " is: "<< std::endl << "\t";
	graph.printPath(path); //function to print cheapestpath
	cost = calculateCost(path); //Function to calculate Cost of cheapestpath
	std::cout << "The total toll is: " << cost << std::endl;
	paintPath(path, cost); //Function to red draw the cheapestpath
	delete path;
}

//Function to Calculate the cost of the cheapestpath
float calculateCost(LinkedList<Vertex<std::string, float> *> * path){
	Node<Vertex<std::string, float> *> * node = nullptr;
	Node<Vertex<std::string, float> *> * node2 = nullptr;
	Vertex<std::string, float> * vertex;
	float cost = 0;
	string from, to;

	node = path->getHead();
	node2 = path->getHead();
	while(node2 != nullptr){ //While there is another element in the LinkedList
		vertex = node->getData();
		from = (*vertex).getData(); //get city name
		if( node->getNext()!= nullptr){ //If there is a next element
			node = node->getNext();
			vertex = node->getData(); //get second city name
			to = (*vertex).getData();
			cost += getCost(from, to); //Function to get highway cost between cities
		}
		node2 = node->getNext(); //Two nodes to avoid double jump, since need to read two cities at a time
	}
	return cost;
}

//Function to the get cost form a highway
float getCost(string from, string to){
	//Loop the highway vector, check for the highway by cities names and returns cost
	for(std::vector<Highway>::iterator it = h.begin(); it != h.end(); ++it) {
		if ((from == it->getFrom() && to == it->getTo()) || (to == it->getFrom() && from == it->getTo()) )
			return it->getCost();
	}
	return -1; // for error handeling
}

//Function to set the start of the graph
void setStart(){
	string city;
	printCities();
	std::cout << "From what city do you want to Start?" << std::endl;
	std::cin >> city;
	while(!checkCity(city)){//Error check
		std::cout << "City does not exist, Try again!" << std::endl;
		std::cout << "From what city do you want to Start?" << std::endl;
		std::cin >> city;
	}
	graph.setStart(city); //set the start for breadth and Depth Functions
}

//Function to get cost of one Highway
void getHighwayCost(){
	string from, to;
	printCities();
	std::cout << "From what city?" << std::endl;
	std::cin >> from;
	while(!checkCity(from)){ //Error Check
		std::cout << "City does not exist, Try again!" << std::endl;
		std::cout << "From what city?" << std::endl;
		std::cin >> from;
	}
	std::cout << "To what city?" << std::endl;
	std::cin >> to;
	while(!checkCity(to)){ //Error Check
		std::cout << "City does not exist, Try again!" << std::endl;
		std::cout << "To what city?" << std::endl;
		std::cin >> to;
	}
	if(getCost(from, to) >= 0) //If Highway is negative highway does not exist
		std::cout << "The toll for this highway is: " << getCost(from, to) <<std::endl;
	else
		std::cout << "Highway does not exist" << std::endl;
}

//Function to print red Path and Open the Map
void paintPath(LinkedList<Vertex<std::string, float> *> * path, float cost){
	sf::RenderWindow window (sf::VideoMode(1100, 800), "CheapHighway");
	Node<Vertex<std::string, float> *> * node = nullptr;
	Node<Vertex<std::string, float> *> * node2 = nullptr;
	Vertex<std::string, float> * vertex;
	VisualGraph visual, visual2;
	int costInt = cost;
	string cost_string;

	window.clear(sf::Color::White);
	setMap(window); //Load map background

	node = path->getHead();
	node2 = path->getHead();
	while(node2 != nullptr){ //While there is another element in the LinkedList Node2
		vertex = node->getData();
		visual= getVisualGraph((*vertex).getData()); //get first VisualGraph
		if( node->getNext()!= nullptr){ //if there is another element in Node
			node = node->getNext();
			vertex = node->getData();
			visual2 = getVisualGraph((*vertex).getData());//get second VisualGraph
			drawPath(visual, visual2, window); //call function to paint red path
		}
		node2 = node->getNext(); //Two nodes to avoid double jump, since need to read two cities at a time
	}
	text.setPosition(500, 20);
	text.setString("Close the window to go back to the menu");
	window.draw(text);
	text.setPosition(600, 70);
	text.setString("The total toll is:          $");
	window.draw(text);
	cost_string =  std::to_string(costInt);
	text.setString(cost_string);
	text.setPosition(800, 70);
	window.draw(text);
	window.display();
	std::cout << "Close the window to go back to the menu" << std::endl;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				//Checks if window is closed
				window.close();
				std::cout << "Map Closed!" << std::endl;
			}
		}
	}
}

//Function to draw the red path (Cities and highways)
void drawPath(VisualGraph city1, VisualGraph city2, sf::RenderWindow& window){
sf::CircleShape circle;
circle.setPosition(city1.getX(),city1.getY());
circle.setRadius(city1.getRadius());
circle.setFillColor(sf::Color::Red);
circle.setOutlineColor(sf::Color::Black);
circle.setOutlineThickness(1);
text.setPosition(circle.getPosition());
text.setString(city1.getCity());
window.draw(circle);//draw city with settings
window.draw(text);//draw city name text with settings

circle.setPosition(city2.getX(),city2.getY());
circle.setRadius(city2.getRadius());
circle.setFillColor(sf::Color::Red);
circle.setOutlineColor(sf::Color::Black);
circle.setOutlineThickness(1);
text.setPosition(circle.getPosition());
text.setString(city2.getCity());
window.draw(circle);//draw city2 with settings
window.draw(text);//draw city name2 with settings

	sf::Vertex line[] =
	{
  	sf::Vertex(sf::Vector2f(city1.getX(), city1.getY()),sf::Color::Red ),//Change circle to red and set start point for line
  	sf::Vertex(sf::Vector2f(city2.getX(), city2.getY()),sf::Color::Red ),//Change circle to red and set end point for line
	};
	window.draw(line, 2, sf::Lines); //Draw the highway line
}
