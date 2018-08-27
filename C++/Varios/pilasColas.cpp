#include <string>
#include <iostream>
#include "Pila.h"
#include "cola.h"


Pila<string>* invertirPila(Pila<string>* p)
{ 
   Pila<string> *nueva = new Pila<string>();
	   while (p->isEmpty() == false) {
		   nueva->push(p->pop());
	   }
   return nueva;
}

Cola<int>* invertirCola(Cola<int>* c)
{
   Cola<int> *nueva = new Cola<int>();
   Pila<int> *p=new Pila<int>();
   while (c->isEmpty() == false) {
	   p->push(c->dequeue());
   }
   while (p->isEmpty() == false) {
	   nueva->enqueue(p->pop());
   }
   return nueva;
}

Cola<float>* convertir(Pila<float>* p)
{
   Cola<float> *nueva = new Cola<float>();
   while (p->isEmpty() == false) {
	   nueva->enqueue(p->pop());
   }

   return nueva;
}

int main()
{
  Pila<string> *uno = new Pila<string>();
  uno->push("AB");
  uno->push("CD");
  uno->push("EF");
  uno->push("GH");
  uno->push("IJ");
  
  cout<<"Pila Original:"<<endl;
  uno->print();

  Pila<string> *dos = invertirPila(uno);

  cout<<"Pila invertida:"<<endl;
  dos->print();

  cout<<"------------------------"<<endl;

  Cola<int> *a = new Cola<int>();
  a->enqueue(1);
  a->enqueue(2);
  a->enqueue(3);
  a->enqueue(4);
  a->enqueue(5);
  a->enqueue(6);
  a->enqueue(7);

  cout<<"Cola original:"<<endl;
  a->print();

  Cola<int> *b = invertirCola(a);

  cout<<"Cola invertida:"<<endl;
  b->print();

  cout<<"------------------------"<<endl;

  Pila<float> *x = new Pila<float>();
  x->push(1.1f);
  x->push(2.2f);
  x->push(3.3f);
  x->push(4.4f);
  x->push(8.8f);
  
  cout<<"Pila Original:"<<endl;
  x->print();

  Cola<float> *y=convertir(x);
  
  cout<<"Cola generada:"<<endl;
  y->print();

  int ogg;
  cin >> ogg;
  return 0;
}
