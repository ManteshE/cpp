//============================================================================
// Name        : Adapter.cpp
// Author      : Mantesh
// Version     :
// Copyright   : Your copyright notice
// Description : 
//============================================================================

#include <iostream>
using namespace std;

class StudInfo {
public:
	virtual void display() = 0;
};

class Student {
private:
	int srNumber;
	string name;
public:
	Student(int srnumber, string name) {
		this->srNumber = srnumber;
		this->name = name;
	}

	void print() {
		cout << "Main Student Class" << endl;
		cout << "Sr Number : " << srNumber << endl;
		cout << "Student Name : " << name << endl;
	}
};

class StudentAdapter : public StudInfo, private Student {

public:

	StudentAdapter(int srNo, string name) : Student(srNo, name) {
		cout << "StudentAdapter : " << srNo <<" " << name << endl;
	}

	virtual void display() {
		print();
	}
};

int main() {
	cout << "Adapter example" << endl; // prints Adapter example
	StudentAdapter stud = StudentAdapter(7, "Mantesh");
	stud.display();
	return 0;
}
