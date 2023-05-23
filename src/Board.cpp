#include "Board.h"

const int NO_PIECE_IN_SOURCE = 11;
const int OTHER_PIECE_IN_SOURCE = 12;
const int MY_PIECE_IN_TARGET = 13;
const int ILLEGAL_MOVE = 21;
const int CHESS_ON_ME = 31;
const int CHESS_ON_OTHER = 41;
const int LEGAL_MOVE = 42;


Board::Board() : board(8, std::vector<Piece*>(8, nullptr)) {
	isWhiteChess = false;
	isBlackChess = false;
	turn = Color::white;
	board[0][0] = new Rook(Color::black, 'R');
	board[0][7] = new Rook(Color::black, 'R');
	board[7][0] = new Rook(Color::white, 'r');
	board[7][7] = new Rook(Color::white, 'r');

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

bool Board::isStepsAvailability(const std::vector<Location> locations,
	const std::vector<std::vector<Piece*>> tempBoard, Location destination) {
	int row, col;
	for (int i = 0; i < locations.size(); i++)
	{
		if (destination != locations[i])
		{
			row = locations[i].row;
			col = locations[i].col;
			if (tempBoard[row][col] != NULL)
			{
				return false;
			}
		}

	}
	return true;

}

int Board::tryMove(const Location source, const Location destination)
{
	if (!isLegalLocation(source, destination))
		return ILLEGAL_MOVE;

	std::vector<std::vector<Piece*>> tempBoard = copyBoard();
	Piece* pieceSource = tempBoard[source.row][source.col];
	Piece* pieceDest = tempBoard[destination.row][destination.col];

	if (pieceSource == NULL)
		return NO_PIECE_IN_SOURCE;
	

	Color myColor = pieceSource->getColor();


	if (myColor != turn)
		return OTHER_PIECE_IN_SOURCE;
	

	if (!pieceSource->isLegalMoov(source, destination))
		return ILLEGAL_MOVE;
	
	
	char kind = pieceSource->getKind();

	if (isNeedCheckFreeMoovs(kind))
	{
		std::vector<Location> locations = pieceSource->allStepsRequired(source, destination);

		if (!isStepsAvailability(locations, tempBoard, destination))
			return ILLEGAL_MOVE;
		
	}
	if (pieceDest != NULL)
	{
		if (pieceSource->getColor() == pieceDest->getColor())
			return MY_PIECE_IN_TARGET;
	}

	tempBoard[destination.row][destination.col] = tempBoard[source.row][source.col];
	tempBoard[source.row][source.col] = NULL;
	
	Location myKing = getMyKingLocation(source, destination);
	Color otherColor = getOtherColor(myColor);
	Location otherKing = getOtherKingLocation(otherColor);

	if (isChess(tempBoard, myKing, myColor))
		return CHESS_ON_ME;
	
	isWhiteChess = false;
	isBlackChess = false;

	move(source, destination);

	if (isChess(tempBoard, otherKing, otherColor))
	{
		if (otherColor == Color::black)
			isBlackChess = true;
		
		else
			isWhiteChess = true;
		
	}
	
	turn = otherColor;
	setMyKingLocation(myColor, myKing);

	if ((myColor == Color::white && isBlackChess) || (myColor == Color::black && isWhiteChess))
		return CHESS_ON_OTHER;

	return LEGAL_MOVE;
	
}

Board& Board::operator=(const Board& other)
{
	whiteKingLocation = other.whiteKingLocation;
	blackKingLocation = other.blackKingLocation;
	isWhiteChess = other.isWhiteChess;
	isBlackChess = other.isBlackChess;
	turn = other.turn;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			board[i][j] = other.board[i][j];
		}
	}
	return *this;
}

std::vector<std::vector<Piece*>> Board::copyBoard()
{
	std::vector<std::vector<Piece*>>tempBoard(8, std::vector<Piece*>(8, nullptr));
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			tempBoard[i][j] = board[i][j];
		}
	}
	return tempBoard;
}

bool Board::isChess(const std::vector<std::vector<Piece*>> tempBoard, Location locationKing, Color colorKing)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (tempBoard[i][j] != NULL)
			{
				if (tempBoard[i][j]->getColor() != colorKing)
				{
					Location sourch(i, j);
					if (tempBoard[i][j]->isLegalMoov(sourch, locationKing))
					{
						std::vector<Location> locations = tempBoard[i][j]->allStepsRequired(sourch, locationKing);
						if (isStepsAvailability(locations, tempBoard, locationKing))
						{
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}

Location Board::getMyKingLocation(Location source, Location destination)
{
	if (!board[source.row][source.col]->isKing())
	{
		if (board[source.row][source.col]->getColor() == Color::white)
		{
			return whiteKingLocation;
		}
		else
		{
			return blackKingLocation;
		}
	}
	else
	{
		return Location(destination.row, destination.col);
	}
}

bool Board::isNeedCheckFreeMoovs(const char kind) const
{
	return !(kind == 'k' || kind == 'K' || kind == 'n' || kind == 'N' || kind == 'p' || kind == 'P');
}

Color Board::getOtherColor(const Color myColor) const
{
	if (myColor == Color::black)
	{
		return Color::white;
	}
	return Color::black;
}

Location Board::getOtherKingLocation(const Color otherColor) const
{
	if (otherColor == Color::black)
	{
		return blackKingLocation;
	}
	return whiteKingLocation;
}

void Board::setMyKingLocation(const Color myColor, Location myKingLocation)
{
	if (myColor == Color::black)
	{
		blackKingLocation = myKingLocation;
	}
	else
	{
		whiteKingLocation = myKingLocation;
	}
}

void Board::move(const Location source, const Location destination)
{
	if (board[destination.row][destination.col] != NULL)
	{
		delete board[destination.row][destination.col];
	}
	board[destination.row][destination.col] = board[source.row][source.col];
	board[source.row][source.col] = NULL;
}

bool Board::isLegalLocation(const Location source, const Location destination) const
{
	return 0 <= source.row && source.row < 8 && 0 <= source.col && source.col < 8 
		&& 0 <= destination.row && destination.row < 8 && 0 <= destination.col && destination.col < 8;
}