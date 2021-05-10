#include "Rotor.h"

Rotor::Rotor() {
	
}

Rotor::~Rotor() {

}

void Rotor::setSpaghetti(std::string spaghetti) {
	for (int i = 0; i < 26; ++i) {
		rotorPairs[i] = spaghetti[i];
	}
}

char Rotor::encode(char input, bool back) {
	int index = 0;
	if (!back) {
		/*since every possible letter is 65 or greater, and all indexes are betwee 0-25
		* Removing 65 gives a 0-25 integer. Then by adding on the position, we have the new letter position
		* Mod it by 26 to ensure it loops around nicely and finally use it as index into array
		*/
		index = ((int)input - 65) + position;
		index = index % 26;
		return rotorPairs[index];
	}
	else {
		//need to run it though backwards rather than forwards.

		//finds letter in the jumbled encoding string
		for (int i = 0; i < 26; ++i) {
			if (input == rotorPairs[i]) {
				index = i;
				break;
			}
		}
		//I'm too lazy to add a condition to check if negative
		index += 26;
		index -= position;
		index = index % 26;
		//should return a letter
		return (char)(index + 65);
	}
}

void Rotor::incPos() {
	++position;
	if (position > 25) {
		position = position % 26;
	}
}