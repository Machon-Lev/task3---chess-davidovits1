// Chess 
#include "Chess.h"
#include "Tools.h"
#include "Board.h"

int main()
{
	string board = "RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr"; 
//	string board = "##########K###############################R#############r#r#####";
	Chess a(board);
	int codeResponse = 0;
	string res = a.getInput();
	int row, col;
	std::pair<int, int> firstStr, secondStr;
	while (res != "exit")
	{
		/* 
		codeResponse value : 
		Illegal movements : 
		11 - there is not piece at the source  
		12 - the piece in the source is piece of your opponent
		13 - there one of your pieces at the destination 
		21 - illegal movement of that piece 
		31 - this movement will cause you checkmate

		legal movements : 
		41 - the last movement was legal and cause check 
		42 - the last movement was legal, next turn 
		*/

		/**/ 
		std::string firstTwoLetters = res.substr(0, 2);
		std::string secondTwoLetters = res.substr(2, 4);
		firstStr = inputAnalysis(firstTwoLetters);
		row = firstStr.first;
		col = firstStr.second;
		Location source(row, col);
		secondStr = inputAnalysis(secondTwoLetters);
		row = secondStr.first;
		col = secondStr.second;
		Location destination(row, col);
		{ // put your code here instead that code
			cout << "code response >> ";
			cin >> codeResponse;
		}
		/**/

		a.setCodeResponse(codeResponse);
		res = a.getInput(); 
	}

	cout << endl << "Exiting " << endl; 
	return 0;
}