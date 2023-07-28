#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;



class RationalException : public logic_error
{
private:
	int numenator;
	int denominator;
public:
	RationalException(int numenator, int denominator)
		: logic_error("Invalid Input")
	{
		this->numenator = numenator;
		this->denominator = denominator;
	}
	int getNumenator() 
	{
		return numenator;
	}

	int getDenominator() 
	{
		return denominator;
	}

};


class Rational
{
private:
	int numer;
	int denom;
public:
	int getNumer() const;
	int getDenom() const;
	void setNumer(int);
	void setDenom(int);
	void input();
	void output() const;
	Rational();
	Rational(int, int = 1);
	void reduce();
	friend Rational operator+(const Rational& a, const Rational& b);
	friend istream& operator>>(istream& strm, Rational& obj);

	bool isValid(int, int);
};
void Rational::reduce()
{
	int x = abs(numer);
	int y = abs(denom);
	// find minimum of x and y
	int min = x;
	if (y < x)
		min = y;
	// finding a common factor greater than 1
	int gcf = 1;
	for (int i = 2; i <= min; i++) {
		if (x % i == 0 && y % i == 0) {
			gcf = i;
		}
	}
	numer = numer / gcf;
	denom = denom / gcf;
	if (denom < 0)
	{
		numer = -numer;
		denom = -denom;
	}
}
Rational::Rational()
{
	numer = 0;
	denom = 1;
}
bool Rational::isValid(int n, int d) {
	return d !=0;
}
Rational::Rational(int numer, int denom)
{
	/*numer = x;
	if (y != 0)
		denom = y;
	else
		denom = 1;*/
	if (!isValid(numer, denom)) {
		throw RationalException(numer, denom);

		this->numer = numer;
		this->denom = denom;

	}

	reduce();
}
int Rational::getNumer() const
{
	return numer;
}
int Rational::getDenom() const
{
	if (denom == 0) {
		throw RationalException(numer, denom);
		
	}
	else
	return denom;
}
void Rational::setNumer(int x)
{
	numer = x;
	reduce();
}
void Rational::setDenom(int x)
{
	/*denom = x;*/
	/*if (denom == 0)
		denom = 1;*/
	if (!isValid(numer, denom)) {
		throw RationalException(numer, denom);
	}
	this->denom = denom;
	
}
void Rational::input()
{
	cout << "Numerator? ";
	cin >> numer;
	cout << "Denominator? ";
	cin >> denom;
	while (denom == 0)
	{
		cout << "Denominator can't be zero!\n";
		cout << "Denominator? ";
		cin >> denom;
	}


	reduce();
}
void Rational::output() const
{
	if (denom != 1)
		cout << numer << "/" << denom << endl;
	else
		cout << numer << endl;
}
Rational operator+(const Rational& a, const Rational& b)
{
	Rational c;
	c.numer = a.numer * b.denom + a.numer * b.denom;
	c.setDenom(a.getDenom() * b.getDenom());
	c.reduce();
	return c;
}
Rational operator-(const Rational& a, const Rational& b)
{
	int x = a.getNumer() * b.getDenom() - a.getDenom() * b.getNumer();
	int y = a.getDenom() * b.getDenom();
	return Rational(x, y);
}
Rational operator*(const Rational& a, const Rational& b)
{
	Rational c;
	c.setNumer(a.getNumer() * b.getNumer());
	c.setDenom(a.getDenom() * b.getDenom());
	c.reduce();
	return c;
}
Rational operator/(const Rational& a, const Rational& b)
{
	Rational c;
	c.setNumer(a.getNumer() * b.getDenom());
	c.setDenom(a.getDenom() * b.getNumer());
	c.reduce();
	return c;
}
void operator+=(Rational& a, const Rational& b)
{
	a = a + b;
}
void operator-=(Rational& a, const Rational& b)
{
	Rational c;
	c.setNumer(a.getNumer() * b.getDenom() - a.getDenom() * b.getNumer());
	c.setDenom(a.getDenom() * b.getDenom());
	c.reduce();
	a = c;
}
void operator*=(Rational& a, const Rational& b)
{
	Rational c;
	c.setNumer(a.getNumer() * b.getNumer());
	c.setDenom(a.getDenom() * b.getDenom());
	c.reduce();
	a = c;
}
void operator/=(Rational& a, const Rational& b)
{
	Rational c;
	c.setNumer(a.getNumer() * b.getDenom());
	c.setDenom(a.getDenom() * b.getNumer());
	c.reduce();
	a = c;
}
bool operator<(const Rational& a, const Rational& b)
{
	return (a.getNumer() * b.getDenom()) < (a.getDenom() * b.getNumer());
}
bool operator<=(const Rational& a, const Rational& b)
{
	return (a.getNumer() * b.getDenom()) <= (a.getDenom() * b.getNumer());
}
bool operator>(const Rational& a, const Rational& b)
{
	return (a.getNumer() * b.getDenom()) > (a.getDenom() * b.getNumer());
}
bool operator>=(const Rational& a, const Rational& b)
{
	return (a.getNumer() * b.getDenom()) >= (a.getDenom() * b.getNumer());
}
bool operator==(const Rational& a, const Rational& b)
{
	return (a.getNumer() * b.getDenom()) == (a.getDenom() * b.getNumer());
}
bool operator!=(const Rational& a, const Rational& b)
{
	return (a.getNumer() * b.getDenom()) != (a.getDenom() * b.getNumer());
}
Rational operator++(Rational& a) // prefix ++x
{
	a.setNumer(a.getNumer() + a.getDenom());
	return a;
}
Rational operator++(Rational& a, int n) // postfix x++
{
	Rational b = a;
	a.setNumer(a.getNumer() + a.getDenom());
	return b;
}
ostream& operator<<(ostream& strm, const Rational& obj)
{
	if (obj.getDenom() != 1)
		strm << obj.getNumer() << "/" << obj.getDenom();
	else
		strm << obj.getNumer();

	i/*f (obj.getDenom() == 0) {
		throw RationalException(obj.getNumer(), obj.getDenom());
	}*/

	

	return strm;
}
istream& operator>>(istream& strm, Rational& obj)
{
	
		cout << "Numerator? ";
		strm >> obj.numer;
		cout << "Denominator? ";
		strm >> obj.denom;

		/*if (obj.denom == 0) {
			throw RationalException(obj.numer, obj.denom);
		}*/


	obj.reduce();
	return strm;
}
int main()
{
	/*Rational a(6, -8);
	cout << a << " is the Rational number" << endl;;
	cin >> a;
	cout << a << " is the Rational number";*/

	Rational a;
	cin >> a;
	cout << a;


	try {
		Rational R;
		cout << "Numenator " << R.getNumer() << endl;
		cout << "Denominator" << R.getDenom() << endl;


	}
	catch (RationalException& ex) {
		cout << ex.what();
		cout << " Rational Number is" << ex.getNumenator() << "/"
			<< ex.getDenominator() << endl;
	}




	return 0;

}