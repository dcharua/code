#include "Gato.h"
#include <cstdlib>

int main()
{
   Gato g[10];
   int op;
   int gatos = 0;
   string nombre;

   while (1)
   {
       cout<<"1. Nuevo gato"<<endl;
       cout<<"2. Ver uno"<<endl;
       cout<<"3. Ver todos"<<endl;
       cout<<"4. Salir"<<endl;

       cout<<"Opcion: "; 
       cin>>op;

       switch ( op )
       {
          case 1:
              cout<<"Nombre: ";
              cin>>nombre;
              g[gatos].setNombre(nombre);
              gatos++;
              break;
          case 2:
              int x;
              cout<<"Dame numero de gato que quieres ver: ";
              cin>>x;
              cout<<"Gato es "<<g[x].getNombre()<<endl;
              break;
          case 3:
              for(int i=0; i<gatos; i++)
              {
                 cout<<i<<" es "<<g[i].getNombre()<<endl;
              }
              break;
          case 4:
              cout<<"ADIOS"<<endl;
              exit(0);
              break;
       }
   }

   return 0;
}
