#include "Board.h"
Board::Board() : board(8, std::vector<Piece*>(8, nullptr)) {
	board[0][0] = new Rook(Color::black, 'R');
	board[0][7] = new Rook(Color::black, 'R');
	board[7][0] = new Rook(Color::black, 'r');
	board[7][7] = new Rook(Color::black, 'r');

}

Board::~Board() {
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			delete board[i][j];
		}
	}
}

int Board::checkStepsAvailability(const std::vector<Location> locations, Location destination) {
	int row, col;
	for (int i = 0; i < locations.size() - 1; i++)
	{
		if (destination != locations[i])
		{
			row = locations[i].row;
			col = locations[i].col;
			if (board[row][col] != NULL)
			{
				return ILLEGAL_MOVE;
			}
		}

	}
	return LLEGAL_MOVE;

}