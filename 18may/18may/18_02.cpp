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
	void input();
	void output();
	// void input(); 
};
MovieData::MovieData() {
	title = "Evil dead";
	director = "simon Ester ";
	year = 2000;
	time = 160;
}
MovieData::MovieData(string a, string b, int c, double d)
{
	title = a;
	director = b;
	year = c;
	time = d;
}


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
void MovieData::input() {
	cout << "Movie Name : ";
	getline(cin, title);
	

	cout << "Movie Director : ";
	getline(cin, director);
	

	cout << "Movie Released Year : ";
	cin >> year;

	cout << "Movie Time : ";
	cin >> time;

	cin.ignore();
}
void MovieData::output() {

	cout << getTitle() << "\t" << getDirector() << "\t" << getYear() << "\t" << getTime() << endl;
	
}






int main() {

	MovieData a, b("Avatar t" , "James Cameron", 2009, 162.3);

	
	
	

	return 0;
}