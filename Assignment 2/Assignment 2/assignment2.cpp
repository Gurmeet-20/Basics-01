#include <iostream>
#include <string>
using namespace std;


//Base Class
class PersonData  {
protected:
	string lastName, firstName, address, city, state, zip, phone;
public:
	void setLastN(string);
	void setFirstN(string);
	void setAddress(string);
	void setCity(string);
	void setState(string);
	void setZip(string);
	void setphone(string);

	string getLastN();
	string getFirstN();
	string getAddress();
	string getCity();
	string getState();
	string getZip();
	string getphone();

	PersonData();
	PersonData(string a, string b, string c, string d, string e, string f, string g = " ");
	void display();


};

PersonData::PersonData(string a, string b, string c, string d, string e, string f, string g) {
	lastName = b;
	firstName = a;
	address = c;
	city = d;
	state = e;
	zip = f;
	phone = g;

}

PersonData::PersonData() {
	lastName = "N/A";
	firstName = "N/A";
	address = "N/A";
	city = "N/A";
	state = "N/A";
	zip = "N/A";
	phone = "N/A";

}

void PersonData::setLastN(string a) {
	lastName = a;
}
void PersonData::setFirstN(string b) {
	firstName = b;
}
void PersonData::setAddress(string c) {
	address = c;
}
void PersonData::setCity(string d) {
	city = d;
}
void PersonData::setState(string e) {
	state = e;
}
void PersonData::setZip(string f) {
	zip = f;
}
void PersonData::setphone(string g) {
	phone = g;
}

string PersonData::getLastN() {
	return lastName;
}
string PersonData::getFirstN() {
	return firstName;
}
string PersonData::getAddress() {
	return address;
}
string PersonData::getCity() {
	return city;
}
string PersonData::getState() {
	return state;
}
string PersonData::getZip() {
	return zip;
}
string PersonData::getphone() {
	return phone;
}

void PersonData::display() {
	cout << " Name:" << getFirstN() << " " << getLastN();
	cout << " \n Address " << getAddress() << ", " << getCity() << ", " << getState() << ", " << getZip();
	cout << "\n Phone Number: " << getphone();
}

//Derived Class 1--------------------------------------------------

class CustomerData : PersonData
{
protected:
	int customerNumber;
	bool mailingList;
public:

	int getCustomerN();
	void setCustomerN(int);

	bool getMailing();
	void setMailing(bool);

	CustomerData();
	CustomerData(int a, bool e = true);

	void display();
};

CustomerData::CustomerData(){

	customerNumber = 0000;
	mailingList = true;

}
CustomerData::CustomerData(int a, bool e ) {

	customerNumber = a;
	mailingList = e;

}

int CustomerData::getCustomerN() 
{
	return customerNumber;
}

bool CustomerData::getMailing() 
{
	return mailingList;
}
void CustomerData::setCustomerN(int a)
{
	customerNumber = a;
}
	
void CustomerData::setMailing(bool x) 
{
	mailingList = x;

}

void CustomerData::display() {
	cout << "\n Customer ID : " << getCustomerN();
	cout << "\n Opted for mail : " << getMailing();

}

//Derived Class 2------------------------------------------------

class PrefferedCustomer : CustomerData
{
private:
	double purchaseAmt;
	double discountLevel;
public:
	void setAmt(double);
	void setDiscount(double);

	double getAmt();
	double getDiscount();
	
	void benefits();
	PrefferedCustomer();

};

PrefferedCustomer::PrefferedCustomer() {

	purchaseAmt = 50;
	discountLevel = 0;


}

void PrefferedCustomer::setAmt(double a) {
	purchaseAmt = a;
}
void PrefferedCustomer::setDiscount(double a) {
	discountLevel = a;
}

double PrefferedCustomer::getAmt() {
	return purchaseAmt;
}
double PrefferedCustomer::getDiscount() {
	return discountLevel;
}

void PrefferedCustomer::benefits() {

	cout << "\n Total Purchase Amount : ";
	cin >> purchaseAmt;

	while (purchaseAmt < 0) {
		cout << "\n Invalid input !!! ";
		cout << "\n Total Purchase Amount : ";
		cin >> purchaseAmt;
	}

	if (purchaseAmt < 500) {
		cout << "Not Eligible dor discount :(";
	}
	else if(500 <= purchaseAmt < 1000) {
		discountLevel = 5.00;
		cout << "**Discount Earned** : " << discountLevel << "% \n";
	}
	else if (1000 <= purchaseAmt < 1500) {
		discountLevel = 6.00;
		cout << "**Discount Earned** : " << discountLevel << "% \n";
	}
	else if (1500 <= purchaseAmt < 2000) {
		discountLevel = 7.00;
		cout << "**Discount Earned** : " << discountLevel << "% \n";
	}
	else if (2000 <= purchaseAmt) {
		discountLevel = 10.00;
		cout << "**Discount Earned** : " << discountLevel << "% \n";
	}

	
}




int main() {

	PersonData a("Andy", "Will", "6098 23st", "Surrey", "BC", "V34T", "778-899-6789"),
		b("Dany","Jr","8182","New West","BC","V34t","678-909-3452"),
		c("Dora","Explorer","3453","Jungle st","BC","V3t5","523-987-2114");

	CustomerData x(29986, false),y;
	


	PrefferedCustomer m;

	

	a.display();
	x.display();
	m.benefits();






	return 0;
}