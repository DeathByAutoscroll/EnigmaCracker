#include "Plugboard.h"
#include <string>
#include <iostream>

Plugboard::Plugboard(std::string pairs) {
	//temp - to be made better soon
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			plugPairs[i][j] = pairs[i*2 + j];
		}
	}
}

Plugboard::~Plugboard() {

}

char Plugboard::swapLetters(char letters) {
	//temp loop
	for (int i = 0; i < 2; ++i) {
		//if letter is the first letter, make it second, else if second, make it first
		if (letters == plugPairs[i][0]) {;
			return plugPairs[i][1];
		}
		else if (letters == plugPairs[i][1]) {
			return plugPairs[i][0];
		}
	}
	//if not found:
	return letters;
}