#include <iostream>
#include <vector>

using namespace std;

template <class Type>

class Cola {
private:
	// Vector de type
	vector <Type> c;

public:
	Cola();

	void enqueue(Type x);
	Type dequeue();
	Type front();
	bool isEmpty();

	void print();
};

template <class Type>
Cola <Type>::Cola() {
}

template <class Type>
void Cola <Type>::enqueue(Type x)
{
	c.push_back(x);
}

template <class Type>
Type Cola <Type>::dequeue()
{
	Type x = c[0];
	c.erase(c.begin());
	return x;
}

template <class Type>
Type Cola <Type>::front()
{
	return c[0];
}

template <class Type>
bool Cola <Type>::isEmpty()
{
	if (c.size() == 0)
		return true;
	return false;
}

template <class Type>
void Cola <Type>::print()
{
	for (int i = 0; i <c.size(); i++) {
		cout << c[i] << endl;
	}
}
