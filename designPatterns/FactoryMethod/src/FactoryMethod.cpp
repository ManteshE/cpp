//============================================================================
// Name        : FactoryMethod.cpp
// Author      : Mantesh
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
using namespace std;

class Car {
public:
	virtual void showCar() = 0;
};

class AudiQ3 : public Car {
public:
	void showCar() {
		cout << "Created instance of AudiQ3" << endl;
	}
};

class AudiQ7 : public Car {
public:
	void showCar() {
		cout << "Created instance of AudiQ7" << endl;
	}
};

class FactoryCar {
public:
	static Car *car(int description) {
         if(description == 1) {
             return new AudiQ3;
         }
         if(description == 2) {
             return new AudiQ7;
         }
         return NULL;
	}
};

int main() {
	cout << "Eactory method example" << endl; // prints Eactory method example
	FactoryCar::car(1)->showCar();
	FactoryCar::car(2)->showCar();
	return 0;
}
