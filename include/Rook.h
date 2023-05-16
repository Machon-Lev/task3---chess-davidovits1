#pragma once
#include "Piece.h"
class Rook : public Piece
{
public:
	Rook(Color c = Color::white, char k = ' ') : Piece(c, k) {};
	~Rook() {};
	std::vector<std::vector<bool>> legalMoovs(const Location source) override;
	std::vector<Location> allStepsRequired(const Location sourch,const  Location destination) override;
};