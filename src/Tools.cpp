#include "Tools.h"
std::pair<Location, Location> inputAnalysis(const std::string& userInput) {
	int sourceLetter = userInput[0] - 'a';
	int sourceDigit = userInput[1] - '1';
	int destLetter = userInput[2] - 'a';
	int destDigit = userInput[3] - '1';
	Location source(sourceLetter, sourceDigit);
	Location dest(destLetter, destDigit);
	return std::make_pair(source, dest);
}