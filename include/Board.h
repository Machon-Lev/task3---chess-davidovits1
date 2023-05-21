#pragma once
#include <vector>
#include "Rook.h"

extern const int NO_PIECE_IN_SOURCE;
extern const int OTHER_PIECE_IN_SOURCE;
extern const int MY_PIECE_IN_TARGET;
extern const int ILLEGAL_MOVE;
extern const int CHESS_ON_ME;

extern const int LEGAL_MOVE;
extern const int CHESS_ON_OTHER;

class Board {
	Location whiteKingLocation = Location(7, 4);
	Location blackKingLocation = Location(0, 4);;
	bool isWhiteChess;
	bool isBlackChess;
	Color turn;
	std::vector<std::vector<Piece*>> board;
	

	void setMyKingLocation(const Color myColor, Location myKingLocation);
	void move(const Location sourch, const Location destination);

public:
	Board();
	~Board();
	bool isStepsAvailability(const std::vector<Location> locations,
		std::vector<std::vector<Piece*>> tempBoard, Location destination);
	int tryMove(const Location sourch, const Location destination);
	Board& operator=(const Board& other);
	std::vector<std::vector<Piece*>> copyBoard();
	bool isChess(const std::vector<std::vector<Piece*>> tempBoard, Location locationKing, Color colorKing);
	Location getMyKingLocation(Location sourch, Location destination);
	Location getOtherKingLocation(const Color otherColor) const;
	bool isNeedCheckFreeMoovs(const char kind) const;
	Color getOtherColor(const Color myColor) const;
};