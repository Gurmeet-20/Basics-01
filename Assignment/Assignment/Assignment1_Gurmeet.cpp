#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
	string firstName;
	string lastName;
	string studentID;
	string phoneNumber;
	double gpa;

public:

	void setFirstN(string);
	void setLastN(string);
	void setStudentID(string);
	void setPhone(string);
	void setGpa(double);

	string getFirstN() ;
	string getLastN() ;
	string getStudentID();
	string getPhone();
	double getGpa();

	void input();
	void output();

	Student(string a, string b, string c, string d, double e);
	Student();

};

Student::Student(string a, string b = " N/A", string c = "3000", string d = "604-000-0000", double e = 0.1) {

	firstName = a;
	lastName = b;
	studentID = c;
	phoneNumber = d;
	gpa = e;

}
Student::Student() {
	firstName = " ";
	lastName = " ";
	studentID = " ";
	phoneNumber = " ";
	gpa = 0;
}


void Student::setFirstN(string a) {

	firstName = a;
}
void Student::setLastN(string a) {

	lastName = a;
}
void Student::setStudentID(string a) {

	studentID = a;
}
void Student::setPhone(string a) {

	phoneNumber = a;
}
void Student::setGpa(double a) {

	gpa = a;
}

string Student::getFirstN() {

	return firstName;
}
string Student::getLastN() {

	return lastName;
}
string Student::getStudentID() {

	return studentID;
}
string Student::getPhone() {

	return phoneNumber;
}
double Student::getGpa() {

	return gpa;
}

void Student::input() {

	cout << " Enter First Name : ";
	getline(cin, firstName);

	cout << " Enter Last Name : ";
	getline(cin, lastName);

	cout << " Enter Student ID : ";
	getline(cin, studentID);

	cout << " Enter Phone Number : ";
	getline(cin, phoneNumber);

	cout << " Enter Gpa : ";
	cin >> gpa;

	cin.ignore();

}
void Student::output() {

	cout << "\n";
	cout << "First Name: " << firstName << "\t";
	cout << "Last Name:  " << lastName << "\t";
	cout << "Student ID: " << studentID << "\t";
	cout << "Phone Number: " << phoneNumber << "\t";
	cout << "Gpa-  " << gpa << "\t";

	cout << endl;

}

class Course : public Student {

	string code;
	int section;
	int MaxStudents;
	int numStudents;

	Student* list;

public:
	Course(string a, int b, int c, int d = 0);
	Course(int);
	~Course();
	string getCode() const;
	int getSection() const;
	int getMaxStudents() const;
	int getNumStudents() const;
	void setCode(string);
	void setSection(int);

	void addStudentsp(Student);

	void displayALL();
	void displayByFirst(string);
	void displayByLast(string);
	void displayByPhone(string);
	void remove(string);
	
	void sortByFirstAsc();
	void sortByFirstDes();

	void sortByLastAsc();
	void sortByLastDes();

	void sortByIdAsc();
	void sortByIdtDes();

	void sortByPhoneAsc();
	void sortByPhoneDes();

	void sortByGpaAsc();
	void sortByGpaDes();

	

};
Course::Course(string a, int b, int c, int d) {
	code = a;
	section = b;
	MaxStudents = c;
	numStudents = 0;

	list = new Student[MaxStudents];


}

Course::Course(int s) {
	code = "CMPT";
	section = 1;
	MaxStudents = s;
	numStudents = 0;

	list = new Student[MaxStudents];

}
Course::~Course() {

	delete[] list;

}
string Course::getCode() const {
	return code;
}
int Course::getSection() const {
	return section;
}
int Course::getMaxStudents() const {
	return MaxStudents;
}
int Course::getNumStudents() const {
	return numStudents;
}
void Course::setCode(string a) {
	code = a;
}
void Course::setSection(int a) {
	section = a;
}

void Course::addStudentsp(Student x) {
	if (numStudents == MaxStudents) {
		cout << "Error!!!! Invalid input";
	}
	else {
		list[numStudents] = x;
		numStudents++;
	}
}

void Course::displayALL() {

	cout << "This is " << code << " " << "course" << endl;
	cout << "This Course has " << numStudents << "students : \n";

	for (int i = 0; i < numStudents; i++) {
		list[i].output();


	}
}
void Course::displayByFirst(string a) {
	cout << " This is data of" << a << endl;
	for (int i = 0; i < numStudents; i++)
		if (list[i].getFirstN() == a)
			list[i].output();
	cout << endl;

}

void Course::displayByLast(string b) {

	cout << " This is data of " << b << endl;
	for (int i = 0; i < numStudents; i++)
		if (list[i].getLastN() == b)
			list[i].output();
	cout << endl;

}

void Course::displayByPhone(string c) {

	cout << " This is data of " << c << endl;
	for (int i = 0; i < numStudents; i++)
		if (list[i].getPhone() == c)
			list[i].output();
	cout << endl;
}

void Course::remove(string a ) {


	for (int i = 0; i < numStudents; i++) {


		if (list[i].getPhone() == a) {
			list[i].getPhone() = list[numStudents - 1].getPhone();
			numStudents--;

			return;
		}
	}
}

bool operator==(Student& a, Student& b) {

	return (a.getFirstN() == b.getFirstN()||a.getLastN() == b.getLastN()||
		a.getStudentID() == b.getStudentID()|| a.getPhone() == b.getPhone()
		|| a.getGpa() == b.getGpa()
		);

}

bool operator>(Student& a, Student& b) {

	return (a.getFirstN() > b.getFirstN() || a.getLastN() > b.getLastN() ||
		a.getStudentID() > b.getStudentID() || a.getPhone() > b.getPhone() 
		|| a.getGpa() > b.getGpa()
		
		);

}

bool operator<(Student& a, Student& b) {

	return (a.getFirstN() < b.getFirstN() || a.getLastN() < b.getLastN() ||
		a.getStudentID() < b.getStudentID() || a.getPhone() < b.getPhone() 
		|| a.getGpa() < b.getGpa()
		
		);

}




void Course::sortByFirstAsc() {

	cout << "Asecnding order of First name";
	
	Student temp;
	
	for (int i = 0; i < numStudents; i++) {

		for (int j = i; j <( numStudents - i); j++) {
			if (list[j].getFirstN() > list[j + 1].getFirstN()) {
				
				

				temp = list[j].getFirstN();
				list[j].getFirstN() = list[j + 1].getFirstN();
				list[j + 1] = temp;
				cout << endl;
			}
			
			
		}
		
		list[i].output();
		
	
	}

	cout << endl;
}

void Course::sortByFirstDes() {
	cout << "Decending order of First name";

	Student temp;
	
	for (int i = numStudents; i >=0; i--) {

		for (int j = numStudents; j > (numStudents - i); j--) {
			if (list[j].getFirstN() > list[j - 1].getFirstN()) {

				temp = list[j].getFirstN();
				list[j].getFirstN() = list[j -1 ].getFirstN();
				list[j -1 ] = temp;
				
			}
		
		}

		list[i].output();
	}

	cout << endl;


}

void Course::sortByLastAsc() {
	cout << "Asecnding order of Last name";

	Student temp;

	for (int i = 0; i < numStudents; i++) {

		for (int j = i; j < (numStudents - i); j++) {
			if (list[j].getLastN() > list[j + 1].getLastN()) {



				temp = list[j].getLastN();
				list[j].getLastN() = list[j + 1].getLastN();
				list[j + 1] = temp;
				
			}


		}

		list[i].output();


	}

	cout << endl;
}
void Course::sortByLastDes() {
	cout << "Decending order of Last name";

	Student temp;

	for (int i = numStudents; i >= 0; i--) {

		for (int j = numStudents; j > (numStudents - i); j--) {
			if (list[j].getLastN() > list[j - 1].getLastN()) {

				temp = list[j].getLastN();
				list[j].getLastN() = list[j - 1].getLastN();
				list[j - 1] = temp;
				
			}
		
		}

		list[i].output();
	}

	cout << endl;
}

void Course::sortByIdAsc() {
	cout << "\n Asecnding order of Student ID";

	Student temp;

	for (int i = 0; i < numStudents; i++) {

		for (int j = i; j < (numStudents - i); j++) {
			if (list[j].getStudentID() > list[j + 1].getStudentID()) {



				temp = list[j].getStudentID();
				list[j].getStudentID() = list[j + 1].getStudentID();
				list[j + 1] = temp;
				
			}


		}

		list[i].output();


	}

	cout << endl;
}
void Course::sortByIdtDes() {
	cout << "Decending order of Student ID";

	Student temp;

	for (int i = numStudents; i >= 0; i--) {

		for (int j = numStudents; j > (numStudents - i); j--) {
			if (list[j].getStudentID() > list[j - 1].getStudentID()) {

				temp = list[j].getStudentID();
				list[j].getStudentID() = list[j - 1].getStudentID();
				list[j - 1] = temp;
				
			}
			
		}

		list[i].output();
	}

	cout << endl;
}

void Course::sortByPhoneAsc() {
	cout << "\n Asecnding order of Student ID";

	Student temp;

	for (int i = 0; i < numStudents; i++) {

		for (int j = i; j < (numStudents - i); j++) {
			if (list[j].getStudentID() > list[j + 1].getStudentID()) {



				temp = list[j].getStudentID();
				list[j].getStudentID() = list[j + 1].getStudentID();
				list[j + 1] = temp;

			}


		}

		list[i].output();


	}

	cout << endl;
}
void Course::sortByPhoneDes() {
	cout << "Decending order of Phone Number";

	Student temp;

	for (int i = numStudents; i >= 0; i--) {

		for (int j = numStudents; j > (numStudents - i); j--) {
			if (list[j].getPhone() > list[j - 1].getPhone()) {

				temp = list[j].getPhone();
				list[j].getPhone() = list[j - 1].getPhone();
				list[j - 1] = temp;

			}
			
		}

		list[i].output();
	}

	cout << endl;
}

/*void Course::sortByGpaAsc() {
	cout << "\n Asecnding order of GPA";

	Student temp;
	

	for ( int i = 0; i < numStudents; i++) {

		for (int j = i; j < (numStudents - i); j++) {
			if (list[j].getGpa() > list[j + 1].getGpa()) {

				temp = list[j].getGpa();
				list[j].getGpa() = list[j + 1].getGpa();
				list[j + 1] = temp;

			}


		}

		list[i].output();


	}

	cout << endl;
}*/

/*void Course::sortByGpaDes() {
	cout << "Decending order of Phone Number";

	Student temp;

	for (double i = numStudents; i >= 0; i--) {

		for (double j = numStudents; j > (numStudents - i); j--) {
			if (list[j].getGpa() > list[j - 1].getGpa()) {
				

				temp = list[j].getGpa();
				list[j].getGpa() = list[j - 1].getGpa();
				list[j - 1] = temp;

			}
			
		}

		list[i].output();
	}

	cout << endl;
}*/







int main() {

	Course x(10), y(15);

	x.setCode("Ecom");
	x.setSection(3);

	y.setCode("Busn");
	y.setSection(2);

	Student a("Alex", "Gomez", "32b5", "604-234-3456", 2.4),
		b("Elena", "William", "34b6", "721-234-3456", 3),
		c("Harry", "William", "35b6", "672-233-3232", 3), d("John"), e("Steve");

	x.addStudentsp(a);
	x.addStudentsp(b);
	x.addStudentsp(c);
	x.addStudentsp(d);
	x.addStudentsp(e);
	x.displayALL();
	
	

	x.sortByFirstAsc();
	x.sortByFirstDes();

	x.sortByIdAsc();
	x.sortByIdtDes();


	
	x.remove("672-233-3232");
	x.displayALL();

	




	return 0;
}