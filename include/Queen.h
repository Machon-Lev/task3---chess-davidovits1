#pragma once
#include "Piece.h"

class Queen : public Piece
{
public:
	Queen(Color c = Color::white, char k = ' ') : Piece(c, k) {};
	~Queen() {};

	std::vector<Location> allStepsRequired(const Location source, const  Location destination) override;
	bool isLegalMove(Location source, Location destination) override;
};