#pragma once
#include <iostream>
#include <string>
using namespace std;

class Rational {
	int numerator;
	int denominator;
public:
	void setDenominator(int);
	void setNuminator(int);

	int getDenomiator();
	int getNumenator();

	void reduce();
	void input();
	void output();
	Rational();
	Rational(int a, int = 1);

};