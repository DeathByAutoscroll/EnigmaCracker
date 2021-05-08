#include "RotorManager.h"

RotorManager::RotorManager() {
	
}

RotorManager::~RotorManager() {

}

char RotorManager::encrypt(char letter) {
	//temp
	letter = rotor1.encode(letter);
	rotor1.incPos();
	return letter;
}