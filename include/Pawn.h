#pragma once
#include "Piece.h"

class Pawn : public Piece
{
public:
	Pawn(Color c = Color::white, char k = ' ') : Piece(c, k) {};
	~Pawn() {};

	std::vector<Location> allStepsRequired(const Location source, const  Location destination) override;
	bool isLegalMove(Location source, Location destination) override;
};