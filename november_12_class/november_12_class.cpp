#include "hangMan.h"

#include <fstream>
#include <vector>
#include <iostream>

int main()
{
	/* Copied a GitHub repository for the file named popular.txt.
	See: https://github.com/dolph/dictionary/blob/master/popular.txt */

	//std::string aString = "albert";
	//char aLetter = 'a';
	//
	//int positionToStartSearchAt = 1;
	//size_t locationOFLetter = aString.find(aLetter, positionToStartSearchAt);
	//std::cout << "In the string " << aString << std::endl;
	//if (aString.find(aLetter) != std::string::npos)
	//{
	//	std::cout << "The letter " << aLetter << " is at index " << locationOFLetter << std::endl;
	//}
	//else
	//{
	//	std::cout << "The letter was not found " << locationOFLetter << std::endl;
	//}

	playHangman();
}

/*
Specification and implementation files are separate.
An overload in a function is adding inputs.
*/