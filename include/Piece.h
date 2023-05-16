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

	Piece(Color c = Color::white, char k = ' ') : color(c), kind(k) {}
	virtual ~Piece() {}

	Color getColor() const { return color; }

	char getKind() const { return kind; }

	
	virtual std::vector<std::vector<bool>> legalMoovs(const Location source) = 0;
	virtual std::vector<Location> allStepsRequired(Location sourch, Location destination) = 0;
	bool isCheesOnMyKing(Location locatinOfMyKing);
	bool isCheesOnOtherKing(Location locatinOfOtherKing);
	virtual bool isLegalMoov(Location source, Location destination) = 0;
};
