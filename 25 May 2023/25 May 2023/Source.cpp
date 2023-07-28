
#include <iostream>
#include <string>
#include "Rational.h"
using namespace std;




int main() {


	Rational a, b(6), c(-6, -8), d(9, -6), z;
	z = c + b;


	z.output();

	/*a.input();
	a.output();

	b.output();
	c.output();
	d.output();*/


	return 0;
}