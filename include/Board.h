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

class Board {
	Location whiteKingLocation = Location(0, 4);
	Location blackKingLocation = Location(7, 4);;
	bool isWhiteChess;
	bool isBlackChess;
	Color turn;
	std::vector<std::vector<Piece*>> board;
	

	void setMyKingLocation(const Color myColor, Location myKingLocation);
	void move(const Location sourch, const Location destination);
	void initBoard();
	Board& operator=(const Board& other);
	std::vector<std::vector<Piece*>> copyBoard();
	bool isChess(const std::vector<std::vector<Piece*>> tempBoard, Location locationKing, Color colorKing);
	Location getMyKingLocation(Location source, Location destination);
	Location getOtherKingLocation(const Color otherColor) const;
	bool isNeedCheckFreeMoves(const char kind) const;
	Color getOtherColor(const Color myColor) const;
	bool isLegalLocation(const Location source, const Location destination) const;
	bool isStepsAvailability(const std::vector<Location> locations,
		std::vector<std::vector<Piece*>> tempBoard, Location destination);
	bool isValidForPawn(const Location source, const Location destination);
	void setIsFirstStepForPawn(Location source);
	bool isPawn(char kind);

public:
	Board();
	~Board();

	int tryMove(const Location source, const Location destination);

};