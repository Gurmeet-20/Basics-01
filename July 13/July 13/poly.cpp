#include <iostream>
#include <string>
using namespace std;

class Ship {

protected:
	string ship;
	string year;
public:
	void setShip(string);
	void setYear(string);
	string getShip();
	string getYear();

	virtual void print() {

		cout << "Ship Info: \n";
		cout << "Ship Name : " << ship << "\n";
		cout << "Ship Build Year : " << year << endl;

	}

	Ship(string a, string b = "2000");
	Ship();

};

Ship::Ship(string a, string b) {

	ship = a;
	year = b;

}
Ship::Ship() {

	ship = "A00";
	year = "N/A";

}

void Ship::setShip(string a) {
	ship = a;
}
void Ship::setYear(string a) {
	year = a;
}
string Ship::getShip() {
	return ship;
}
string Ship::getYear() {
	return year;
}

//void Ship::print() {
//
//	cout << "Ship Info: \n";
//
//	cout << "Ship Name : " << ship << "\n";
//	cout << "Ship Build Year : " << year << endl;
//
//}

class CruiseShip : public Ship
{

private:
	int Mpassengers;
public:
	void setP(int);
	int getP();

	void print() {
		cout << "\n Cruise Ship Info: \n";
		cout << "Name : " << getShip();

		cout << " \n Capacity of Cruise Ship : " << Mpassengers << endl;
	}

	CruiseShip(string n, string y, int a = 0) : Ship(n, y) {
		Mpassengers = a;

	}
};




void CruiseShip::setP(int a) {
	Mpassengers = a;
}
int CruiseShip::getP() {
	return Mpassengers;
}

//void CruiseShip::print() {
//
//	cout << "\n Cruise Ship Info: \n";
//
//	cout << "Ship Build Year : " << year;*/
//
//	cout << " \n Capacity of Cruise Ship : " << Mpassengers << endl;
//
//}

class CargoShip : public Ship
{
private:
	int Ccapacity;
public:
	void setC(int);
	int getC();

	void print() {
		cout << "\n Cargo Ship Info: \n";
		cout << getShip();
		cout << " \n Capacity of Cargo Ship : " << Ccapacity << endl;

	}

	CargoShip(string n, string y, int a = 0) : Ship(n, y) {
		Ccapacity = a;

	}

};
//CargoShip::CargoShip(string a,int b) {
//	ship = a;
//	Ccapacity = b;
//}


void CargoShip::setC(int a) {
	Ccapacity = a;
}
int CargoShip::getC() {
	return Ccapacity;
}

//void CargoShip::print() {
//
//	cout << "\n Cargo Ship Info: \n";
//
//	/*cout << "Ship Name : " << ship << "\n";
//	cout << "Ship Build Year : " << year;*/
//	cout << " \n Capacity of Cargo Ship : " << Ccapacity << endl;
//
//}





int main() {

	//define array pinter to ships 

	Ship* ship[3] = { new Ship, new CargoShip ("Blueberry","2000", 500),
		new CruiseShip("Jack", "1988",2000)
	};




	/*Ship ship[3] = {  Ship,  CargoShip("Blueberry","2000",5000),
		 CruiseShip("Jack", "1988", 2000)
	};
	For all three ships only ship info will b printed 
	*/


	for (int i = 0; i < 3; i++) {

		ship[i]->print();
	}


	//a->print();

	//a.setShip("ZXY2");
	//a.setYear("2009");

	///*a.print();
	//b.print();*/

	//CruiseShip x;
	//x.setShip("Cruise100");
	//x.setYear("2020");
	//x.setP(2000);
	//x.print();

	//CargoShip y;
	//y.setShip("CargoZY455");
	//y.setYear("2023");
	//y.setC(300);
	//y.print();


	return 0;

}
