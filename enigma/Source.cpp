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

	std::cout << "Please insert the message you would like to encrypt/decrypt.\n";
	std::getline(std::cin, input); //this is used to capture spaces

	for (int i = 0; i < input.size(); ++i) {
		
		letter = std::toupper(input[i]);

		if ((int)letter > 64 && (int)letter < 91) {
			//Functions to manipulate letters
			//letter = board.swapLetters(letter);
			letter = man.encrypt(letter);
			//letter = board.swapLetters(letter);
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