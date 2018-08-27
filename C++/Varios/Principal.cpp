#include "Alumno.h"
#include <map>

map<int,Alumno*> minilista;
map<int,Alumno*>::iterator ita;

void inicializa()
{
  vector<int> va;
  va.push_back(1);
  va.push_back(2);
  va.push_back(3);
  va.push_back(4);
  va.push_back(5);
  va.push_back(6);
  Alumno *a = new Alumno("AAA",va);

  minilista[123] = a;

  vector<int> vb;
  vb.push_back(10);
  vb.push_back(9);
  vb.push_back(9);
  vb.push_back(9);
  vb.push_back(9);
  vb.push_back(9);
  Alumno *b = new Alumno("BB",vb);

  minilista[456] = b;

  vector<int> vc;
  vc.push_back(10);
  vc.push_back(5);
  vc.push_back(6);
  vc.push_back(7);
  vc.push_back(8);
  vc.push_back(7);
  Alumno *c = new Alumno("BB",vc);

  minilista[789] = c;
}

void calculaPromedios()
{
   for(ita = minilista.begin(); ita != minilista.end(); ita++)
   {
     cout<<"Matricula "<<ita->first<<" "<<ita->second->getNombre()<<endl;
     vector<int> calificaciones = ita->second->getCalif();
     int prom = 0;
     for(int i=0;i<6;i++)
       prom = prom + calificaciones[i];

     prom = prom/6;
     cout<<"  Promedio "<<prom<<endl;
   }
}

int main()
{
   inicializa();
   calculaPromedios();

   return 0;
}
