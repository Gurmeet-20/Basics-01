#include <iostream>
#include <string>
using namespace std;
class MovieData
{
private:
	string title;
	string director;
	int yearReleased;
	double runningTime;
public:
	string getTitle();
	string getDirector();
	int getYearReleased();
	double getRunningTime();
	void setTitle(string);
	void setDirector(string);
	void setYearReleased(int);
	void setRunningTime(double);
	void input();
	void output();
	MovieData();
	MovieData(string, string, int, double);
};
MovieData::MovieData()
{
	title = " ";
	director = " ";
	yearReleased = 2000;
	runningTime = 60;
}
MovieData::MovieData(string a, string b, int c, double d)
{
	title = a;
	director = b;
	yearReleased = c;
	runningTime = d;
}
string MovieData::getTitle()
{
	return title;
}
string MovieData::getDirector()
{
	return director;
}
int MovieData::getYearReleased()
{
	return yearReleased;
}
double MovieData::getRunningTime()
{
	return runningTime;
}
void MovieData::setTitle(string x)
{
	title = x;
}
void MovieData::setDirector(string x)
{
	director = x;
}
void MovieData::setYearReleased(int x)
{
	yearReleased = x;
}
void MovieData::setRunningTime(double x)
{
	runningTime = x;
}
void MovieData::input()
{
	cout << "Title? ";
	getline(cin, title);
	cout << "Director? ";
	getline(cin, director);
	cout << "Year? ";
	cin >> yearReleased;
	cout << "Minutes? ";
	cin >> runningTime;
	cin.ignore();
}
void MovieData::output()
{
	cout << title << "\t" << director << "\t" << yearReleased << "\t" <<
		runningTime << endl;
}
int main()
{
	MovieData a, b("Avatar", "James Cameron", 2009, 162);
	a.output();
	b.output();
	
	
	return 0;
}