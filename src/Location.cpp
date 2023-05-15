#include "Location.h"


Location& Location::operator+=(const Location& other)
{

	row += other.row;
	col += other.col;
	return *this;
	
}

bool Location::operator==(const Location& other) const
{
	return (row == other.row && col == other.col);
}

bool Location::operator!=(const Location& other) const
{
	return !(*this == other);
}

Location& Location::operator=(const Location& other)
{
	row = other.row;
	col = other.col;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Location& loc)
{
	os <<"row: " <<  loc.row << ", " << "col: " << loc.col;
	return os;
}
