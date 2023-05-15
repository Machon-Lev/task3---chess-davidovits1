#pragma once
#include <iostream>
struct Location
{
	int row;
	int col;

public:
	// Default constructor
	Location() : row(0), col(0) {}

	// Parameterized constructor
	Location(int r, int c) : row(r), col(c) {}

	// Addition assignment operator (+=)
	Location& operator+=(const Location& other);

	// Equality operator (==)
	bool operator==(const Location& other) const;

	// Inequality operator (!=)
	bool operator!=(const Location& other) const;

	// Assignment operator (=)
	Location& operator=(const Location& other);


};

// Printing operator (<<)
std::ostream& operator<<(std::ostream& os, const Location& loc);