#pragma once
#include "Color.h"
#include <vector>
#include "Location.h"

/// <summary>
/// Abstract class of chess piece
/// </summary>
class Piece
{
protected:
	Color color;
	char kind;

public:
	/// <summary>
	/// CTor of piece
	/// </summary>
	/// <param name="c">color</param>
	/// <param name="k">char kind</param>
	Piece(Color c = Color::white, char k = ' ') : color(c), kind(k) {}

	/// <summary>
	/// DTor
	/// </summary>
	virtual ~Piece() {}

	/// <summary>
	/// Get color of piece
	/// </summary>
	Color getColor() const { return color; }

	/// <summary>
	/// Get kind of piece
	/// </summary>
	char getKind() const { return kind; }

	/// <summary>
	/// Pure abstract function - all necessary steps from the source location to the destination location
	/// </summary>
	/// <param name="source">source location</param>
	/// <param name="destination">destination location</param>
	/// <returns>vector of locations with all necessary steps</returns>
	virtual std::vector<Location> allStepsRequired(Location sourch, Location destination) = 0;

	///// <summary>
	///// 
	///// </summary>
	//bool isCheesOnMyKing(Location locatinOfMyKing);

	///// <summary>
	///// 
	///// </summary>
	//bool isCheesOnOtherKing(Location locatinOfOtherKing);

	/// <summary>
	/// Pure abstract function - checks if the move is legal
	/// </summary>
	/// <param name="source">source location</param>
	/// <param name="destination">destination location</param>
	/// <returns>True or false</returns>
	virtual bool isLegalMove(Location source, Location destination) = 0;

	/// <summary>
	/// abstract function - checks if is king
	/// </summary>
	/// <returns>False for everyone without king</returns>
	virtual bool isKing() { return false; }
};
