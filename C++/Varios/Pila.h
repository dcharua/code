#include <iostream>
#include <vector>

using namespace std;

template <class Type>

class Pila {
private:
	// Vector de type
	vector <Type> p;

public:
	Pila();

	void push(Type x);
	Type pop();
	Type top();
	bool isEmpty();

	void print();
};

template <class Type>
Pila <Type>::Pila(){
}

template <class Type>
void Pila <Type>::push(Type x)
{
	p.push_back(x);
}

template <class Type>
Type Pila <Type>::pop()
{
	Type x = p[p.size() - 1];
	p.pop_back();
	return x;
}

template <class Type>
Type Pila <Type>::top()
{
	return p[p.size() - 1];
}

template <class Type>
bool Pila <Type>::isEmpty()
{
	if (p.size() == 0)
		return true;
	return false;
}

template <class Type>
void Pila <Type>::print()
{
	cout << p[p.size() - 1] << "<- tope" << endl;
	for (int i = (p.size()-2); i >= 0; i--)	{
		cout << p[i] << endl;
	}
}
