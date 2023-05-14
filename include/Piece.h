#pragma once
#include "Color.h"
#include <vector>

class Piece
{
protected:
	Color color;
	char kind;

public:
	Piece(Color c = white, char k = ' ');
	virtual ~Piece() {};
	
	virtual std::vector<std::vector<bool>> legalMoovs(int pawnRow, int pawnCol) = 0;
};
