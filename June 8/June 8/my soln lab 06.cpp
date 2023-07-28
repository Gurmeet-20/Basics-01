#include <iostream>
#include <string>
using namespace std;

class Numbers {
	int num;
	static string lessThan20[20];
	static string tens[10];
	static string hundred;
	static string thousand;

public:
Numbers(int a= 100);
//~Numbers();
int getNum() ;
void setNum(int);
void print();



};
Numbers::Numbers(int a) {
	num = a;

	 if (num == 10) {
		cout << "ten";
	}
	else if (num == 100) {
		cout << "one" << " " << hundred << endl;
	}
	else if (num == 1000) {
		cout << "one" << thousand << endl;
	}

	
}
//Numbers::~Numbers() {
//	 string lessThan20[20];
//	 string tens[10];
//	 string hundred;
//	 string thousand;
//}

string Numbers::lessThan20[20]=
{  "zero","one", "two", "three", "four", "five",
	"six", "seven", "eight", "nine", "ten", "eleven",
	"twelve", "thirteen", "fourteen", "fifteen",
	"sixteen", "seventeen", "eighteen", "nineteen"
	 };

string Numbers::tens[10]  {
	"ten","twenty","thirty","fourty","fifty",
	"sixty","seventy","eighty","ninety"," "
};
string Numbers::hundred{
	"hundred"

};
string Numbers::thousand{
	"thousand"
};

void Numbers::setNum(int a) {
	num = a;

}

int Numbers::getNum()  {
	return num;
}




void Numbers::print() {

	cout << this->num << "\n";

	if (num >= 1 && num < 20) {
		for (int i = 0; i < 20; i++) {
			lessThan20[i] = lessThan20[num];

		}
		cout << this->lessThan20[num] << endl;

	}
	else if (num >= 20 && num < 100) {



		if ((num % 10) == 0) {
			for (int i = 0; i < 9; i++) {
				tens[i] = tens[(num / 10) - 1];


			}cout << tens[(num / 10)] << endl;
		}
		else {
			for (int i = 0; i < 10; i++) {
				tens[i] = tens[(num / 10) - 1];


			}cout << tens[num / 10] << " ";

			for (int i = 0; i < 9; i++) {
				lessThan20[i] = lessThan20[num % 10];

			}
			cout << lessThan20[(num % 10)] << endl;
		}

	}

	if (num > 100 && num < 1000) {


		for (int i = 0; i < 9; i++) {
			lessThan20[i] = lessThan20[num / 100];

		}
		//cout << lessThan20[num / 100] << " " << hundred << " ";


		for (int i = 0; i < 10; i++) {
			tens[i] = tens[(num % 100) / 10 - 1]; //o


		}
		//cout << tens[(num % 100) / 10] << " ";

		for (int i = 0; i < 9; i++) {
			lessThan20[i] = lessThan20[(num % 100) % 10];

		}

		cout << lessThan20[num / 100] << " " << hundred << " " << tens[(num % 100) / 10] << " "
			<< lessThan20[(num % 100) % 10];


	}

	if (num % 1000 == 0) {
		for (int i = 0; i < 9; i++) {
			lessThan20[i] = lessThan20[num / 1000];

		}
		cout << lessThan20[num / 1000] << " " << thousand << " ";

	}
	else if (num > 1000 && num < 10000) {


		for (int i = 0; i < 9; i++) {
			lessThan20[i] = lessThan20[num / 1000];

		}
		cout << lessThan20[num / 1000] << " " << thousand << " ";

		for (int i = 0; i < 9; i++) {
			lessThan20[i] = lessThan20[num / 100];

		} cout << lessThan20[num / 100] << " " << hundred << " ";


		for (int i = 0; i < 10; i++) {
			tens[i] = tens[(num % 100) / 10 - 1]; //o


		}
		cout << tens[(num % 100) / 10] << " ";

		for (int i = 0; i < 9; i++) {
			lessThan20[i] = lessThan20[(num % 100) % 10];

		}cout << lessThan20[(num % 100) % 10];

		//cout << lessThan20[num / 1000] << " " << thousand << " "<< lessThan20[num / 100] << hundred << " " << tens[(num % 100) / 10] << " "
			//<< lessThan20[(num % 100) % 10];


	}
}

//void Numbers::TwoDigit(int a) {
//
//	int x;
//	x = a % 10;
//
//	int y;
//	y = a / 10;
//
//
//	for (int i = 0; i < 10; i++) {
//		tens[i] = tens[y - 1];
//
//
//	}cout << tens[y] << " ";
//
//	for (int i = 0; i < x; i++) {
//		lessThan20[i] = lessThan20[x];
//
//	}
//	cout << lessThan20[x] << endl;
//}





		int main() {

			Numbers x(2325);
			x.print();

			//Numbers z(2500);
			//z.print();

			//Numbers x(335);
			//x.print();

			/*Numbers x(4);
			x.print();*/

			return 0;
		}