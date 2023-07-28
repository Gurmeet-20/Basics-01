#include <iostream>
#include <string>
using namespace std;

class Numbers {
private:
	int number;
	static string list[30];
public:
	Numbers(int);
	void print();
};

string Numbers::list[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
						"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
						"eighteen", "nineteen", "twenty", "thirty", "fourty", "fifty", "sixy", "seventy",
						"eighty", "ninty", "hundred", "thousand", };

Numbers::Numbers(int number) {
	this->number = number;
}
void Numbers::print() {
	if (number <= 20) {
		cout << list[number];
	}
	else if (number < 30) {
		cout << list[20] << " ";
		if (number % 10 != 0) {
			cout << list[number % 10];
		}
	}
	else if (number < 40) {
		cout << list[21] << " ";
		if (number % 10 != 0) {
			cout << list[number % 10];
		}
	}
	else if (number < 50) {
		cout << list[22] << " ";
		if (number % 10 != 0) {
			cout << list[number % 10];
		}
	}
	else if (number < 60) {
		cout << list[23] << " ";
		if (number % 10 != 0) {
			cout << list[number % 10];
		}
	}
	else if (number < 70) {
		cout << list[24] << " ";
		if (number % 10 != 0) {
			cout << list[number % 10];
		}
	}
	else if (number < 80) {
		cout << list[25] << " ";
		if (number % 10 != 0) {
			cout << list[number % 10];
		}
	}
	else if (number < 90) {
		cout << list[26] << " ";
		if (number % 10 != 0) {
			cout << list[number % 10];
		}
	}
	else if (number < 100) {
		cout << list[27] << " ";
		if (number % 10 != 0) {
			cout << list[number % 10];
		}
	}
	else if (number < 1000) {
		cout << list[(number / 100) % 10] << " " << list[28] << " ";
		number -= (number / 100) % 10 * 100;
		print();
	}
	else if (number < 10000) {
		cout << list[(number / 1000) % 10] << " " << list[29] << " ";
		number -= (number / 1000) % 10 * 1000;
		print();

	}
}

int main() {
	Numbers a(5), b(89), c(999), d(1337);
	a.print();
	cout << endl;
	b.print();
	cout << endl;
	c.print();
	cout << endl;
	d.print();
}