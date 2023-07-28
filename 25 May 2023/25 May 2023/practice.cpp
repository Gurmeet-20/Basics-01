#include <iostream>
#include <string>
using namespace std;

class Rational {

	int num;
	int denom;
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

void Rational::reduce() {
	int x = abs(num);
	int y = abs(denom);

	int min = x;
	if (y < min)
		min = y;

	int gcf = 1;
		for(int i = 2; i <= min; i++) {

			if (x % i == 0 && y % i == 0) {

				gcf = i;
			}

		}
		num = num / gcf;
		denom = denom / gcf;

		if (denom < 0) {

			denom = -denom;
			num = -num;
		}

}

