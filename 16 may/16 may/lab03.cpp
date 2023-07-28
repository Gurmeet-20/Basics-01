#include <iostream>
#include<string>
using namespace std;

struct Book {

	string Title;
	string Author;
	int numPages;
	double price;

};

void Read(Book a[],int size) {
	cout << " Enter the following info"<<endl;
for (int i = 0; i < size; i++) {

		cout << "Book Name- ";
	//	cin >> a[i].Title; cout << endl;
		getline(cin, a[i].Title);

		//cin >> a[i].Author; cout << endl;
		cout << "Book Author- ";
		getline(cin, a[i].Author);
		
		cout << "Book Pages : ";
		cin >> a[i].numPages; cout << endl;
		

		cout << "Book Price :";
		cin >> a[i].price; cout << endl;
		
	}



}

void Display(Book b[], int size) {

	for (int i = 0; i < size; i++) {
		cout << b[i].Title<< endl;
		cout << b[i].Author<< endl;
		cout << b[i].numPages << endl;
		cout << b[i].price << endl;
	}

}






int main() {

	
	Book arr[3];

	Read(arr, 3);
	Display(arr, 3);



	/*for (int i = 0; i < 3; i++) {

		cout << "Enter the book info"<< endl;
		cin >> arr[i].Title; cout << endl;
		cin >> arr[i].Author; cout << endl;
		cin >> arr[i].numPages; cout << endl;
		cin >> arr[i].price; cout << endl;


	}*/




	return 0;
}