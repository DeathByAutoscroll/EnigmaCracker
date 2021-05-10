#pragma once
#include <iostream>
#include "Plugboard.h"
#include "Rotor.h"

class RotorManager
{
private:
	//class definitions
	Rotor rotor[5];
	Rotor reflector;
	int rotorsUsed[3];

public:
	//constructor
	RotorManager();
	//destructor
	~RotorManager();

	//functions
	char encrypt(char);
	void setRotors();
	void addRotor(int, int);
	int getRotor(int);

};

