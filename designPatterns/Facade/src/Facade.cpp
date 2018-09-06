//============================================================================
// Name        : Facade.cpp
// Author      : Mantesh
// Version     :
// Copyright   : Your copyright notice
// Description : 
//============================================================================

#include <iostream>
using namespace std;

class SubSystemA {
public:
	void print() {
		cout << "called SubSystemA" << endl;
	}
};

class SubSystemB {
public:
	void print() {
		cout << "called SubSystemA" << endl;
	}
};

class Facade {
public:
	Facade() {
		subA = new SubSystemA();
		subB = new SubSystemB();
	}

	void methodA() {
		subA->print();
	}
	void methodB() {
			subB->print();
	}
private:
	SubSystemA *subA;
	SubSystemB *subB;
};

int main() {
	cout << "Facade Pattern example" << endl; // prints Facade Pattern example
	Facade f;
	f.methodA();
	f.methodB();
	return 0;
}
