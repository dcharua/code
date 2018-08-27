#include <iostream>
#include <cmath>

using namespace std;


int wait_time = 46;
try {
	cout << "Try block entered" << endl;
	if (wait_time > 30) {

		throw wait_time;

		cout << "Leaving try block" << endl;
	}
}

catch (int value) {

	cout << "Exception thrown with wait time equal to " << value << endl;

}

cout << "After catch block" << endl;

   int aa;
   cin >> aa;


}
}