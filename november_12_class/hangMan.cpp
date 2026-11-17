#include "hangMan.h"

#include <iostream>
#include <fstream>
#include <random>

//This is the immplementation file.

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

void findAndReplace(std::string wordToGuess, std::string& placeholder, char characterToSearchFor)
{
	for (int location = 0; location < wordToGuess.size(); location++)
	{
		if (wordToGuess[location] == characterToSearchFor)
		{
			std::cout << "Correct " << std::endl;
			placeholder[location] = characterToSearchFor;
		}

		else
		{
			std::cout << "The character " << characterToSearchFor << " was not found " << std::endl;
		}
	}
	std::cout << "The updated placeholder is: " << placeholder << std::endl;
}

std::string generatePlaceholder(std::string wordToGuess)
{
	std::string placeholder;
	for (int i = 0; i < wordToGuess.size(); i++)
	{
		placeholder.push_back('*');
	}
	return placeholder;
}

void playHangman()
{
	//First get all words, or add a second player who makes the word.
	std::string absoluteFilePath =
		"C:/Users/timot/source/repos/november_12_class/november_12_class/popular.txt";

	//absoluteFilePath.replace()

	std::vector<std::string> dictionaryWords = getAllDictionaryWords(absoluteFilePath);

	std::string wordToGuess = pickRandomWord(dictionaryWords);
	std::string placeholder = generatePlaceholder(wordToGuess);
	
	//std::cout << "The word that is being guessed is: " << wordToGuess << std::endl;
	std::cout << "The word to guess is: " << placeholder << std::endl;
	
	int maxGuesses = placeholder.size();
	int currentNumberOfGuesses = 0;

	//Loops until the user guesses all characters of wordToGuess.
	while((placeholder != wordToGuess) && (currentNumberOfGuesses < maxGuesses))
	{
		//Prompt for guessedCharacter and whether it was correct.
		char guessedCharacter;
		std::cout << "Guess a letter: " << std::endl;
		//std::getline()
		std::cin >> guessedCharacter; /* This operator is the input operator, or the stream 
		extraction */
		currentNumberOfGuesses++;
		
		//Check if the right character is in the word.
		findAndReplace(wordToGuess, placeholder, guessedCharacter);
	}

	if (currentNumberOfGuesses == maxGuesses)
	{
		std::cout << "You have lost the game. " << std::endl;
	}
}