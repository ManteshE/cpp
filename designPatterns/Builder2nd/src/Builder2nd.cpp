//============================================================================
// Name        : Builder2nd.cpp
// Author      : Mantesh
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
#include <sstream>
#include <string>
using namespace std;


class Email {
public:
	class EmailBuilder;

	Email(string from, string to) {
		m_from  = from;
		m_to = to;
	}

	string to_string() {
		stringstream stream;
		stream << "\nFrom : " << m_from
			   << "\nTo : " << m_to;
		return stream.str();
	}

	string m_from;
	string m_to;
};

class Email::EmailBuilder {
public:
	EmailBuilder& from(string from) {
		m_from = from;
		return *this;
	}
	EmailBuilder& to(string to) {
		m_to = to;
		return *this;
	}

	Email build() const {
		return Email{m_from, m_to};
	}
private:
	string m_from;
	string m_to;
};

int main() {
	cout << "Builder example !!!" << endl; // prints Builder example
	Email email = Email::EmailBuilder{}.from("abc@gmail.com")
									.to("xyz@gmail.com")
									.build();
	cout << "Email data" << email.to_string() << endl;
	return 0;
}
