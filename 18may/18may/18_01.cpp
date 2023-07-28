#include <iostream>
#include <string>
using namespace std;

class MovieData {
	string title;
	string director;
	int year;
	double time;

	

public:
	string getTitle();
	string getDirector();
	int getYear();
	double getTime();
	
	void setTitle(string);
	void setDirector(string);
	void setYear(int);
	void setTime(double);
	// void input(); 
};


	string MovieData::getTitle() {
		return title;
	}

	string MovieData::getDirector() {
		return director;
	}

	int MovieData::getYear() {
		return year;
	}

	double MovieData::getTime() {
		return time;
	}


	void MovieData::setTitle(string x) {
		title = x;
	}
	void MovieData::setDirector(string y) {
		director = y;
	}
	void MovieData::setYear(int z) {
		year = z;

	}
	void MovieData::setTime(double t) {
		time = t;
	}
	//to access private variables of the class






int main() {

	MovieData a, b;
	string tempM;
	string tempD;
	int tempY;
	double tempT;

	cout << "Movie Name : ";
	getline(cin, tempM);
	a.setTitle(tempM);

	cout << "Movie Director : ";
	getline(cin, tempD);
	a.setDirector(tempD);

	cout << "Movie Released Year : ";
	cin >> tempY;
	a.setYear(tempY);

	cout << "Movie Time : ";
	cin >> tempT;
	a.setTime(tempT);

	cin.ignore();

	cout << "Movie Name : ";
	getline(cin, tempM);
	b.setTitle(tempM);

	cout << "Movie Director : ";
	getline(cin, tempD);
	b.setDirector(tempD);

	cout << "Movie Released Year : ";
	cin >> tempY;
	b.setYear(tempY);

	cout << "Movie Time : ";
	cin >> tempT;
	b.setTime(tempT);


	cout << a.getTitle() << "\t" << a.getDirector() << "\t" << a.getYear() << "\t" << a.getTime() << endl;
	cout << b.getTitle() << "\t" << b.getDirector() << "\t" << b.getYear() << "\t" << b.getTime() << endl;


	return 0;
}