#include "Pila.h"

Pila::Pila(){
}

void Pila::push(int x)
{
	p.push_back(x);
}

int Pila::pop()
{
	int x = p[p.size() - 1];
	p.pop_back();
	return x;
}

int Pila::top()
{
	return p[p.size() - 1];
}

bool Pila::isEmpty()
{
	if (p.size() == 0)
		return true;
	return false;
}

void Pila::print()
{
	cout << p[p.size() - 1] << "<- tope" << endl;
	for (int i = (p.size()-2); i >= 0; i--)	{
		cout << p[i] << endl;
	}
}