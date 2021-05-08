#pragma once
#include "Plugboard.h"
#include "Rotor.h"

class RotorManager
{
private:
	//all this rotor spaghetti wiring was found on wikipedia 
	//https://en.wikipedia.org/wiki/Enigma_rotor_details
	//This uses "Enigma 1" and "M3 Army" rotor details
	//class definitions
	Rotor rotor1{ "EKMFLGDQVZNTOWYHXUSPAIBRCJ" };
	Rotor rotor2{ "AJDKSIRUXBLHWTMCQGZNPYFVOE" };
	Rotor rotor3{ "BDFHJLCPRTXVZNYEIWGAKMUSQO" };
public:
	//constructor
	RotorManager();
	//destructor
	~RotorManager();

	//functions
	char encrypt(char);

};

