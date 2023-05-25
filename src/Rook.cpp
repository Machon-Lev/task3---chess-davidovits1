#include "Rook.h"
#include <algorithm>


std::vector<Location> Rook::allStepsRequired(const Location source,const  Location destination) {
	std::vector<Location> stepsRequired;
	if (source.row == destination.row)
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
	{
		return std::vector<Location>();
	}

	return stepsRequired;
}

bool Rook::isLegalMove(Location source, Location destinatio)
{
	return source.row == destinatio.row || source.col == destinatio.col;
}