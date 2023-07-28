#include <iostream>
#include <string>
using namespace std;

class NumDays {

private:	
	double WorkHrs;
	double WorkDays;

public:

	void setWorkHrs(double);
	void setWorkDays(double);
	double getWorkHrs() const;
	double getWorkDays() const ;
	
	void input();
	void output();
	

	NumDays();
	NumDays(double a, double b= 2);
	
	NumDays friend operator-(const NumDays& a, const NumDays& b);
	NumDays operator -- (); 
	NumDays operator -- (int);


};

NumDays::NumDays() {
	WorkHrs = 8;
	WorkDays = WorkHrs/8;

}
NumDays::NumDays(double a, double b) {
	WorkHrs = a;
	WorkDays = a/8 ;

}


void NumDays:: setWorkHrs(double a) {
	WorkHrs = a;
}
void NumDays::setWorkDays(double a) {
	WorkDays = a/8;
}
double NumDays::getWorkHrs() const {
	return WorkHrs;

}
double NumDays::getWorkDays() const {

	return WorkDays;

}



void NumDays::input() {
	
	
	cout << "Enter the number of hours worked : ";
	cin >> WorkHrs; cout << endl;

	cout << "Number of days worked : ";
	cout << WorkDays/8;

}

void NumDays::output() {

	cout << "hours worked : " << WorkHrs << endl;
	cout << "days worked : " << WorkHrs/8<< endl;
}

NumDays  operator-(const NumDays& a, const NumDays& b) {
	
NumDays c;
c.WorkHrs=	a.WorkHrs - b.WorkHrs;
c.WorkDays =( a.WorkDays - b.WorkDays)/8;

return c;
}

NumDays operator+(const NumDays& a, const NumDays& b) {
	NumDays c;
	c.setWorkHrs(a.getWorkHrs() + b.getWorkHrs());

	c.setWorkDays((a.getWorkDays() + b.getWorkDays())/8);

	return c;

}

NumDays operator++(NumDays& a) {

	a.setWorkHrs(a.getWorkHrs() + 1);

	return a;
}

NumDays operator++(NumDays& a, int i) {

	a.setWorkHrs(a.getWorkHrs() + 1);
	

	return a;

}

NumDays NumDays:: operator-- () {

	WorkHrs - 1;

	WorkDays = WorkHrs / 8;
	
	return *this;
}

NumDays NumDays::operator-- (int) {

	WorkHrs - 1; 

	WorkDays = WorkHrs / 8;

	return *this;

}







int main() {

	NumDays  three(24), four(15), z, y, x;

	z = three + four;
	z.output();
	
	y = three- four;
	y.output();
	
	three++;
	three.output();



	return 0;
 }
