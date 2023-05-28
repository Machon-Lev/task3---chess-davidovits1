#include "Bishop.h"

std::vector<Location> Bishop::allStepsRequired(const Location source, const Location destination)
{
	std::vector<Location> stepsRequired;
	int distanceRow = destination.row - source.row;
	int distanceCol = destination.col - source.col;
	
	//down right
	if (distanceRow > 0 && distanceCol > 0)
	{
		for (int i = 1; i < distanceRow; i++)
		{
			Location l(source.row + i, source.col + i);
			stepsRequired.push_back(l);
		}
	}

	//down left
	else if (distanceRow > 0 && distanceCol < 0)
	{
		for (int i = 1; i < distanceRow; i++)
		{
			Location l(source.row + i, source.col - i);
			stepsRequired.push_back(l);
		}
	}

	//up right
	else if (distanceRow < 0 && distanceCol > 0)
	{
		for (int i = 1; i < distanceCol; i++)
		{
			Location l(source.row - i, source.col + i);
			stepsRequired.push_back(l);
		}
	}

	//up left
	else if (distanceRow < 0 && distanceCol < 0)
	{
		for (int i = 1; i < -distanceCol; i++)
		{
			Location l(source.row - i, source.col - i);
			stepsRequired.push_back(l);
		}
	}

	else
		return std::vector<Location>();

	return stepsRequired;
}

bool Bishop::isLegalMove(Location source, Location destination)
{
	int distanceRow = destination.row - source.row;
	int distanceCol = destination.col - source.col;
	
	if (distanceRow != 0 && (distanceRow == distanceCol || distanceRow == -distanceCol))
		return true;
	return false;
}
