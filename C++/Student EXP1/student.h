/*
Daniel Charua / A01370874
Mauricio Rico / A01370874
Final Exam
14/09/16
*/
/*
System for school grades:
Write a program using the Array class seen in class to keep track of student grades. Your program will need to follow these requirements:
- Create a class 'Student'. It contains an Array of grades, and optionally an array of subject names. Each student has 6 different subjects. A student has a name, and an average grade. Add operator overloads to sort by average grade.
- Your program will use an Array of Student to keep track of data. You should store at least 5 students. You should allow the user of the system to view grades by student, grades by subject, list the students sorted by average, modify grades for a specific student and subject.
- The data for your student grades should be read from a text file. If you modify the grades in your system, you should write the changes to the file.
Upload a zip file containing all your source code and the file you use for the data. Do NOT upload project files for Visual Studio or X-Code.
Remember to write correct code that is understandable, efficient and easy to maintain. This means:
- Write comments
- Use adequate coding and naming conventions
- Keep your program simple
- Write your contact details for other programmers to find you
-Write all your code and documentation in English*/

#include <iostream>
#include <string>
using namespace std;

class Student{
  // Private attributes from class Student
private:
int size;
int i;
int k;

string name;
float average;
string *subject;
float *grade;
void swapF(float *a, float *b);
void swapS(string *a, string *b);

//Public attributes from class Student
public:
//Constructors
Student();
//Destructor
~Student();

//Methods
string getStudent();
void setStudent(string n);

float getAverage();
void setAverage();

string getSubject(int index);
void setSubject(string s);

float getGrade(int index);
void setGrade(float g);
void setGrade(float g, int z);

void pop();

void printStudent();
void printSubject();

void newStudent(float g0, float g1, float g2, float g3, float g4,float g5, string s0, string s1, string s2, string s3, string s4, string s5);
void erase();
void swap(Student & other);
//operator overload function
bool operator< (Student & other);
};
