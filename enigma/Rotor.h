#pragma once
#include <string>
class Rotor
{
protected:
	//these will be definined in a rotor manager and given to a rotor with a pointer
	char rotorPairs[26];
	int position = 0;
	int rotPos;

public:
	//constructor
	Rotor();
	~Rotor();

	//functions
	void setSpaghetti(std::string);
	char encode(char, bool);
	void incPos();

};