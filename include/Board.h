#pragma once
#include <vector>
#include "Rook.h"

int NO_PIECE_IN_SOURCE = 11;
int OTHER_PIECE_IN_SOURCE = 12;
int MY__PIECE_IN_TARGET = 13;
int ILLEGAL_MOVE = 21;
int CHESS_ON_ME = 31;

int LLEGAL_MOVE = 42;
int CHESS_ON_OTHER = 41;

class Board {
	std::vector<std::vector<Piece*>> board;

public:
	Board();
	~Board();
	int checkStepsAvailability(const std::vector<Location> locations, Location destination);


};