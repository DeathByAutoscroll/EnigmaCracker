#pragma once
#include <string>
class Rotor
{
protected:
	//these will be definined in a rotor manager and given to a rotor with a pointer
	char rotorPairs[26];
	int position = 0;

public:
	//constructor
	Rotor(std::string);
	~Rotor();

	//functions
	char encode(char);
	void incPos();

};