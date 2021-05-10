#include <iostream>
#include <string>
#include <fstream>
#include "RotorManager.h"

int main() {

	std::string input;
	std::string output = "";
	char letter;
	bool verified = false;

	//plugboard
	std::cout << "Please insert the plugboard pairs (format XXYYZZ).\n";
	while (!verified) { //Verifying input
		verified = true;
		std::getline(std::cin, input); //this is used to capture spaces
				
		//if greater than 10 pairs or not in pairs, reject string.
		if (input.size() == 0 || input.size() > 20) {
			std::cout << "No more than 10 pairs allowed.\n";
			verified = false;
		} else if (input.size() % 2) {
			std::cout << "Please ensure each letter has a pair.\n";
			verified = false;
		}
		else {
			for (int i = 0; i < input.size(); ++i) {
				//if not a capital letter, reject string
				if ((int)input[i] < 65 || (int)input[i] > 90) {
					std::cout << "Sorry, not a valid input (capital letters only).\n";
					verified = false;
					break;
				}
			}
		}
	}
	Plugboard board(input);
	RotorManager man;
	man.setRotors();

	for (int i = 0; i < 3; ++i) {
		verified = false;
		while (!verified) {
			verified = true;
			std::cout << "Please insert which rotor you would like to use in position " << i + 1 << std::endl;
			std::getline(std::cin, input);

			for (int j = 0; j < i; ++j) {
				if (std::stoi(input) < 1 || std::stoi(input) > 5){
					std::cout << "Error: You can only use rotors 1 to 5\n";
					verified = false;
					break;
				}
				else if (std::stoi(input) - 1 == man.getRotor(j)) {
					std::cout << "Error: You can't have the same rotor twice!\n";
					verified = false;
					break;
				}
			}

			if (verified) {
				man.addRotor(i, std::stoi(input) - 1);
			}
		}
	}

	std::cout << "Please insert the message you would like to encrypt/decrypt.\n";
	std::getline(std::cin, input); //this is used to capture spaces

	for (int i = 0; i < input.size(); ++i) {
		
		letter = std::toupper(input[i]);

		if ((int)letter > 64 && (int)letter < 91) {
			//Functions to manipulate letters
			letter = board.swapLetters(letter);
			letter = man.encrypt(letter);
			letter = board.swapLetters(letter);
		}
		else if (letter == ' ') {
			//adds a space to the output - not accurate but looks nicer
			output.push_back(' ');
			continue;
		} else {
			//Ignore the character if not A-Z or a space
			continue;
		}

		//add new character to string
		output.push_back(letter);
	}
	
	//temp
	std::cout << "Your new message is now:" << std::endl;
	std::cout << output;

	return 0;

}