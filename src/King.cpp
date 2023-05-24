#include "King.h"

std::vector<std::vector<bool>> King::legalMoovs(const Location source)
{
	return std::vector<std::vector<bool>>();
}

std::vector<Location> King::allStepsRequired(const Location sourch, const Location destination)
{
	return std::vector<Location>();
}

bool King::isLegalMoov(Location source, Location destination)
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
