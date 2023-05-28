#pragma once
#include "Piece.h"

/// <summary>
/// Class queen of pawn
/// </summary>
class Pawn : public Piece
{
	bool isFirstStep = true;
public:
	/// <summary>
	/// CTor of pawn
	/// </summary>
	/// <param name="c">color of king</param>
	/// <param name="k">char kind</param>
	Pawn(Color c = Color::white, char k = ' ') : Piece(c, k) {};

	/// <summary>
	/// DTor of pawn
	/// </summary>
	~Pawn() {};

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
	/// Get is first step
	/// </summary>
	/// <returns>bool isFirstStep</returns>
	bool getIsFirstStep() { return isFirstStep; }

	/// <summary>
	/// Set isFirstStep false
	/// </summary>
	void setIsFIrstStep() { isFirstStep = false; }
};