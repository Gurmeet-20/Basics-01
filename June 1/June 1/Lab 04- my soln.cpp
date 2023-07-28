#include <iostream>
#include <string>

using namespace std;

class Complex {
	double real;
	double imaginary;

public:
	void setRal(double);
	void setImg(double);
	double getReal() const;
	double getImg() const;
	double Magnitube() const;

	void input();
	void output();

	Complex(double a, double b = 2);
	Complex();

	Complex friend operator+(const Complex& a, const Complex& b);
	Complex friend operator-(const Complex& a, const Complex& b);
	Complex friend operator*(const Complex& a, const Complex& b);

	Complex friend operator++(Complex& a);
	Complex friend operator++(Complex& a, int n); //prefix
	Complex friend operator--(Complex& a);
	Complex friend operator--(Complex& a, int n);

};
// this is a pointer, this-> 
//use before name of member variable

Complex::Complex(double a, const double b) {

	real = a;
	imaginary = b;

}

Complex::Complex() {

	real = 1;
	imaginary = 2;
}

void Complex::setRal(double a) {

	this->real = a;
}
void Complex::setImg(double a) {

	this->imaginary = a;
}
double Complex::getReal() const {

	return this->real;

}
double Complex::getImg() const {

	return this->imaginary;

}

double Complex::Magnitube() const {

	double mag;

	mag = (real * real) + (imaginary * imaginary);

	sqrt(mag);

	return mag;

}

void Complex::input() {

	cout << "Enter the Real part : ";
	cin >> this->real;


	cout << endl << "Enter the Imaginary part : ";
	cin >> this->imaginary;


}

void Complex::output() {

	cout << this->real << " + j" << this->imaginary<< endl;

}

//Addition
Complex operator+(const Complex& a, const Complex& b) {
	Complex c;
	Complex d;

	c.real = a.real + b.real;
	c.imaginary = a.imaginary + b.imaginary;

	return c;
}

Complex operator+=(Complex& a, const Complex& b) {

	a = a + b;

	return a;


}

//Sub

Complex operator-(const Complex& a, const Complex& b) {

	Complex c;


	c.real = a.real - b.real;
	c.imaginary = a.imaginary - b.imaginary;

	return c;


}

Complex operator-=(Complex& a, const Complex& b) {

	a = a - b;

	return a;

}

//Multiplication

Complex  operator*(const Complex& a, const Complex& b) {

	Complex c;

	c.real = a.real * b.real - b.imaginary * b.imaginary;
	c.imaginary = a.real * b.imaginary + a.imaginary * b.real;

	return c;

}
Complex operator*=(Complex& a, const Complex& b) {

	a = a * b;
	return a;

}

Complex operator++(Complex& a) {

	a.real++;

	return a;



}
Complex  operator++(Complex& a, int n) {
	a.real++;

	return a;
}
Complex  operator--(Complex& a) {
	a.real--;

	return a;
}
Complex  operator--(Complex& a, int n) {

	a.real--;

	return a;
}



//> , < , <= , >= , == , !=

bool operator==(const Complex& a, const Complex& b) {

	return(a.getReal() == b.getReal() && a.getImg() == b.getImg());

}

bool operator!=(const Complex& a, const Complex& b) {

	return(a.getReal() != b.getReal() || a.getImg() != b.getImg());

}

bool operator<(const Complex& a, const Complex& b) {

	return(a.Magnitube() < b.Magnitube());

}

bool operator<=(const Complex& a, const Complex& b) {

	return(a.Magnitube() <= b.Magnitube());

}

bool operator>(const Complex& a, const Complex& b) {

	return(a.Magnitube() > b.Magnitube());

}

bool operator>=(const Complex& a, const Complex& b) {

	return(a.Magnitube() > b.Magnitube());

}





int main() {

	Complex a, b(3,4), c(1,3),d,e,f;
	a = b + c;
	d = c * b;
	

	b.output();
	c.output();
	a.output();
	d.output();


	return 0;
}


