#include <iostream>
#include <cmath>

using namespace std;

float divide(int a, int b)
{
   float result = -1.0f;

   if(b == 0)
      cout<<"No se puede dividir entre cero"<<endl;
   else
     result = (float)a/b;

   return result; 
}

int main()
{
   float w,z;
   int x, y;

   x = 10;
   y = 0;

   z = divide(x,y);
   w = 13.14f;
   w = pow(w,z);

   cout<<"Resultado "<< w <<endl;

   return 0;   
}
