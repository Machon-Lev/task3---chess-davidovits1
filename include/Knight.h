#pragma once
#include "Piece.h"

/// <summary>
/// Class knight of chess
/// </summary>
class Knight : public Piece
{
public:
	/// <summary>
	/// CTor of knight
	/// </summary>
	/// <param name="c">color of king</param>
	/// <param name="k">char kind</param>
	Knight(Color c = Color::white, char k = ' ') : Piece(c, k) {};

	/// <summary>
	/// DTor of knight
	/// </summary>
	~Knight() {};

	/// <summary>
	/// All necessary steps from the source location to the destination location
	/// </summary>
	/// <param name="source">source location</param>
	/// <param name="destination">destination location</param>
	/// <returns>vector of locations with all necessary steps</returns>
	std::vector<Location> allStepsRequired(const Location source, const  Location destination) override;

	/// <summary>
	/// Checks if the move is legal
	/// </summary>
	/// <param name="source">source location</param>
	/// <param name="destination">destination location</param>
	/// <returns>True or false</returns>
	bool isLegalMove(Location source, Location destination) override;
};