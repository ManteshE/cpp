//============================================================================
// Name        : Proxy.cpp
// Author      : Mantesh
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
using namespace std;

class ISubject {
public:
	virtual void print() = 0;
	virtual ~ISubject(){}
};

class SubjectCpp : public ISubject {
public:
	void print() {
		cout << "called subject cpp" << endl;
	}
	~SubjectCpp(){}
};

class Proxy : ISubject {
public:
	Proxy() {
		sub = new SubjectCpp();
	}
	void print() {
		sub->print();
	}
	~Proxy(){}
private:
	ISubject *sub;
};

int main() {
	cout << "Proxy Pattern example" << endl; // prints Proxy Pattern example
	Proxy p;
	p.print();
	return 0;
}
