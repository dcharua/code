#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

class myexception: public exception
{
  virtual const char* what() const throw()
  {
    return "Tiene menos de 4 caracteres";
  }
} myex;

bool tieneDigitos(string nom)
{
   string::size_type encontrado; 

   encontrado = nom.find("0",0);
   if(encontrado != string::npos)
     return true;
   encontrado = nom.find("1");
   if(encontrado != string::npos)
     return true;
   encontrado = nom.find("2");
   if(encontrado != string::npos)
     return true;
   encontrado = nom.find("3");
   if(encontrado != string::npos)
     return true;
   encontrado = nom.find("4");
   if(encontrado != string::npos)
     return true;
   encontrado = nom.find("5");
   if(encontrado != string::npos)
     return true;
   encontrado = nom.find("6");
   if(encontrado != string::npos)
     return true;
   encontrado = nom.find("7");
   if(encontrado != string::npos)
     return true;
   encontrado = nom.find("8");
   if(encontrado != string::npos)
     return true;
   encontrado = nom.find("9");
   if(encontrado != string::npos)
     return true;
   return false;
}

void revisa(string nombre)
{

     if(nombre.size() < 4)
       throw myex;
     if(nombre.at(0) != 'A')
       throw 13; 
     if(tieneDigitos(nombre) == false)
       throw 13.14f;

}

int main()
{
   string n;

   cout<<"Escribe el nombre del archivo: ";
   cin>>n;  
 
   try {
     revisa(n);
     //Ya paso la revision genero archivo
     ofstream archivo_salida;
     archivo_salida.open("numeros.txt");
     for(int i=1; i<11; i++)
        archivo_salida << i <<endl;
     archivo_salida.close();
     cout<<"Ya se escribio el archivo"<<endl;
   }
   catch(exception& e){
      cout<<e.what()<<endl;
   }
   catch(int e){
      cout<<"El nombre del archivo no con comienza con A"<<endl;
   }
   catch(float e){
      cout<<"El nombre del archivo no tiene digitos"<<endl;
   }


   return 0;   
}
