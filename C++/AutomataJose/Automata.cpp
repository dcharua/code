#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

// Map strucutre to save transitions
map<string, string> AFD;
// Vectors to store initial and final states
vector<string> initial_state, final_state;

void readFile();
void buildAutomata(string input);
void checkFinalState(string state, string qFinal[]);

int main(){
  int in;
  string input;
  while (in !=2){
  cout << endl;
  cout << "---------AFD------------"<<endl;
  cout << "-- 1. Evaluate string -- "<<endl;
  cout << "-- 2. Exit            -- "<<endl;
  cout << "------------------------"<<endl;
  cin >> in;
  if (in !=2){
    readFile();
    cout << "Please enter the string to evaluate:";
    cin >> input;
    buildAutomata(input);
    cout << endl;
    }
  }
}

void readFile(){
  ifstream file;
  string line, state1, language, state2;
  int count = 0;
  file.open("automata.txt");

  while(count<4){
    getline(file,line);
    stringstream ss(line);
    while(getline(ss, state1, ',')){
      if(count==2){
        initial_state.push_back(state1);
      }
      if(count==3){
        final_state.push_back(state1);
      }
    }
   count++;
 }
 while(!file.eof()){
  getline(file,line);
  stringstream ss(line);
  getline(ss, state1, ',');
  getline(ss, language, ':');
  getline(ss, state2);
  AFD[state1.append(language)] = state2;
  }
  file.close();
}

void buildAutomata(string input){
  string element, state1, state2, temp;
  state1 = initial_state.front();
  cout<< "--------------Transitions Table----------" <<endl;
  for (int i = 0; i<input.size(); i++){
    element = input[i];
    temp = state1;
    state2 = AFD[state1.append(element)];
    cout<<" --- From: "  << temp <<" --- To: " <<state2 << " --- With: "<< element << " ---" << endl;
    state1 = state2;
  }
  cout<< "-----------------------------------------" <<endl<<endl;
  if(std::find(final_state.begin(), final_state.end(), state2)!=final_state.end()){
    cout <<  "--ACCEPTED-- " << state2 << " is a final state"<<endl;
  }else{
    cout <<  "--NOT ACCEPTED-- "<<state2 << " is not a final state"<<endl;
  }
}
