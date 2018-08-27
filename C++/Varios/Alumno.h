#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Alumno{
  private:
    string nombre;
    vector<int> calif;
  public:
    Alumno(string n, vector<int> c);
    vector<int> getCalif();
    string getNombre();
};
