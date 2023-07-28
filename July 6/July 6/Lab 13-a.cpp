#include <iostream>
#include <array>
using namespace std;

int main() {

	array<double, 5> arr;
	
	array<double, 5>::iterator I;

	I = arr.begin();

	for (int i = 0; i < arr.size(); i++) {
		cout << " Enter the Values : ";
		cin >> *I;
		I++;
	}

	I = arr.begin();
	for (int i = 0; i < arr.size(); i++) {
		cout << *I << endl;
		I++;
	}

	/*I = arr.begin();
	while (I != arr.end()) {
		cout << *I << endl;
		I++;
	}*/








	return 0;
}