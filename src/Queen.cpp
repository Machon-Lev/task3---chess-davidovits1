#include "Queen.h"

std::vector<Location> Queen::allStepsRequired(const Location source, const Location destination)
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

	//left or right
	else if (source.row == destination.row)
	{
		int maxCol = std::max(source.col, destination.col);
		int minCol = std::min(source.col, destination.col);

		for (int i = minCol; i <= maxCol; i++)
		{
			if (i != source.col)
			{
				Location l(source.row, i);
				stepsRequired.push_back(l);
			}

		}
	}

	//up or down
	else if (source.col == destination.col)
	{
		int maxRow = std::max(source.row, destination.row);
		int minRow = std::min(source.row, destination.row);

		for (int i = minRow; i <= maxRow; i++)
		{
			if (i != source.row)
			{
				Location l(i, source.col);
				stepsRequired.push_back(l);
			}

		}
	}

	else
		return std::vector<Location>();

	return stepsRequired;
}

bool Queen::isLegalMove(Location source, Location destination)
{
	int distanceRow = destination.row - source.row;
	int distanceCol = destination.col - source.col;

	if ((distanceRow != 0 || distanceCol != 0) && (distanceRow == distanceCol || distanceRow == -distanceCol
		|| source.row == destination.row || source.col == destination.col))
		return true;
	return false;
}