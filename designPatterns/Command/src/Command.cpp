//============================================================================
// Name        : Command.cpp
// Author      : Mantesh
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
using namespace std;

// Command Interface
class Command {
public:
	virtual void execute() = 0;
	Command(){}
	~Command(){}
};

// Receiver Class
class Light {
public:
	void lightOn() {
		cout<<"light on" << endl;
	}
	void lightOff() {
			cout<<"light off" << endl;
	}
};

// Command for turning on the light
class CommandLightOn : public Command {
public:
	CommandLightOn(Light *l) : light(l) {

	}

	void execute() {
		light->lightOn();
	}
private:
	Light *light;
};

// Command for turning off the light
class CommandLightOff : public Command {
public:
	CommandLightOff(Light *l) : light(l) {

	}

	void execute() {
		light->lightOff();
	}
private:
	Light *light;
};

// Invoker
class RemoteControl {
public:
	void setCommand(Command * cmd) {
		m_cmd = cmd;
	}
	void pressButton() {
		m_cmd->execute();
	}
private:
	Command *m_cmd;
};

int main() {
	cout << "command example" << endl; // prints command example
	Light *light = new Light;
	CommandLightOn *on = new CommandLightOn(light);
	CommandLightOff *off = new CommandLightOff(light);

	RemoteControl *control = new RemoteControl;

	control->setCommand(on);
	control->pressButton();
	control->setCommand(off);
	control->pressButton();
	return 0;
}
