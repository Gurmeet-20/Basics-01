#include <iostream>
#include <string>
#include "Rational.h"
using namespace std;



//class Rational {
//	int numerator;
//	int denominator;
//public:
//	void setDenominator(int);
//	void setNuminator(int);
//
//	int getDenomiator();
//	int getNumenator();
//
//	void reduce();
//	void input();
//	void output();
//	Rational();
//	Rational(int a, int = 1);
//
//
//
//};
Rational::Rational() {
	numerator = 1;
	denominator = 6;

}
Rational::Rational(int a, int b) {
	numerator = a;
	denominator = b;

	if (a == 0) {
		a = 1;
	}

	reduce();
}

void Rational::setDenominator(int a) {
	denominator = a;

	if (denominator == 0) {
		denominator = 1;
	}


}

void Rational::setNuminator(int b) {

	numerator = b;

}

int Rational::getDenomiator() {

	return denominator;
}
int Rational::getNumenator() {

	return numerator;
}

void Rational::reduce() {
	int x = abs(numerator);
	int y = abs(denominator);

	int min = x;
	if (y < x) {
		min = y;
	}

	int gcf = 1;
	for (int i = 2; i <= min; i++) {
		if (x % i == 0 && y % i == 0) {
			gcf = i;

		}
	}numerator /= gcf;
	denominator /= gcf;


	if (denominator < 0) {
		numerator = -numerator;
		denominator = -denominator;
	}


}

void Rational::input() {

	cout << "Enter Numenator";
	cin >> numerator;

	cout << "enter Denominator ";
	cin >> denominator;
	while (denominator == 0) {
		cout << "Denominator cannot be zero!!!";

		cout << "enter Denominator ";
		cin >> denominator;
	}

	reduce();

}


void Rational::output() {



	reduce();

	//if (denominator != 1 ) {
	cout << numerator << "/" << denominator << endl;
	//}
	//else {
	//	cout << numerator;
	//}
}

Rational operator+(Rational a, Rational b) {
	Rational c;

	//c.numenator= a.num * b.denom + a.denom * b.num 
	//c.denominator =a.denom * b.denom 

	
	c.setNuminator(a.getNumenator() * b.getDenomiator() + a.getDenomiator() * b.getNumenator());
	c.setDenominator(a.getDenomiator()* b.getDenomiator());
		return c;

}



//int main() {
//
//
//	Rational a, b(6), c(-6, -8), d(9, -6),z;
//	z = c + b;
//
//	
//	z.output();
//
//	/*a.input();
//	a.output();
//
//	b.output();
//	c.output();
//	d.output();*/
//
//
//	return 0;
//}