#include <iostream>
#include <string>
#include<cmath>
using namespace std;





class vector2D {
private:
	double rho;
	double theta;
	double x, y;
public:
	void setRho(double);
	void setTheta(double);
	double getRho();
	double getTheta();
	
	double getX();
	double getY();

	double magnitude();

	vector2D();

	vector2D operator - (vector2D);
	vector2D operator + (vector2D);
	friend bool operator>(vector2D& a, vector2D& b);
	friend bool operator>=(vector2D& a, vector2D& b);
	friend bool operator<(vector2D& a, vector2D& b);
	friend bool operator<=(vector2D& a, vector2D& b);

	friend istream& operator>>(istream& strm, vector2D& obj);
	friend ostream& operator<<(ostream& strm, vector2D& obj);

};

vector2D::vector2D() {

	rho = 1;


	if (-180 > theta > 180) {
		cout << "Invalid!!!";
	}
	else
		theta = 1;

	x = 1;
	y = 1;
}

void vector2D::setRho(double a) {
	rho = a;
}
void vector2D::setTheta(double a) {
	theta = a;
}
double vector2D::getRho() {
	return rho;
}
double vector2D::getTheta() {
	return theta;
}

double vector2D::getX() {

	
	x = rho * cos(theta);

//	x *= 180 / 3.14;

	return x;

		// 1rad* 180/pi
}
double vector2D::getY() {

	
	y = rho * sin(theta);

//	y *= 180 / 3.14;

	return y;
}

double vector2D::magnitude() {

	double a,b,c;
	a = getX();
	b = getY();

	a *= a;
	b *= b;

	c = a + b;
	rho = sqrt(c);

	
		//atan2(y,x)

	return rho;
}



//member
vector2D  vector2D::operator - (vector2D) {
	
	vector2D a;

	a.x = a.getX() - this->getX();
	a.y = a.getY() - this->getY();

	rho = a.getX() - a.getY();
	theta = atan2(y, x);
	

	return a;
	

}
vector2D  vector2D::operator + (vector2D) {

	vector2D a;

	a.x = a.getX() + this->getX();
	a.y = a.getY() + this->getY();


	//double c;
	//c = a.x * a.x + a.y * a.y;

	//rho = a.x + a.y;
	//theta = atan2(y, x);
	a.rho = a.x + this->x;
	a.theta = a.y+ this->y ;


	return a;
}

//friend
bool operator>=(vector2D& a, vector2D& b) {
	return (a.magnitude() >= b.magnitude());
}
	
bool operator>(vector2D& a, vector2D& b) {
	return (a.magnitude() > b.magnitude());

	}

bool operator<(vector2D& a, vector2D& b) {
	return (a.magnitude() < b.magnitude());
}
bool operator<=(vector2D& a, vector2D& b) {
	return (a.magnitude() <= b.magnitude());
}





//non-member

bool operator==( vector2D& a,  vector2D& b)
{
	return (a.magnitude() == b.magnitude());
}

bool operator!=( vector2D& a, vector2D& b)
{
	return (a.magnitude() != b.magnitude());
}

ostream& operator<<(ostream& strm, vector2D& obj)
{
	cout << "Rho = ";
	strm << obj.getRho();
	cout << ", theta = ";
	strm << obj.getTheta();
	cout << endl;

	return strm;
}

istream& operator>>(istream& strm, vector2D& obj)
{
	cout << "Rho Value: ";
	strm >> obj.rho;
	cout << "\n Theta value: ";
	strm >> obj.theta;


	strm.clear();

	return strm;


}





int main() {

	vector2D a, b, c;

	a.setRho(5);
	a.setTheta(90);

	b.setRho(10);
	b.setTheta(100);

	c = a + b;

	cout << c;





	return 0;
}