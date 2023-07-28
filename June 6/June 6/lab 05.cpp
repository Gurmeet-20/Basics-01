#include <iostream>

#include <string> 

using namespace std;

class Laptop
{
private:
	string manufacturer;
	string processor;
	double screenSize;
	string color;
	bool isNew;
public:
	string getManufacturer() const;
	string getProcessor() const;
	double getScreenSize() const;
	string getColor() const;
	bool getIsNew() const;
	void setManufacturer(string);
	void setProcessor(string);
	void setScreenSize(double);
	void setColor(string);
	void setIsNew(bool);
	void input();
	void output() const;
	Laptop();
	Laptop(string, string = "AMD Ryzen", double = 17.3, string = "Silver",
		bool = false);
};
Laptop::Laptop()
{
	manufacturer = "Asus";
	processor = "Intel i5";
	screenSize = 15.6;
	color = "Black";
	isNew = true;
}
Laptop::Laptop(string a, string b, double c, string d, bool e)
{
	manufacturer = a;
	processor = b;
	screenSize = c;
	color = d;
	isNew = e;
}
string Laptop::getManufacturer() const
{
	return manufacturer;
}
string Laptop::getProcessor() const
{
	return processor;
}
double Laptop::getScreenSize() const
{
	return screenSize;
}
string Laptop::getColor() const
{
	return color;
}
bool Laptop::getIsNew() const
{
	return isNew;
}
void Laptop::setManufacturer(string x)
{
	manufacturer = x;
}
void Laptop::setProcessor(string x)
{
	processor = x;
}
void Laptop::setColor(string x)
{
	color = x;
}
void Laptop::setScreenSize(double x)
{
	screenSize = x;
}
void Laptop::setIsNew(bool x)
{
	isNew = x;
}
void Laptop::input()
{
	string newStr;
	cout << "Manufacturer? ";
	getline(cin, manufacturer);
	cout << "Processor? ";
	getline(cin, processor);
	cout << "ScreenSize? ";
	cin >> screenSize;
	cin.ignore();
	cout << "Color? ";
	getline(cin, color);
	cout << "Is this laptop new?(Y/N) ";
	getline(cin, newStr);

	if (newStr == "Y" || newStr == "y")
		isNew = true;
	else if (newStr == "N" || newStr == "n")
		isNew = false;
	else
		cout << "Invalid answer!!!" << endl;
	cout << endl;
}
void Laptop::output() const
{
	cout << "Manufacturer:\t" << manufacturer << endl;
	cout << "Processor:\t" << processor << endl;
	cout << "Screen Size:\t" << screenSize << endl;
	cout << "Color:\t " << color << endl;
	if (isNew)
		cout << "This laptop is a new laptop." << endl;
	else
		cout << "This laptop is a used laptop." << endl;
	cout << endl;
}



class ElectronicStore {
private:
	string storeName;
	string city;
	int numLaptops;  //no setters
	int maxLaptop; //no setters
	Laptop* list;
public:
	ElectronicStore(int);
	~ElectronicStore();
	string getStore() const;
	string getCity() const;
	int getNumLaptops() const;
	int getMaxLaptop() const;
	void setStore(string);
	void setCity(string);
	
	void addLaptop(Laptop);

	void displayALL();

	void sellLaptop(Laptop);
	 
	void displayBrand(string);

};
ElectronicStore::ElectronicStore(int s) {
	storeName = "Best Buy";
	city = "Vancouver";
	numLaptops = 0;
	maxLaptop = s;
		
	list = new Laptop[maxLaptop];

}
ElectronicStore::~ElectronicStore() {
	delete[] list;
}

string ElectronicStore::getStore() const {
	return storeName;
}
string ElectronicStore::getCity() const {
	return city;
}
int ElectronicStore::getNumLaptops() const {
	return numLaptops;
}
int ElectronicStore::getMaxLaptop() const {

	return maxLaptop;
}
void ElectronicStore::setStore(string) {
	 
	string a = storeName;

}
void ElectronicStore::setCity(string) {
	
	string b = city; 

}

void ElectronicStore::addLaptop(Laptop x) {
	if (numLaptops == maxLaptop) {
		cout << "Error!!!! please enter Valid number";
	}
	else {
		list[numLaptops] = x;
		numLaptops++;

	}
}

void ElectronicStore::displayALL() {
	cout << "Wlcome to" << storeName << " " << city << endl;
	cout << "This store has " << numLaptops << " laptops listed below : \n\n";

	for (int i= 0; i < numLaptops; i++) {    // maxLAptops display all the laptops so use numLaptops
		list[i].output();
	}

}

bool operator==(const Laptop& a, const Laptop& b)
{
	return (a.getManufacturer() == b.getManufacturer());
}

void ElectronicStore::sellLaptop(Laptop a ) {

	
	

	for (int i = 0; i < numLaptops; i++) {


		if (list[i] == a) {
			list[i] = list[numLaptops - 1];
			numLaptops--;

			return;
		}
	}cout << "This Laptop is not Available";


		/*if (a == b) {

			list[i] = list[numLaptops-1] ;
		}*/



		/*if (a == b) {


			list[i] = list[numLaptops-1];

		
		}*/
		
	}
void ElectronicStore::displayBrand(string s)
{
	cout << "These are " << s << " laptops we have in stock:\n";
	for (int i = 0; i < numLaptops; i++)
		if (list[i].getManufacturer() == s)
			list[i].output();
	cout << endl;
}



//void ElectronicStore::displayBrand(string) {
//	string a;
//
//	
//
//
//}


int main() {

	ElectronicStore x(100),y(1000);
	x.setStore("Visions");
	x.setCity("Burnaby");
	y.setStore("Joe's Computer");
	y.setCity("surrey");

	Laptop a("Dell", "intel i3", 15.5, "Black", true), b("hp","inter i5", 18, "White", true),c("Asus");


	x.addLaptop(a);
	x.addLaptop(a);
	x.addLaptop(a);
	x.addLaptop(b);
	x.addLaptop(b);
	x.addLaptop(c);

	x.displayALL();
	//x.displayALL(b);
	
	x.sellLaptop(b);

	x.displayALL();
	x.displayBrand("Dell");
	

	return 0;
}



