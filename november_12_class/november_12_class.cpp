#include "hangMan.h"

#include <fstream>
#include <vector>
#include <iostream>

int main()
{
	/* Copied a GitHub repository for the file named popular.txt.
	See: https://github.com/dolph/dictionary/blob/master/popular.txt */
	std::string absoluteFilePath = 
		"C:/Users/timot/source/repos/november_12_class/november_12_class/popular.txt";
	std::vector<std::string> dictionaryWords = getAllDictionaryWords(absoluteFilePath);


	for (int index = 0; index < 10; index++)
	{
		std::cout << "The random word is: " << pickRandomWord(dictionaryWords) << std::endl;
	}
}

/*Specification and implementation files are separate.*/