#pragma once
#include <string>
#include "Location.h"
//Get source and destination string and returns source and destination Location pair
//(a1b2 -> 0,0 1,1)
std::pair<Location, Location> inputAnalysis(const std::string& userInput);