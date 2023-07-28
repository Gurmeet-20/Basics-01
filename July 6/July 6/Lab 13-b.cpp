#include<iostream>
#include<vector>
using namespace std;


int main() {

	vector<int> num(6);
	vector<int>::iterator I;

	I = num.begin();

	for (int i = 0; i < 6; i++) {
		cout << "Enter the value : ";
		cin >> *I;
		I++;

	}

	I = num.begin();

	for (int i = 0; i < 6; i++) {
		
		cout<< *I << "\t";

	}


	int min; 
	min = num[0];
	int max;
	max = num[0];
	
	for (int i = 0; i < 6; i++) {

		if (min >num[i]) {
			
			min = num[i];
		}
		if (max <num[i])
			max = num[i];
			
		

	}cout << "\n minimum is " << min << endl;
	cout << "max is " << max;

	

	
	





	return 0;
}