#include <iostream>
//Daniel Charua A01017419
using namespace std;
unsigned long int iterativeFactorial(int number);
unsigned long int recursiveFactorial(int number);

int main()
{
	int number;
	int result;
	cout << "Enter Number:";
	cin >> number;

	result = iterativeFactorial(number);
	
	cout << "The Factorial is: " << result << endl;
	result = recursiveFactorial(number);

	cout << "The Factorial is: " << result << endl;
	
	
	int x;
	cin >> x;
	return 0;
}

unsigned long int iterativeFactorial(int number){
	unsigned long int res = 1;
	for (int i = number; i > 0; i--) {
		res *= i;
	}
	return res;

}
unsigned long int recursiveFactorial(int number) {
	if (number == 0) return 1;
	else {
		return number* recursiveFactorial(number - 1);
		
	}
}