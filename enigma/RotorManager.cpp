#include "RotorManager.h"

RotorManager::RotorManager() {
	
}

RotorManager::~RotorManager() {

}

char RotorManager::encrypt(char letter) {
	char temp;
	//rotate the rotors
	rotor[rotorsUsed[2]].incPos();

	//encode forward
	for (int i = 0; i < 3; ++i) {
		temp = rotor[rotorsUsed[i]].encode(letter, false);
		letter = temp;
	}
	//ADD REFLECTOR ARRAY CHOICE HERE
	//reflect letter back - this means encoding/decoding can use same wires
	temp = reflector.encode(letter, false);
	letter = temp;

	//encode backwards
	for (int i = 2; i >= 0; --i) {
		temp = rotor[rotorsUsed[i]].encode(letter, true);
		letter = temp;
	}

	return letter;
}

void RotorManager::setRotors() {
	//all this rotor spaghetti wiring was found on wikipedia - (08/05/2021)
	//https://en.wikipedia.org/wiki/Enigma_rotor_details
	//This uses "Enigma 1" and "M3 Army" rotor details
	//debug  fillerfiller("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
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