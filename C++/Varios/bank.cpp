//Daniel Charua A0101719
//Bank
#include<iostream>
using namespace std;
float calculateInterest(float money, float interest, int years);

int main() {
	float money;
	int years;
	float interest;
	float final;
	cout << "How much money are you gonna invest? " << endl;
	cin >> money;
	cout << "For how many years? " << endl;
	cin >> years;
	cout << "What is the yearly interest in porcentage? (100%-1%)" << endl;
	cin >> interest;
	interest = interest / 100;
    final= calculateInterest(money, interest, years);
	cout<<"============================="<<endl;
	cout<<"============== Final: "<<final<<endl;
}

float calculateInterest(float money, float interest, int years) {
	if (years == 0) {
		cout<<"============================="<<endl;
		cout<< "==Year: "<<years<<" === Amout: "<<money<<endl;
		return money;
	}
	else {
		float result;
		result=(1 + interest) * calculateInterest(money, interest, years - 1);
		cout<< "==Year: "<<years<<" === Amout: "<<result<<endl;
		return  result;
	}
}
	
