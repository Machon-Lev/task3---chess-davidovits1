#include "Knight.h"
//#include <math.h>

std::vector<Location> Knight::allStepsRequired(const Location source, const Location destination)
{
	return std::vector<Location>();
}

bool Knight::isLegalMove(Location source, Location destination)
{
	int distanceRow = abs(destination.row - source.row);
	int distanceCol = abs(destination.col - source.col);
	return (distanceRow == 1 && distanceCol == 2) || (distanceRow == 2 && distanceCol == 1);
}