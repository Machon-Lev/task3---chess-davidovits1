#pragma once
#include <vector>
#include "Rook.h"

class Board {
	std::vector<std::vector<Piece*>> board;

public:
	Board();
	~Board();


};