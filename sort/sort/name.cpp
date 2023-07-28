#include<iostream>;
using namespace std;


int main() {


	string arr[5] = { "Boat","Fat", "Apple","Gst"
	};

	cout << "original array : ";
	for (int i = 0; i < 4; i++) {
		cout << arr[i] << "\t";
	}
	cout << endl;

	string temp;

	for (int i = 0; i < 4; i++) {
		for (int j = i; j < (4 - i); j++) {
			if (arr[j] > arr[i]) {

				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}


		}

		


	}

	cout << "sorted array : ";
	for (int i = 0; i < 4; i++) {
		cout << arr[i] << "\t";
	}


	return 0;
}


			