#pragma once
#include "Piece.h"
class Rook : public Piece
{
public:
	Rook(Color c = Color::white, char k = ' ') : Piece(c, k) {};
	~Rook() {};
	std::vector<Location> allStepsRequired(const Location source,const  Location destination) override;
	bool isLegalMove(Location source, Location destination) override;
};