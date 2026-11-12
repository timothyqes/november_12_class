#include "hangMan.h"

#include <iostream>
#include <fstream>
#include <random>

std::vector<std::string> getAllDictionaryWords(std::string fileName)
{
	std::vector<std::string> words;

	std::ifstream fin(fileName);

	//Making sure the file exists:
	if (fin.is_open() == false)
	{
		std::cout << "Could not find the file named " << fileName << std::endl;
		return{};
	}

	//The file exist, so getline() and a while() loop will be used.

	std::string currentWord;

	while (std::getline(fin, currentWord))
	{
		words.push_back(currentWord);
	}

	std::cout << "The number of words is: " << words.size() << std::endl;

	return words;
}

std::string pickRandomWord(std::vector<std::string> words)
{
	std::string randomWord;

	std::mt19937 rng(std::random_device{}()); //Explained in Fundamentals Programming II.

	//Equal probability of pulling a random value. Uniform means same.
	std::uniform_int_distribution<int> distribution(0, words.size() - 1);

	int randomIndex = distribution(rng);

	randomWord = words[randomIndex];

	return randomWord;
}
