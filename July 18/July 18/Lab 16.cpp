#include <iostream>
#include <string>
using namespace std;

class BasicShape {
protected:
	double area;
public:
	double getArea() {
		return area;
	}
	void setArea(double a) {
		area = a;
	}

	virtual void calcArea() = 0;
};

class Circle: public BasicShape
{
private:
	long int centerX;
	long int centerY;
	double radius;
public:
	long int getCenterX() {
		return centerX;
	}

	long int getCenterY() {
		return centerY;
	}

	void calcArea() {

		area = 3.14159 * radius * radius;

		
	}

	Circle(long int x, long int y, double r) 
	{
		centerX = x;
		centerY = y;
		radius = r;
		calcArea();
	}

};


class Rectangle :public BasicShape
{
private:
	long int width;
	long int length;

public:
	long int getWidth() {
		return width;

	}
	long int getLength() {
		return length;

	}

	void calcArea() {
		area = length * width;

	}

	Rectangle(long int l, long int w)
	{

		length = l;
		width = w;
		calcArea();
	}


};


int main() {
	 
	cout << "Areas of shapes \n";

		BasicShape* shape[3] = { new Circle(1,1,5), new Rectangle(5,7),
		new Circle(0,0,4) };

		for (int i = 0; i < 3; i++) {

			cout << shape[i]->getArea()<<"\n";
		}

		
	
	return 0;
}