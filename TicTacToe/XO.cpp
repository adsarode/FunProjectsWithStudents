/*
	Source file for tic tac toe
*/

#include <iostream>
#include <string>
#include "XO.h"

XO::XO()
{
	for (int box = 0; box < 9; box++)
	{
		mBoxes[box] = '-';
	}

	mPlayer1 = true;
}

XO::~XO()
{

}

bool XO::CheckBox(const int boxId)
{
	if (mBoxes[boxId] != '-')
	{
		std::cout << "Box already used!" << std::endl << "* Play Again!" << std::endl;
		return false;
	}

	mBoxes[boxId] = mPlayer1 ? 'X' : 'O';

	mPlayer1 = !mPlayer1;
	
	return true;
}

void XO::DisplayBoxes()
{
	system("cls");

	std::cout << "Current Game Status" << std::endl;

	std::string boxDivider = "-----+-----+-----";

	std::string boxLine1, boxLine2, boxLine3;
	for (int boxId = 0; boxId < 9; boxId++)
	{
		std::string box;
		std::string boxValue(1, mBoxes[boxId]);
		if (boxId % 3 == 0 || boxId % 3 == 1)	
			box = std::string("  ") + boxValue + std::string("  |");
		else if (boxId % 3 == 2)	
			box = std::string("  ") + boxValue + std::string("  ");

		if (boxId < 3) boxLine1 += box;
		else if (boxId < 6) boxLine2 += box;
		else if (boxId < 9) boxLine3 += box;
	}

	std::cout << boxLine1 << std::endl;
	std::cout << boxDivider << std::endl;
	std::cout << boxLine2 << std::endl;
	std::cout << boxDivider << std::endl;
	std::cout << boxLine3 << std::endl;
}

void XO::PrintInstructions()
{
	std::cout << "*** Welcome to Tic Tac Toe *** " << std::endl;
	std::cout << "*** Enter your box id *** " << std::endl;
}

bool XO::IsGameOver()
{
	// TODO: Pending Implementation

	return false;
}