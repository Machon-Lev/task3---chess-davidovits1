#include "Pawn.h"

std::vector<Location> Pawn::allStepsRequired(const Location source, const Location destination)
{
	//Case 2 steps down
	if (destination.row - source.row == 2)
	{
		std::vector<Location> stepsRequired;
		Location l(destination.row - 1, destination.col);
		stepsRequired.push_back(l);
		return stepsRequired;
	}

	//Case 2 steps up
	if (source.row - destination.row == 2)
	{
		std::vector<Location> stepsRequired;
		Location l(destination.row + 1, destination.col);
		stepsRequired.push_back(l);
		return stepsRequired;
	}

	//Case 1 step
	return std::vector<Location>();
}

bool Pawn::isLegalMove(Location source, Location destination)
{
	int sr = source.row;
	int sc = source.col;
	int dr = destination.row;
	int dc = destination.col;
	
	if (color == Color::white)
		return ((dr == sr + 1) || (dr == sr + 2)) && (dc == sc || dc == sc + 1 || dc == sc - 1);
	else
		return ((dr == sr - 1) || (dr == sr - 2)) && (dc == sc || dc == sc + 1 || dc == sc - 1);;
}