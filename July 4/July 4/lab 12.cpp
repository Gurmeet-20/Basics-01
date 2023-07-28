#include <iostream>
using namespace std;

template<class T>

T total(T arr[], int size) {

	cout << "Enter the values : ";
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}
	

	T sum = 0;
	for (int i = 0; i < size; i++) {

		cout << arr[i]<<"\t";
		sum = sum + arr[i];

	}
	cout<<"\n" <<"Sum of the numbers : " << sum;

	return sum;
}

class Rational
{
private:
	int numenator;
	int denominator;
public:
	int getNum() const;
	int getDenom() const;
	void setNumer(int);
	void setDenom(int);
	void input();
	void output() const;
	Rational();
	Rational(int, int = 1);
	void reduce();
	friend istream& operator>>(istream& strm, Rational& obj);
};
void Rational::reduce() 
{
	int x = abs(numenator);
	int y = abs(denominator);
	
	int min = x;
	if (y < x)
		min = y;
	
	int gcf = 1;
	for (int i = 2; i <= min; i++) {
		if (x % i == 0 && y % i == 0) {
			gcf = i;
		}
	}
	numenator = numenator / gcf;
	denominator = denominator / gcf;
	if (denominator < 0)
	{
		numenator = -numenator;
		denominator = -denominator;
	}
}
Rational::Rational()
{
	numenator = 0;
	denominator = 1;
}
Rational::Rational(int x, int y)
{
	numenator = x;
	if (y != 0)
		denominator = y;
	else
		denominator = 1;
	reduce();
}
int Rational::getNum() const
{
	return numenator;
}
int Rational::getDenom() const
{
	return denominator;
}
void Rational::setNumer(int x)
{
	numenator = x;
	reduce();
}
void Rational::setDenom(int x)
{
	denominator = x;
	if (denominator == 0)
		denominator = 1;
	reduce();
}
void Rational::input()
{
	cout << "Numerator? ";
	cin >> numenator;
	cout << "Denominator? ";
	cin >> denominator;
	while (denominator == 0)
	{
		cout << "Denominator can't be zero!\n";
		cout << "Denominator? ";
		cin >> denominator;
	}
	reduce();
}
void Rational::output() const
{
	if (denominator != 1)
		cout << numenator << "/" << denominator << endl;
	else
		cout << numenator << endl;
}


Rational operator+(const Rational& a, const Rational& b)
{
	Rational c;
	c.setNumer(a.getNum() * b.getDenom() + a.getDenom() * b.getNum());
	c.setDenom(a.getDenom() * b.getDenom());
	c.reduce();
	return c;
}

ostream& operator<<(ostream& strm, const Rational& obj)
{
	if (obj.getDenom() != 1)
		strm << obj.getNum() << "/" << obj.getDenom();
	else
		strm << obj.getNum();
	return strm;
}
istream& operator>>(istream& strm, Rational& obj)
{
	cout << "Numerator? ";
	strm >> obj.numenator;
	cout << "Denominator? ";
	strm >> obj.denominator;
	while (obj.denominator == 0)
	{
		cout << "Denominator can't be zero!\n";
		cout << "Denominator? ";
		strm >> obj.denominator;
	}
	obj.reduce();
	return strm;
}








int main() {

	cout << " INTEGERS \n";
	int num[3];

	total<int>(num, 3);

	cout << "\n DOUBLES \n";

	double dec[3];

	total<double>(dec,  3);

	cout << "\n Ratioanl \n";
	Rational* a= new Rational[3];
	

	total<Rational>(a, 3);
	





	return 0;
}