#pragma once
#include "Piece.h"

class Bishop : public Piece
{
public:
	Bishop(Color c = Color::white, char k = ' ') : Piece(c, k) {};
	~Bishop() {};

	std::vector<Location> allStepsRequired(const Location source, const  Location destination) override;
	bool isLegalMove(Location source, Location destination) override;
};