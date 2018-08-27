#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

//Golbal Variables
int sizeQ, sizeA, sizeQi, sizeQf;
string alphabet;
//Function Declaration
int readSize();
int readFile(string q[], string qFinal[], string qInitial[], string** transitions);
bool validateAlphabet(string token);
int getAlphabet(string token);
bool validateState(string token, string q[]);
int getState(string token, string q[]);
string checkChain(string** transitions, string chain, string q[], string qInitial[]);
void checkFinalState(string state, string qFinal[]);

int main(){
  //get size of automata
  readSize();
  //Local Variables
  string **transitions;
  string chain;
  transitions = new string *[sizeQ];
  for(int i = 0; i <sizeQ; i++)
    transitions[i] = new string[sizeA];
  string q[sizeQ];
  string qFinal[sizeQf];
  string qInitial[sizeQi];
  //Pass data form the file
  readFile(q, qFinal, qInitial, transitions);

  // User input
  std::cout << "Enter the string:";
  std::cin >> chain;
  //Check the string
  checkFinalState(checkChain(transitions, chain, q, qInitial), qFinal);
}

int readSize(){
 ifstream in;
 string line, token;
 int j = 0;
 in.open("text.txt");

 if(in.fail()){
  cout<<"Error reading file"<<endl;
  return 0;
 }
 while(j<4){
  getline(in,line);
  int i = 0;
  stringstream ss(line);
  while(std::getline(ss, token, ',')){
    i++;
  }
  if(j==0)
    sizeQ = i;
  if(j==1)
    sizeA = i;
  if(j==2)
    sizeQi = i;
  if (j==3)
    sizeQf = i;
  j++;
  }
  in.close();
  return 0;
}


int readFile(string q[], string qFinal[], string qInitial[], string** transitions){
  ifstream in;
  string line, token, token2, token3;
  int j = 0;
  int stateN, alphabetN;
  in.open("text.txt");

  if(in.fail()){
   cout<<"Error reading file"<<endl;
   return 0;
  }
  while(j<4){
    getline(in,line);
    int i = 0;
    stringstream ss(line);
    while(getline(ss, token, ',')){
      if(j==0)
        q[i] = token;
      if(j==1)
        alphabet += token;
      if(j==2)
        qInitial[i] = token;
      if(j==3)
        qFinal[i] = token;
      i++;
    }
   j++;
 }
 while(!in.eof()){
  getline(in,line);
  stringstream ss(line);
  getline(ss, token, ',');
  getline(ss, token2, ':');
  getline(ss, token3);
  if(!token.empty() && validateState(token, q) && !token2.empty() && validateAlphabet(token2) && !token3.empty())
    transitions[getState(token, q)][getAlphabet(token2)] = token3;
  }
  in.close();
  return 0;
}

bool validateAlphabet(string token){
  if (alphabet.find(token) <= sizeA)
    return true;
  else
    std::cout << "Check the transitions, symbol {" << token <<"} is not in alphabet" << '\n';
  return false;
}

int getAlphabet(string token){
  return alphabet.find(token);
}

bool validateState(string token, string q[]){
  for (int i = 0; i<sizeQ; i++){
    if (q[i] == token)
      return true;
  }
  std::cout << "Check the transitions, state {" << token <<"} does not exists" << '\n';
  return false;
}
int getState(string token, string q[]){
  for (int i = 0; i<sizeQ; i++){
    if (q[i] == token)
      return i;
  }
  return 0;
}

string checkChain(string** transitions, string chain, string q[], string qInitial[]){
  string state, prev;
  string c;
  for (int i = 0; i<chain.size(); i++){
    c = chain[i];
    if(validateAlphabet(c) && i==0){
      prev = state;
      state = qInitial[i];
      std::cout<< q[i] << " -> "<< state << " with string " << chain[i] <<'\n';
    }
    else if(validateAlphabet(c)){
      prev = state;
      state = transitions[getState(state, q)][getAlphabet(c)];
      std::cout<< prev << " -> "<< state << " with string " << chain[i] <<'\n';
    }
  }
  return state;
}

void checkFinalState(string state, string qFinal[]){
  for(int i = 0; i<sizeQf; i++){
    if(qFinal[i] == state){
      std::cout << "The string was accepted, final state " << state <<'\n';
      return;
    }
  }
  std::cout <<"The string was NOT accepted "<< state<< " is NOT a final state" <<'\n';
}
