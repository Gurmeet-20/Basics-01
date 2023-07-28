#include <iostream>
#include <string>
using namespace std;


// inheritence
class Employee {
protected:
	string FullName;
	int ENum;
	int HireYear;

public:

	void setName(string);
	void setNum(int);
	void setHire(int);

	string getName();
	int getNum();
	int getYear();
	void Display();

	Employee();

};
Employee::Employee() {
	FullName = " ";
	ENum = 30057;
	HireYear = 2000;

}


void Employee::setName(string a) {
	FullName = a;
}
void Employee::setNum(int a) {
	a = ENum;
}
void Employee::setHire(int a) {
	a = HireYear;
}

string Employee::getName() {
	return FullName;
}
int Employee::getNum() {
	return ENum;
}
int Employee::getYear() {
	return HireYear;

}

void Employee::Display() {

	cout << "Information of the employee \n";
	cout << FullName << "\t" << ENum << "\t" << HireYear;

}

class ProductionWorker : public Employee

{
	int shift;
	double Pay;
public:
	void setShift(int);
	void setPay(int);
	int getShift();
	int getPay();

	void newDisplay();

	ProductionWorker();

};
ProductionWorker::ProductionWorker() {
	shift = 1;
	Pay = 15;
}

void ProductionWorker::setShift(int a) {
	a = shift;

}
void ProductionWorker::setPay(int a) {
	a = Pay;
}
int  ProductionWorker::getShift() {
	return shift;
}
int ProductionWorker::getPay() {
	return Pay;
}
void ProductionWorker::newDisplay() {

	cout << "Information of the employee \n";
	cout << FullName << "\t" << ENum << "\t" << HireYear << endl;
	if (shift == 1) {
		cout << "Day Shift" << "\n" << Pay;

	}
	else {
		cout << "Night Shift" << "\n" << Pay;
	}

}



int main() {

	ProductionWorker x;
	x.setName("Jon");
	x.setNum(3568);
	x.setHire(2003);


	x.setShift(1);

	x.setPay(15.8);

	x.newDisplay();




	return 0;
}