#pragma once
#include "Piece.h"

/// <summary>
/// Class king of chess
/// </summary>
class King : public Piece
{
public:
	/// <summary>
	/// CTor of king
	/// </summary>
	/// <param name="c">color of king</param>
	/// <param name="k">char kind</param>
	King(Color c = Color::white, char k = ' ') : Piece(c, k) {};

	/// <summary>
	/// DTor of king
	/// </summary>
	~King() {};

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

	/// <summary>
	/// Checks if is king
	/// </summary>
	/// <returns>True</returns>
	bool isKing() override;
};