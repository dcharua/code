/*
Daniel Charua / A01370874
Mauricio Rico / A01370874
Final Exam
14/09/16
*/
#include "student.h"

//Constructor
Student::Student(){
  size = 7;
  i=0;
  k=0;
  subject = new string[size];
  grade = new float [size];
  name= "0";
  average= 0;
}

//Destuctor
Student::~Student() {
	delete [] subject;
  delete [] grade;
}

//Set and get fuctions
string Student::getStudent() {
	return name;
}

void Student::setStudent(string n) {
	name=n;
}

string Student::getSubject(int index) {
	return subject[index];
}

void Student::setSubject(string s) {
	subject[i] = s;
  i++;
}

float Student::getGrade(int index) {
	return grade[index];
}

void Student::setGrade(float g) {
	grade[k] = g;
  k++;
}

//function overload to set specific grade
void Student::setGrade(float g, int z) {
	grade[z] = g;
}


float Student::getAverage() {
	return average;
}

//Funcion to calculate the average grade
void Student::setAverage(){
  average=0;
  int k=0;
  for(int i=0; i<size-1;i++){
    if(grade[i]!=0) {
      average+=grade[i];
      k++;
    }
  }
  average= (average/k);
}


//funcion used to clear double reading form file
void Student::pop(){
  k--;
  grade[k]=0;
}


//function to print students
void Student::printStudent(){
  std::cout << std::endl;
  std::cout << "----------------------" << std::endl;
  std::cout << "Student's name: " << name << std::endl;
  for(int i=0; i<size-1; i++){
    if(grade[i]!=0){
      std::cout << "  Subject: " << subject[i] << ", Grade: "<< grade[i]<<std::endl;
      }
    }
  std::cout << "  Average: " << average << std::endl;
  std::cout << "----------------------" << std::endl;
}

//Function to print the subjects
void Student::printSubject(){
  for(int i=0;i<size-1;i++){
    std::cout <<"  "<<i<<". Subject: "<<subject[i]<<  std::endl;
  }
}

//Fuction to add newStudent it was done in this "unefficient" way since the set and get were "in conflict"
void Student::newStudent(float g0, float g1, float g2, float g3, float g4, float g5, string s0, string s1, string s2, string s3, string s4, string s5){
  grade[0]=g0;
  grade[1]=g1;
  grade[2]=g2;
  grade[3]=g3;
  grade[4]=g4;
  grade[5]=g5;
  subject[0]= s0;
  subject[1]= s1;
  subject[2]= s2;
  subject[3]= s3;
  subject[4]= s4;
  subject[5]= s5;
}
//Function to erase Student
void Student::erase(){
  for (int i=0; i<size; i++){
    subject[i] = "0";
    grade[i] = 0;
  }
  name= "0";
  average= 0;
  std::cout << "-------------------" << std::endl;
  std::cout << "  Student erased" << std::endl;
}

//Operator Overload to swap Students
 bool Student::operator < ( Student & other){
  if(average< other.average) return true;
  else return false;
}

//swap function that swaps the student class
void Student::swap(Student & other){
  for (int i=0; i<size; i++){
    swapS(&subject[i], &other.subject[i]);
    swapF(&grade[i], &other.grade[i]);
  }
 swapS(&name, &other.name);
 swapF(&average, &other.average);
}

//Swaping floats
void Student::swapF(float *a, float *b) {
	float temp = *a;
	*a = *b;
	*b = temp;
}

//Swaping Strings
void Student::swapS(string *a, string *b) {
  string temp = *a;
	*a = *b;
	*b = temp;
}
