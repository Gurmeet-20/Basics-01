#include <iostream>
using namespace std;

int main(){

	double students;
	double movies;
	double sum = 0;
	double avg;
	int* x = nullptr;

	cout << "Enter the total number of students  : ";
	cin >> students; 

	x = new int[students];

	for (int i = 1; i <= students; i++) {
		cout << "Number of movies watched by student " << i << " : ";
		
		cin >> movies;  
		while (movies <0) {
			cout << "Error!!!! Please enter a valid number"<< endl;
			cout << "Number of movies watched by student " << i << " : ";
 cin >> movies;

		 }
		cout << endl;
		sum += movies;
	} avg = sum / students;

	cout << "Average movies watched per student : " << avg; 


	delete[]x; 
	x = nullptr;


	return 0;
}