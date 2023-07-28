#include<iostream>
#include<string>
#include<stdexcept>
using namespace std;

class RationalException : public logic_error {
private:
    int numerator;
    int denominator;
public:
    RationalException(int numerator, int denominator) : logic_error("Invalid Rational") {
        this->numerator = numerator;
        this->denominator = denominator;
    }
    int getNumerator() const {
        return numerator;
    }
    int getDenominator() const {
        return denominator;
    }
};

class Rational {
private:
    int numerator;
    int denominator;
public:
    bool isValid(int, int);
    int getNumerator();
    int getDenominator();
    void setNumerator(int numerator);
    void setDenominator(int denominator);
    void input();
    void output();
    void reducer(int numerator, int denominator);
    Rational() {
        numerator = 0;
        denominator = 1;
    }
    Rational(int numerator, int denominator = 1) {
        if (!isValid(numerator, denominator)) {
            throw RationalException(numerator, denominator);
        }
        this->numerator = numerator;
        this->denominator = denominator;
        reducer(numerator, denominator);
    }
};

void Rational::reducer(int numerator, int denominator) {
    int temp = 1;
    int tempnumerator = abs(numerator);
    int tempdenominator = abs(denominator);
    for (int i = 2; i <= tempnumerator && i <= tempdenominator; i++)
    {
        if (tempnumerator % i == 0 && tempdenominator % i == 0) {
            temp = i;
        }
    }
    tempnumerator = tempnumerator / temp;
    tempdenominator = tempdenominator / temp;
    if (numerator < 0) { tempnumerator = -tempnumerator; }
    if (denominator < 0) { tempnumerator = -tempnumerator; }
    this->numerator = tempnumerator;
    this->denominator = tempdenominator;
}
bool Rational::isValid(int numerator, int denominator)
{
    return denominator != 0;
}
int Rational::getNumerator() {
    return numerator;
}
int Rational::getDenominator() {
    return denominator;
}
void Rational::setNumerator(int numerator) {
    this->numerator = numerator;
}
void Rational::setDenominator(int denominator) {
    if (!isValid(numerator, denominator)) {
        throw RationalException(numerator, denominator);
    }
    this->denominator = denominator;
}
void Rational::input() {
    cout << "What is your numerator? ";
    cin >> numerator;
    cout << "What is your denominator? ";
    do {
        cin >> denominator;
        if (denominator == 0) {
            cout << "you walnut" << endl;
        }
    } while (denominator == 0);
    reducer(numerator, denominator);

}
void Rational::output() {
    cout << numerator << "/" << denominator;
    cout << endl;
}

int main() {
    try {
        Rational a;
        Rational b(5, 2);
        a.output();
        b.output();
        b.setDenominator(0);
    }
    catch (RationalException& ex) {
        cout << ex.what();
        cout << " you tried to do: " << ex.getNumerator() << "/" << ex.getDenominator() << endl;
    }



    return 0;
}