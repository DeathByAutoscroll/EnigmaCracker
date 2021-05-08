#include <iostream>
#include <string>
#include <fstream>
#include "Plugboard.h"

int main() {

	std::string input;
	std::string output = "";
	char letter;

	//TEMP
	std::cout << "Please insert the plug pairs (format XXYYZZ).\n";
	std::getline(std::cin, input); //this is used to capture space
	//TEMP
	Plugboard plugs(input);
	
	std::cout << "Please insert the message you would like to encrypt/decrypt.\n";
	std::getline(std::cin, input); //this is used to capture spaces

	for (int i = 0; i < input.size(); ++i) {
		
		letter = std::toupper(input[i]);

		if ((int)letter > 64 && (int)letter < 91) {
			//insert function to main rotor manager
			letter = plugs.swapLetters(letter);

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