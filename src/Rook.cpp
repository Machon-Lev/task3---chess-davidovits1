#include "Rook.h"
#include <algorithm>

std::vector<std::vector<bool>> legalMoovs(const Location source) {
	std::vector<std::vector<bool>> board(8, std::vector<bool>(8, false));
	for (int i = 0; i < 8; i++)
	{
		if (i != source.row)
		{
			board[source.row][i] = true;
		}
		
		if (i != source.col)
		{
			board[i][source.col] = true;
		}
	}
	return board;
}

std::vector<Location> allStepsRequired(const Location sourch,const  Location destination) {
	std::vector<Location> stepsRequired;
	if (sourch.row == destination.row)
	{
		int maxCol = std::max(sourch.col, destination.col);
		int minCol = std::min(sourch.col, destination.col);
		
		for (int i = minCol; i <= maxCol; i++)
		{
			if (i != sourch.col)
			{
				Location l(sourch.row, i);
				stepsRequired.push_back(l);
			}

		}
	}
	else if (sourch.col == destination.col)
	{
		int maxRow = std::max(sourch.row, destination.row);
		int minRow = std::min(sourch.row, destination.row);

		for (int i = minRow; i <= maxRow; i++)
		{
			if (i != sourch.row)
			{
				Location l(i, sourch.col);
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
