#pragma once
#include "Color.h"
#include <vector>
#include "Location.h"

class Piece
{
protected:
	Color color;
	char kind;

public:
	Piece(Color c = white, char k = ' ');
	virtual ~Piece() {};
	
	virtual std::vector<std::vector<bool>> legalMoovs(const Location source) = 0;
	virtual std::vector<Location> allStepsRequired(Location sourch, Location destination) = 0;
};
