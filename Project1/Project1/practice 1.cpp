#include <iostream>
#include <string>
using namespace std;

class Rectangle {
	int length;
	int width;
	int area;

public:
	
	int getArea();
	int getLength();
	int getWidth();

	void setArea(int, int);
	void setWidth(int);
	void setLength(int);


};
Rectangle::Rectangle() {
	length = 0;
	width = 0;
	area = 0;
}


int Rectangle::getLength() {
	return length;
}

int Rectangle::getWidth() {
	return width;
}

int Rectangle::getArea() {
	return area;
}


void Rectangle::setLength(int x) {
	length = x;


}

void Rectangle::setWidth(int x) {
	length = x;


}

void Rectangle::setArea(int x, int y) {
	area = x * y;

	

}





int main() {
	Rectangle A;

	int TempL;
	int TempW;
	int TempA;

	cout << "Enter lngth : ";
	cin >> TempL;
	A.setLength(TempL);

	cout << "Enter Width : ";
	cin >> TempW;
	A.setWidth(TempW);

	A.setArea(TempL, TempW);

	
	cout << A.getLength() << "\t" << A.getWidth() << endl << "Area is : " << A.getArea();







	return 0;
}
