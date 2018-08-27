#include <iostream>
#include <cmath>

using namespace std;

class myexception: public exception
{
  virtual const char* what() const throw()
  {
    return "Estas dividiendo por cero";
  }
} myex;

float divide(int a, int b)
{
   float result = -1.0f;

     if(b == 0)
       throw myex;
     if(b < 0)
       throw -1; 
     result = (float)a/b;

   return result; 
}

int main()
{
   float w,z;
   int x, y;

   x = 10;
   y = -3;
   
   try {
     z = divide(x,y);
     w = 13.14f;
     w = pow(w,z);
     cout<<"Resultado "<< w <<endl;
   }
   catch(exception& e){
      cout<<e.what()<<endl;
   }
   catch(int e){
      cout<<"El divisor es un numero negativo"<<endl;
   }


   return 0;   
}
