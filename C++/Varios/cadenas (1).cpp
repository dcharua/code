#include <string>
#include <iostream>

using namespace std;

int main()
{
  //Dos formas de inicializar un objeto del tipo string
  string a;
  string b("pero la imaginacion te llevara a todas partes");
  a = "La logica te llevara de A a B";

  //Imprimir los strings originales:
  cout<<"String a: "<<a<<endl;
  cout<<"String b: "<<b<<endl;

  //Substring:
  string pedazo = a.substr(3,3);
  cout<<"Pedazo: "<<pedazo<<endl<<endl;

  //Accesar caracteres:
  cout<<"El caracter en la posicion 7 del string a: "<<a[7]<<endl<<endl;
  cout<<"El caracter en la posicion 11 del string b: "<<b.at(11)<<endl<<endl;

  //Concatenar:
  string c;
  c = a + b;
  cout<<"Concatenadas: "<<c<<endl<<endl;  

  //Insertar una coma:
  c.insert(29,", "); 
  cout<<"Coma insertada: "<<c<<endl<<endl;  

  //Eliminar una parte del string:
  string x = "Vaaaamos a iniciar";
  cout<<"Antes de eliminar: "<<x<<endl;
  x.erase(1,3);
  cout<<"Despues de eliminar: "<<x<<endl<<endl;

  //Comparar strings
  string w, y, z, m;
  w = "durazno";
  y = "kiwi";
  z = "durazno";
  m = "manzana";

  cout<<"w: "<<w<<" y: "<<y<<" z: "<<z<<" m: "<<m<<endl;

  if(w == z)
    cout<<"w y z son iguales"<<endl;
  if(m > z)
    cout<<"m es mayor que z"<<endl;
  if(y < z)
    cout<<"y es menor que z"<<endl;
  else
    cout<<"y NO es menor que z"<<endl;

  //Encontrar un substring en un string:
  string frase="El sol sale y la lluvia se seca";
  int posicion = frase.find("lluvia");

  cout<<"La posicion de la palabra lluvia es: "<<posicion<<endl;

  return 0;
}
