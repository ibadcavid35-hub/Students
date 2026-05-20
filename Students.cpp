#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Student {
private:
	string _name;
	short _age;
	float _gpa;
public:
	Student(string name, short age, float gpa) {
		this->_name = name;
		this->_age = age;
		this->_gpa = gpa;
	}

	string getName() {
		return _name;
	}

	short getAge() {
		return _age;
	}

	float getGPA() {
		return _gpa;
	}
};

int main() {
	Student s1("Salman", 21, 90.0);
	Student s2("Tunar", 21, 95.5);
	Student s3("Elman", 22, 89.6);

	ofstream wfile("students.txt");

	if (wfile.is_open()) {
		wfile << "Name: " << s1.getName() << " | Age: " << s1.getAge() << " | GPA: " << s1.getGPA() << endl;
		wfile << "Name: " << s2.getName() << " | Age: " << s2.getAge() << " | GPA: " << s2.getGPA() << endl;
		wfile << "Name: " << s3.getName() << " | Age: " << s3.getAge() << " | GPA: " << s3.getGPA() << endl;
		wfile.close();
	}

	ifstream rfile("students.txt");

	if (rfile.is_open()) {
		string line;
		while (getline(rfile, line)) {
			cout << line << endl;
		}
		rfile.close();
	}

	return 0;
}