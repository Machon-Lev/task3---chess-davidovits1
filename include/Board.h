#pragma once
#include <vector>
#include "Rook.h"
#include "King.h"
#include "Bishop.h"
#include "Queen.h"
#include "Knight.h"
#include "Pawn.h"

extern const int NO_PIECE_IN_SOURCE;
extern const int OTHER_PIECE_IN_SOURCE;
extern const int MY_PIECE_IN_TARGET;
extern const int ILLEGAL_MOVE;
extern const int CHESS_ON_ME;

extern const int LEGAL_MOVE;
extern const int CHESS_ON_OTHER;

/// <summary>
/// Class board of chess
/// </summary>
class Board {
	Location whiteKingLocation = Location(0, 4);
	Location blackKingLocation = Location(7, 4);;
	Color turn;
	std::vector<std::vector<Piece*>> board;
	
	/// <summary>
	/// Determine the position of the player's king
	/// </summary>
	void setMyKingLocation(const Color myColor, Location myKingLocation);

	/// <summary>
	/// Moves a piece from the source to the destination
	/// </summary>
	/// <param name="source">location</param>
	/// <param name="destination">location</param>
	void move(const Location sourch, const Location destination);

	/// <summary>
	/// Initializes the board
	/// </summary>
	void initBoard();
	
	/// <summary>
	/// Copy the board
	/// </summary>
	/// <returns>Vector of board</returns>
	std::vector<std::vector<Piece*>> copyBoard();
	
	/// <summary>
	/// Checking if there is chess on the king
	/// </summary>
	/// <param name="tempBoard">board</param>
	/// <param name="locationKing">location of king</param>
	/// <param name="colorKing">color of king</param>
	/// <returns>True or false</returns>
	bool isChess(const std::vector<std::vector<Piece*>> tempBoard, Location locationKing, Color colorKing);

	/// <summary>
	/// Returns the position of the player's king
	/// </summary>
	/// <param name="source">location</param>
	/// <param name="destination">location</param>
	/// <returns>location player's king</returns>
	Location getMyKingLocation(Location source, Location destination);

	/// <summary>
	/// Returns the position of the opponent's king
	/// </summary>
	/// <param name="source">location</param>
	/// <param name="destination">location</param>
	/// <returns>location opponent's king</returns>
	Location getOtherKingLocation(const Color otherColor) const;

	/// <summary>
	/// Checks if this is a piece that needs to be moved to other places on the board
	/// </summary>
	/// <param name="kind">char</param>
	/// <returns>false for king and knight true for others</returns>
	bool isNeedCheckFreeMoves(const char kind) const;

	/// <summary>
	/// Returns the color of the opponent
	/// </summary>
	/// <param name="myColor">color of the player</param>
	/// <returns>Color of the opponent</returns>
	Color getOtherColor(const Color myColor) const;

	/// <summary>
	/// Checks if the requested source and destination location are valid
	/// </summary>
	/// <param name="source">location</param>
	/// <param name="destination">location</param>
	/// <returns>True or false</returns>
	bool isValidLocation(const Location source, const Location destination) const;

	/// <summary>
	/// Checks if all the places that need to be passed are free
	/// </summary>
	/// <param name="locations">vector of locations required</param>
	/// <param name="tempBoard">copy of board</param>
	/// <param name="destination">location</param>
	/// <returns>True or false</returns>
	bool isStepsAvailability(const std::vector<Location> locations,
		std::vector<std::vector<Piece*>> tempBoard, Location destination);

	/// <summary>
	/// Checks if the move is legal for a pawn
	/// </summary>
	/// <param name="source">location</param>
	/// <param name="destination">location</param>
	/// <returns>True or false</returns>
	bool isValidForPawn(const Location source, const Location destination);

	/// <summary>
	/// Updates the function setIsFIrstStep of pawn
	/// </summary>
	/// <param name="source">location</param>
	void setIsFirstStepForPawn(Location source);

	/// <summary>
	/// Checks if is king
	/// </summary>
	/// <param name="kind">char</param>
	/// <returns>True or false</returns>
	bool isPawn(char kind);

public:
	/// <summary>
	/// CTor of board
	/// </summary>
	Board();

	/// <summary>
	/// DTor of board
	/// </summary>
	~Board();
	
	/// <summary>
	/// Trying to make the move from source to destination
	/// </summary>
	/// <param name="source">location</param>
	/// <param name="destination">location</param>
	/// <returns>A code that signifies success or failure and the reasons</returns>
	int tryMove(const Location source, const Location destination);

};