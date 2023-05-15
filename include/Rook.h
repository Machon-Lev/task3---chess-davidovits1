#pragma once
#include "Piece.h"
class Rook : public Piece
{
public:
	Rook(Color c = white, char k = ' ') : Piece(c, k) {};
	~Rook() override {};
	std::vector<std::vector<bool>> legalMoovs(const Location source) override;
	std::vector<Location> allStepsRequired(Location sourch, Location destination) override;
};