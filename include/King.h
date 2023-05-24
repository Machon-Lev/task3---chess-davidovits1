#pragma once
#include "Piece.h"

class King : public Piece
{
public:
	King(Color c = Color::white, char k = ' ') : Piece(c, k) {};
	~King() {};

	std::vector<std::vector<bool>> legalMoovs(const Location source) override;	// maby need to delete
	std::vector<Location> allStepsRequired(const Location sourch, const  Location destination) override;
	bool isLegalMoov(Location source, Location destination) override;
	bool isKing() override;
};