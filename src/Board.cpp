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
	initBoard();
}

Board::~Board() {
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			delete board[i][j];
		}
		board[i].clear();
	}
	board.clear();
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
	

	if (!pieceSource->isLegalMove(source, destination))
		return ILLEGAL_MOVE;
	
	
	char kind = pieceSource->getKind();

	if (isPawn(kind))
	{
		if (!isValidForPawn(source, destination))
			return ILLEGAL_MOVE;
	}

	if (isNeedCheckFreeMoves(kind))
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

	if (isPawn(kind))
		setIsFirstStepForPawn(source);

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
					if (tempBoard[i][j]->isLegalMove(sourch, locationKing))
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

bool Board::isNeedCheckFreeMoves(const char kind) const
{
	return !(kind == 'k' || kind == 'K' || kind == 'n' || kind == 'N');
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

void Board::initBoard()
{
	board[0][0] = new Rook(Color::white, 'R');
	board[0][1] = new Knight(Color::white, 'N');
	board[0][2] = new Bishop(Color::white, 'B');
	board[0][3] = new Queen(Color::white, 'Q');
	board[0][4] = new King(Color::white, 'K');
	board[0][5] = new Bishop(Color::white, 'B');
	board[0][6] = new Knight(Color::white, 'N');
	board[0][7] = new Rook(Color::white, 'R');

	board[1][0] = new Pawn(Color::white, 'P');
	board[1][1] = new Pawn(Color::white, 'P');
	board[1][2] = new Pawn(Color::white, 'P');
	board[1][3] = new Pawn(Color::white, 'P');
	board[1][4] = new Pawn(Color::white, 'P');
	board[1][5] = new Pawn(Color::white, 'P');
	board[1][6] = new Pawn(Color::white, 'P');
	board[1][7] = new Pawn(Color::white, 'P');

	board[7][0] = new Rook(Color::black, 'r');
	board[7][1] = new Knight(Color::black, 'n');
	board[7][2] = new Bishop(Color::black, 'b');
	board[7][3] = new Queen(Color::black, 'q');
	board[7][4] = new King(Color::black, 'k');
	board[7][5] = new Bishop(Color::black, 'b');
	board[7][6] = new Knight(Color::black, 'n');
	board[7][7] = new Rook(Color::black, 'r');

	board[6][0] = new Pawn(Color::black, 'p');
	board[6][1] = new Pawn(Color::black, 'p');
	board[6][2] = new Pawn(Color::black, 'p');
	board[6][3] = new Pawn(Color::black, 'p');
	board[6][4] = new Pawn(Color::black, 'p');
	board[6][5] = new Pawn(Color::black, 'p');
	board[6][6] = new Pawn(Color::black, 'p');
	board[6][7] = new Pawn(Color::black, 'p');
}

bool Board::isValidForPawn(const Location source, const Location destination)
{
	Pawn* pawn = dynamic_cast<Pawn*>(board[source.row][source.col]);

	int distanceRow = abs(source.row - destination.row);
	if (distanceRow == 2)
	{
		if (pawn->getIsFirstStep())
			return true;
		else
			return false;
	}

	else if (board[destination.row][destination.col] == NULL)
	{
		if (destination.col == source.col)
			return true;
	}

	else if (destination.col != source.col)
		return true;

	return false;
}

void Board::setIsFirstStepForPawn(Location source)
{
	Pawn* pawn = dynamic_cast<Pawn*>(board[source.row][source.col]);
	pawn->setIsFIrstStep();
}

bool Board::isPawn(char kind)
{
	return kind == 'p' || kind == 'P';
}