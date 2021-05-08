#pragma once
#include <string>
class Plugboard
{
private:
	char plugPairs[10][2];

public:
	//constructor
	Plugboard(std::string);
	//destructor
	~Plugboard();

	//functions
	char swapLetters(char);

};
