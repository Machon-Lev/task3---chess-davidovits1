#include "King.h"

std::vector<Location> King::allStepsRequired(const Location source, const Location destination)
{
	return std::vector<Location>();
}

bool King::isLegalMove(Location source, Location destination)
{
	int sr = source.row;
	int sc = source.col;
	int dr = destination.row;
	int dc = destination.col;
	return (dr == sr + 1 && dc == sc) || (dr == sr && dc == sc + 1) || (dr == sr - 1 && dc == sc)
		|| (dr == sr && dc == sc - 1) || (dr == sr + 1 && dc == sc + 1) || (dr == sr - 1 && dc == sc - 1)
		|| (dr == sr + 1 && dc == sc - 1) || (dr == sr - 1 && dc == sc + 1);
}

bool King::isKing()
{
	return true;
}
