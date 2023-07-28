#include <iostream>

#include <string> 

using namespace std;


class Laptop {

    string  Manufacturer;
    string Processor;
    double screenSize;
    string colour;
    int isNew;

public:



    void setManufacturer(string);
    void setProcessor(string);
    void setScreen(double);
    void setColour(string);
    void setYear(int);
    void input();
    void output();

     string getManufacturer();
    string getProcessor();
    double getScreen();
    string getColour();
    int getYear();
    Laptop(string, string, double, string, int);
    Laptop();
};

Laptop::Laptop() {

    Manufacturer = "NA";
    Processor = "NA";
    screenSize = 10;
    colour = "Blue";
    isNew = 2005;

}



Laptop::Laptop(string a, string b, double d, string c, int y) {

    Manufacturer = a;
    Processor = b;
    screenSize = d;
    colour = c;
    isNew = y;

}


void Laptop::setManufacturer(string x) {

    Manufacturer = x;

}

void Laptop::setProcessor(string x) {

    Processor = x;

}

void Laptop::setScreen(double x) {

    screenSize = x;

}

void Laptop::setColour(string x) {

    colour = x;

}

void Laptop::setYear(int x) {

    isNew = x;

}

//void isNew(bool a) { 

// isNew; }

string Laptop::getManufacturer() {

    return Manufacturer;

}

string Laptop::getProcessor() {

    return Processor;

}

double Laptop::getScreen() {

    return screenSize;

}

string Laptop::getColour() {

    return colour;

}

int Laptop::getYear() {

    if (isNew > 2005) {

        return 1;

    } else

        return 0;
}

//int Laptop::isNew() { 

// return 0, 1; 

//} 



void Laptop::input() {

    cout << "enter name of the company " << endl;
    getline(cin, Manufacturer);

    cout << "Processer " << endl;
    getline(cin, Processor);

    cout << "Screen Size " << endl;
    cin >> screenSize;

    cin.ignore();

    cout << "Colour : " << endl;
    getline(cin, colour);

    cout << "year of Manufacturer " << endl;
    cin >> isNew;

    cin.ignore();

}

void Laptop::output() {

    cout << getManufacturer() << endl << getProcessor() << endl

        << getScreen() << endl << getColour() << endl << getYear();

}


int main() {

    Laptop A, B("Dell", "Intel i5", 20.1, "White", 2006);
    
    A.input();

    // B.input(); 
     A.output();

    B.output();


    return 0;
}