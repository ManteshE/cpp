//============================================================================
// Name        : Observer.cpp
// Author      : Mantesh
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class IObserver {
public:
	virtual void update(float temp, float humidity, float pressure) = 0;
};

class ISubject {
public:
	virtual void registerObserver(IObserver *observer) = 0;
	virtual void unregisterObserver(IObserver *observer) = 0;
	virtual void notifyObserver() = 0;
};

class WhetherData : public ISubject {
	std::vector<IObserver *> observers; // observers
	float temp = 0.0f;
	float humidity = 0.0f;
	float pressure = 0.0f;
public:
	void registerObserver(IObserver *o) {
		cout<<"register..."<< endl;
		observers.push_back(o);
	}
	void unregisterObserver(IObserver *o) {
		cout<<"unregister..."<< endl;
		auto iterator = find(observers.begin(), observers.end(), o);
		if (iterator != observers.end()) { // observer found
			observers.erase(iterator); // remove the observer
		}
	}
	void notifyObserver() {
		for (IObserver *observer : observers) { // notify all observers
		        observer->update(temp, humidity, pressure);
		}
	}

	void setState(float temp, float humidity, float pressure) {
	    this->temp = temp;
	    this->humidity = humidity;
	    this->pressure = pressure;
	    std::cout << std::endl;
	    notifyObserver();
	}
};

class Client : public IObserver {
	int id;
public:
	Client(int id) {
		this->id = id;
	}
	void update(float temp, float humidity, float pressure) {
		cout<<"called client:" << temp <<":"<< humidity <<":"<< pressure << endl;
	}
};

int main() {
	cout << "Observer example" << endl; // prints Observer example
	WhetherData *wdata = new WhetherData;
	Client c1(1);
	wdata->registerObserver(&c1);
	wdata->setState(37.7, 25.5, 7.7);
	wdata->unregisterObserver(&c1);
	return 0;
}
