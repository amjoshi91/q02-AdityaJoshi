/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
#include <iostream>
using namespace std; 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, constructorRESET)
{
	Piezas board;
	bool checker = true;
	int i, j;
	for(i = 0; i < BOARD_ROWS; i++)
	{
		for(j = 0; j < BOARD_COLS; j++)
		{
			if(board.pieceAt(i,j) != Blank)
				checker = false;
		}
	}
	board.dropPiece(1);
	board.reset();
	
	for(i = 0; i < BOARD_ROWS; i++)
	{
		for(j = 0; j < BOARD_COLS; j++)
		{
			if(board.pieceAt(i,j) != Blank)
			checker = false;
		}
	}
	
	ASSERT_TRUE(checker);
}

TEST(PiezasTest, ExtraDROPS)
{
	Piezas board;
	bool checker = true;
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(1);
	if(board.dropPiece(1) == Blank)
		checker = true;
	ASSERT_TRUE(checker);
}
	
TEST(PiezasTest, invalidCOL)
{
	Piezas board;
	bool checker = false;
	if(board.dropPiece(100) == Invalid)
		checker = true;
	ASSERT_TRUE(checker);
}

TEST(PiezasTest, checkForInvalidPiece)
{
	Piezas board;
	bool checker = false;
	if(board.pieceAt(8,3) == Invalid)
		checker = true;
	ASSERT_TRUE(checker);
}

TEST(PiezasTest, checkIfPieceDroppedSuccessfully)
{
	Piezas board;
	bool checker = false;
	board.dropPiece(2);
	if(board.pieceAt(BOARD_ROWS-1,2) == X)
		checker = true;
	ASSERT_TRUE(checker);
}

TEST(PiezasTest,gameNotOver)
{
	Piezas board;
	bool checker = false;
	if(board.gameState() == Invalid)
		checker = true;
	ASSERT_TRUE(checker);
}

TEST(PiezasTest, xWins)
{
	Piezas board;
	bool checker = false;
	board.dropPiece(0);
	board.dropPiece(0);

	board.dropPiece(1);
	board.dropPiece(0);

	board.dropPiece(2);
	board.dropPiece(1);

	board.dropPiece(3);
	board.dropPiece(1);

	board.dropPiece(3);
	board.dropPiece(2);
	
	board.dropPiece(2);
	board.dropPiece(3);
	
/*	for(int i = 0; i < BOARD_ROWS; i++)
	{
		for(int j = 0; j < BOARD_COLS; j++)
		{
			if(board.pieceAt(i,j) == X)
				cout << "X" << " ";
			if(board.pieceAt(i,j) == O)
				cout << "O" << " ";
			if(board.pieceAt(i,j) == Blank)
				cout << "B" << " ";
			if(board.pieceAt(i,j) == Invalid)
				cout << "I" << " ";
		}
		cout << endl;
	}
	cout << "here";
*/
	if(board.gameState() == X)
		checker = true;
	ASSERT_TRUE(checker);

}

TEST(PiezasTest, noWinner)
{
	Piezas board;
	bool checker = false;
	
	board.dropPiece(0);
	board.dropPiece(0);

	board.dropPiece(1);
	board.dropPiece(1);
	
	board.dropPiece(2);
	board.dropPiece(2);
	
	board.dropPiece(3);
	board.dropPiece(3);

	board.dropPiece(0);
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(3);

	if(board.gameState() == Blank)
		checker = true;
	ASSERT_TRUE(checker);
}

TEST(PiezasTest, oWinner)
{
	
	Piezas board;
	bool checker = false;
	
	board.dropPiece(0);
	board.dropPiece(0);

	board.dropPiece(1);
	board.dropPiece(1);
	
	board.dropPiece(2);
	board.dropPiece(2);
	
	board.dropPiece(0);
	board.dropPiece(3);

	board.dropPiece(2);
	board.dropPiece(3);
	board.dropPiece(1);
	board.dropPiece(3);

	if(board.gameState() == O)
		checker = true;
	ASSERT_TRUE(checker);
}
