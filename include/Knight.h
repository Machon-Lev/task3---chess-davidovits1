#pragma once
#include "Piece.h"

class Knight : public Piece
{
public:
	Knight(Color c = Color::white, char k = ' ') : Piece(c, k) {};
	~Knight() {};

	std::vector<Location> allStepsRequired(const Location source, const  Location destination) override;
	bool isLegalMove(Location source, Location destination) override;
};