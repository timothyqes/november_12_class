#pragma once

#include <string>
#include <vector>

std::vector<std::string> getAllDictionaryWords(std::string fileName);

std::string pickRandomWord(std::vector<std::string> words);

void findAndReplace(std::string wordToGuess, std::string& placeholder, char characterToSearchFor); //Without the ampersand sign, placeholder will not be able to be updated, since it passes by value, not by reference.

/// <summary>/// Calls other helper functions. /// </summary>
void playHangman();