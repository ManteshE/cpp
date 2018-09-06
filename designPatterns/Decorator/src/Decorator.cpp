//============================================================================
// Name        : Decorator.cpp
// Author      : Mantesh
// Version     :
// Copyright   : Your copyright notice
// Description : 
//============================================================================

#include <iostream>
using namespace std;

class ICourtBooking {
public:
	virtual double cost() = 0;
	virtual ~ICourtBooking(){};
};

class GrassCourtBooking : public ICourtBooking {
public:
	double cost() {
		cout << "cost of grass court: "<< cost_val << endl;
		return cost_val;
	}
private:
	int cost_val = 200;
};

class HardCourtBooking : public ICourtBooking {
public:
	double cost() {
		cout << "cost of hard court: "<< cost_val << endl;
		return cost_val;
	}
private:
	int cost_val = 100;
};

class Decorator : public ICourtBooking {
	ICourtBooking *ICout;
public:
	Decorator(ICourtBooking *court) {
		ICout = court;
	}
	double cost() {
		return ICout->cost();
	}
};

class Coaching : public Decorator {
public:
	Coaching(ICourtBooking *court) : Decorator(court) {

	}
	double cost() {
		int cost_coaching = 100;
		int c = (Decorator::cost() + cost_coaching );
		cout << "cost of Coaching :" << cost_coaching << "\t court + coaching :"<< c << endl;
		return c;
	}
};

class BallPack : public Decorator {
public:
	BallPack(ICourtBooking *court) : Decorator(court) {

	}
	double cost() {
		int cost_ball = 100;
		int c = (Decorator::cost() + cost_ball);
		cout << "cost of BallPack  :" << cost_ball << "\t court + BallPacking :"<< c << endl;
		return c;
	}
};

int main() {
	cout << "Decorator example" << endl; // prints Decorator example
	ICourtBooking *grass = new GrassCourtBooking();
	grass = new Coaching(grass);
	grass = new BallPack(grass);
	grass->cost();

	ICourtBooking *hard = new HardCourtBooking();
	hard = new Coaching(hard);
	hard = new BallPack(hard);
	hard->cost();
	return 0;
}
