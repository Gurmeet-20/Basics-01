#include <iostream>
#include <string>
using namespace std;


class Numbers
{
private:
	int number;
	static string lessThan20[20];
	static string tens[10];
	static string hundred;
	static string thousand;
public:
	Numbers(int x) { number = x; }
	void print();
};
string Numbers::lessThan20[20] =
{ "zero", "one", "two", "three", "four", "five",
"six", "seven ", "eight", "nine", "ten",
"eleven", "twelve", "thirteen", "fourteen",
"fifteen", "sixteen", "seventeen", "eighteen",
"nineteen",
};
string Numbers::tens[10] =
{ " ", "ten ", "twenty ", "thirty", "forty",
"fifty", "sixty", "seventy", "eighty", "ninety",
};
//string Numbers::hundred = "hundred";
string Numbers::thousand = "thousand";
void Numbers::print()
{
	int remainder = number;
	if (remainder < 0 || remainder > 9999)
	{
		cout << "invalid input.";
	}
	else
	{
		cout << "The English description is:";
		if (number == 0)
		{
			cout << " zero";
		}
		int n_thousands = remainder / 1000;
		remainder %= 1000;
		if (n_thousands > 0)
		{
			cout << " " << lessThan20[n_thousands];
			cout << " " << thousand;
		}
		int n_hundreds = remainder / 100;
		remainder %= 100;
		if (n_hundreds > 0)
		{
			cout << " " << lessThan20[n_hundreds];
			cout << " " << hundred;
		}
		if (remainder >= 20)
		{
			int n_tens = remainder / 10;
			remainder %= 10;
			if (n_tens > 0)
				cout << " " << tens[n_tens];
		}
		if (remainder > 0)
		{
			cout << " " << lessThan20[remainder];
		}
	}
	cout << endl << endl;
}
int main()
{
	int number;
	cout << "Enter a whole dollar amount: ";
	cin >> number;
	Numbers n(number);
	n.print();
	return 0;
}