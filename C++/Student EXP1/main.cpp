/*
Daniel Charua / A01370874
Mauricio Rico / A01370874
Final Exam
14/09/16
*/
#define SIZE 16
#include "student.h"
#include "template.h"

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;
// Function definitions
void user_menu();
void printAll();
void printSt();
void printSb(int id);
void addStudent();
void sortAverage();
void readFromFile();
void writeToFile();
//Array of Students using the Array template
Array<Student> student(SIZE);
int main() {
  std::cout << "Grading Sistem" << std::endl;
  user_menu();
  return 0;
}
// User menu that is called on the main
void user_menu()
{
  //Firing Variables
  int i=0;
  int k=0;
  int id, subject;
  char option = 'a';
  readFromFile();

  // Setting average for all Students
  for (int i=0; i<SIZE-1; i++) student[i].setAverage();


    while (option != 'q'){
      std::cout << "\nUser Menu" << std::endl;
      // Menu options
      std::cout << "  a. View grades of all the students" << std::endl;
      std::cout << "  b. View grades by Student" << std::endl;
      std::cout << "  c. View grades by Subject" << std::endl;
      std::cout << "  d. Sort by average(operator overload)" << std::endl;
      std::cout << "  e. Modify Grades" << std::endl;
      std::cout << "  f. Add new student" << std::endl;
      std::cout << "  g. Erase existing student" << std::endl;
      // Finish the program
      std::cout << "  q. Quit program" << std::endl;
      std::cout << "Choose an option: ";
      std::cin >> option;

      if (option == 'a')
      {
      // View grades of all the students
        printAll();
      }
      if (option == 'b')
       {
        //View grades by Student
          printSt();
          std::cout << "--------------- " << std::endl;
          std::cout << "Select a student: ";
          std::cin >> id;
          student[id].setAverage();
          student[id].printStudent();
        }
      if (option == 'c')
      {
        //View grades by Subject
          std::cout << "--------------- " << std::endl;
          student[0].printSubject();
          std::cout << "Select a subject : ";
          std::cin >> id;
          std::cout<<endl;
          printSb(id);
      }
      if (option == 'd')
      {
        //Sort by average(operator overload)
        sortAverage();
        std::cout << "--------------- " << std::endl;
        std::cout << "After  sorting: ";
        printAll();
      }

      if (option == 'e')
      {
        //Modify Grades
        float grade;
        std::cout << "--------------- " << std::endl;
        printSt();
        std::cout << "--------------- " << std::endl;
        std::cout << "Select a student to modify grade: ";
        std::cin >> id;
        std::cout << "--------------- " << std::endl;
        student[id].printSubject();
        std::cout << "Select the subject : ";
        std::cin >> subject;
        std::cout << "Current grade: "<<student[id].getGrade(subject) <<" Enter new grade: ";
        std::cin >> grade;
        student[id].setGrade(grade, subject);
      }
      if (option == 'f')
      {
        //Add new student
        addStudent();
      }
      if (option == 'g')
      {
        //Erase existing student
        std::cout << "--------------- " << std::endl;
        printSt();
        std::cout << "--------------- " << std::endl;
        std::cout << "Select a student to erase: ";
        std::cin >> id;
        student[id].erase();
      }
    }
  writeToFile();
}

void readFromFile(){
  string name, subject;
  int i=0;
  float grade;
  char line[200];
  //Reading  from file
    fstream in("student.txt");
    if (in.is_open()){
      while (!in.eof()){
        in.getline(line, sizeof(line));
        string str(line);
        istringstream iss(str);
        iss >> name;
        student[i].setStudent(name);
        while ( iss ){
          iss >> subject;
          student[i].setSubject(subject);
          iss >> grade;
          student[i].setGrade(grade);
       }
      student[i].pop(); //Earsing double read in grade
      i++;
     }
    }
  //Erasing double read in student
  i--;
  student[i].setStudent("0");
  //Closing file
  in.close();
}

void writeToFile(){
  //Writing the data back to the file after closing program
  ofstream out("student.txt", ios::out |ios::trunc);
  if (out.is_open()) {
  for (int i = 0; i < SIZE; i++) {
  if(student[i].getStudent()!="0"){
    out << student[i].getStudent() << " " <<student[0].getSubject(0) << " " << student[i].getGrade(0) << " " << student[0].getSubject(1) << " " << student[i].getGrade(1)<< " " << student[0].getSubject(2) << " " << student[i].getGrade(2)<< " " << student[0].getSubject(3) << " " << student[i].getGrade(3)<< " " << student[0].getSubject(4) << " " << student[i].getGrade(4)<< " " << student[0].getSubject(5) << " " << student[i].getGrade(5)<<endl;
     }
   }
  }
  out.close();
}

//Fuction to print all students with grades
void printAll(){
  for(int i=0; i<SIZE-1; i++) {
    if(student[i].getStudent()!="0"){
      student[i].setAverage();
      student[i].printStudent();
  }
 }
}

//Fuction to print by student
void printSt(){
  std::cout << "--------------- " << std::endl;
  for (int i=0; i<SIZE-1; i++){
    if(student[i].getStudent()!="0")
     std::cout <<"  "<<i<<". Student: "<<student[i].getStudent()<<  std::endl;
 }
}

//Function to print by subject
void printSb(int id){
  for(int i=0; i<SIZE-1;i++){
    if(student[i].getStudent()!="0"){
     std::cout << "  Student: " << student[i].getStudent() << ", Grade: "<< student[i].getGrade(id) << std::endl;
   }
  }
}

//Function to add a new Student to the system
void addStudent(){
  string name;
  float g0, g1, g2, g3, g4, g5;
  for (int i=0; i<SIZE-1; i++){
    if(student[i].getStudent()=="0"){ //Checks if student is not full
      std::cout << "Enter the new student's name: ";
      std::cin >>name;
      student[i].setStudent(name);
      std::cout << "--------------- " << std::endl;
      std::cout << "Enter the grade for "<< student[0].getSubject(0)<< " (0 if student does not take that class): ";
      std::cin >> g0;

      std::cout << "Enter the grade for "<< student[0].getSubject(1)<< " (0 if student does not take that class): ";
      std::cin >> g1;

      std::cout << "Enter the grade for "<< student[0].getSubject(2)<< " (0 if student does not take that class): ";
      std::cin >> g2;

      std::cout << "Enter the grade for "<< student[0].getSubject(3)<< " (0 if student does not take that class): ";
      std::cin >> g3;;

      std::cout << "Enter the grade for "<< student[0].getSubject(4)<< " (0 if student does not take that class): ";
      std::cin >> g4;

      std::cout << "Enter the grade for "<< student[0].getSubject(5)<< " (0 if student does not take that class): ";
      std::cin >> g5;
      student[i].newStudent(g0, g1, g2, g3, g4, g5, student[0].getSubject(0), student[0].getSubject(1), student[0].getSubject(2), student[0].getSubject(3), student[0].getSubject(4), student[0].getSubject(5) );
      break;
    }else if (i==SIZE-2)std::cout << "Can not add more students, earse one first" << std::endl;
  }
}

//fuction to sort by average using insertionSort and operator overload
void sortAverage() {
	for (int i = 0; i< SIZE-1; i++){
		int j=i;
		while (j > 0 && student[j] < student[j-1]){
      student[j].swap(student[j-1]);
			j--;
		}
	}
}
