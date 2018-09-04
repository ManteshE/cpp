//============================================================================
// Name        : Builder.cpp
// Author      : Mantesh
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
using namespace std;

class FirstName {
public:
	string firstName;
};

class LastName {
public:
	string lastName;
};

/* final product */
class Person {
public:
	FirstName *fn;
	LastName *ln;

	void display() {
		cout << "first Name : "<<fn->firstName << endl;
		cout << "Last Name : " << ln->lastName << endl;
	}
};

/* Builder is responsible for constructing the smaller parts */
class Builder {
public:
		virtual FirstName *getFirstname() = 0;
		virtual LastName *getLastName() = 0;
};

/* Director is responsible for the whole process */
class Director {
	Builder *builder;
public:
	void setBuilder(Builder *newBuilder) {
		builder = newBuilder;
	}

	Person *getPerson() {
		Person *person = new Person();
		person->fn = builder->getFirstname();
		person->ln = builder->getLastName();
		return person;
	}
};

/* Concrete builder for Mantesh */
class ManteshClass : public Builder {
public:
	FirstName *getFirstname() {
		FirstName *first = new FirstName();
		first->firstName = "Mantesh";
		return first;
	}

	LastName *getLastName() {
		LastName *last = new LastName();
		last->lastName = "Eksambe";
		return last;
	}
};

int main() {
	cout << "Builder example" << endl; // prints Builder example
	/* Final product */
	Person *person;

	/* A director who controls the process */
	Director director;

	/* Concrete builders */
	ManteshClass mantesh;

	director.setBuilder(&mantesh);
	person = director.getPerson();
	person->display();
	return 0;
}
