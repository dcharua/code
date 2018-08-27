#include <fstream>
#include <iostream>
#include <sstream>
#include<vector>
//Daniel Charua Garcia A01017419
//Deje el codigo original comentado para poder checarlo luego, por eso no lo "limpie"
using namespace std;

int main()
{
   ifstream archivo_entrada;
   char linea[128];
   int i=0;
   int k = 0;
   vector <string> v;

   archivo_entrada.open("bitacora.txt");

   if(archivo_entrada.fail())
   {
      cout<<"Error al abrir el archivo"<<endl;
      return 0;
   }

   while(!archivo_entrada.eof())
   {
     archivo_entrada.getline(linea,sizeof(linea));
     //cout<<i<<": "<<linea<<endl;
     i++;
	
     string str(linea);//convietre el arreglo de char a string
     
     istringstream iss(str);//iss es la particion del string por espacios
     
     
        string sub;
        iss >> sub;//mete el iss en sub 
        // cout<<"Pedazo "<< sub<<endl;//imprime el sub
		v.push_back (sub);
		k++;
     } 
   
   int h;
   int l;
   ofstream archivo_salida;
   archivo_salida.open("lista.txt");
   for (h = 0; h < v.size(); h++) {
	   int c = 1;
	   if (v[h] != "x") {
		   for (l = 0; l < v.size(); l++) {
			   if (h != l && v[h] == v[l]) {
					   c++;
					   v[l] = "x";
				   }
		   }
		  archivo_salida << "El usuario " << v[h] << " ingreso " << c << " veces" << endl;
	   }
   }
   
   archivo_entrada.close();
   cout << "Archivo creado" << endl;
   int a;
   cin >> a;
   return 0;
}
