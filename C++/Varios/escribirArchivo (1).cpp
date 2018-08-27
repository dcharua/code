#include <fstream>
#include <iostream>

using namespace std;

int main()
{
   ofstream archivo_salida;
   archivo_salida.open("datos.txt");

   archivo_salida << "Linea numero 1"<<endl;
   archivo_salida << "Linea numero 2"<<endl;
   archivo_salida << "a:b:c:d"<<endl;

   archivo_salida.close();

   return 0;
}
