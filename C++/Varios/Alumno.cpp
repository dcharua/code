#include "Alumno.h" 

    Alumno::Alumno(string n, vector<int> c)
    {
       nombre = n;
       calif = c;
    }

    vector<int> Alumno::getCalif()
    {
       return calif;
    }

    string Alumno::getNombre()
    {
       return nombre;
    }
