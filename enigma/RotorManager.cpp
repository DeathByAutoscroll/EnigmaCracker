#include "RotorManager.h"

RotorManager::RotorManager() {
	
}

RotorManager::~RotorManager() {

}

char RotorManager::encrypt(char letter) {
	char temp;
	//rotate the rotors
	rotor[rotorsUsed[2]].incPos();

	for (int i = 0; i < 3; ++i) {
		temp = rotor[rotorsUsed[i]].encode(letter);
		letter = temp;
	}
	//ADD REFLECTOR ARRAY HERE
	temp = reflector.encode(letter);
	letter = temp;

	for (int i = 2; i >= 0; --i) {
		temp = rotor[rotorsUsed[i]].encode(letter);
		letter = temp;
	}

	return letter;
}

void RotorManager::setRotors() {
	//all this rotor spaghetti wiring was found on wikipedia - (08/05/2021)
	//https://en.wikipedia.org/wiki/Enigma_rotor_details
	//This uses "Enigma 1" and "M3 Army" rotor details
	rotor[0].setSpaghetti("EKMFLGDQVZNTOWYHXUSPAIBRCJ");
	rotor[1].setSpaghetti("AJDKSIRUXBLHWTMCQGZNPYFVOE");
	rotor[2].setSpaghetti("BDFHJLCPRTXVZNYEIWGAKMUSQO");
	rotor[3].setSpaghetti("ESOVPZJAYQUIRHXLNFTGKDCMWB");
	rotor[4].setSpaghetti("VZBRGITYUPSDNHLXAWMJQOFECK");

	reflector.setSpaghetti("EJMZALYXVBWFCRQUONTSPIKHGD");
}

void RotorManager::addRotor(int i, int num) {
	rotorsUsed[i] = num;
}

int RotorManager::getRotor(int i) {
	return rotorsUsed[i];
}