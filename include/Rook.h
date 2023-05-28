#pragma once
#include "Piece.h"

/// <summary>
/// Class queen of chess
/// </summary>
class Rook : public Piece
{
public:
	/// <summary>
	/// CTor of rook
	/// </summary>
	/// <param name="c">color of king</param>
	/// <param name="k">char kind</param>
	Rook(Color c = Color::white, char k = ' ') : Piece(c, k) {};

	/// <summary>
	/// DTor of rook
	/// </summary>
	~Rook() {};

	/// <summary>
	/// All necessary steps from the source location to the destination location
	/// </summary>
	/// <param name="source">source location</param>
	/// <param name="destination">destination location</param>
	/// <returns>vector of locations with all necessary steps</returns>
	std::vector<Location> allStepsRequired(const Location source,const  Location destination) override;

	/// <summary>
	/// Checks if the move is legal
	/// </summary>
	/// <param name="source">source location</param>
	/// <param name="destination">destination location</param>
	/// <returns>True or false</returns>
	bool isLegalMove(Location source, Location destination) override;
};