#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
   ifstream archivo_entrada;
   char linea[128];
   int i=0;

   archivo_entrada.open("bitacora.txt");

   if(archivo_entrada.fail())
   {
      cout<<"Error al abrir el archivo"<<endl;
      return 0;
   }

   while(!archivo_entrada.eof())
   {
     archivo_entrada.getline(linea,sizeof(linea));
     cout<<i<<": "<<linea<<endl;
     i++;

     string str(linea);

     istringstream iss(str);
     do
     {
        string sub;
        iss >> sub;
        cout<<"Pedazo "<< sub<<endl;
     } while (iss);
   }

   archivo_entrada.close();

   return 0;
}
