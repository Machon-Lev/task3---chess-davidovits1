#include "Pawn.h"

std::vector<Location> Pawn::allStepsRequired(const Location source, const Location destination)
{
	return std::vector<Location>();
}

bool Pawn::isLegalMove(Location source, Location destination)
{
	int sr = source.row;
	int sc = source.col;
	int dr = destination.row;
	int dc = destination.col;

	if (color == Color::white)
		return (dr == sr + 1) && (dc == sc || dc == sc + 1 || dc == sc - 1);
	else
		return (dr == sr - 1) && (dc == sc || dc == sc + 1 || dc == sc - 1);;
}