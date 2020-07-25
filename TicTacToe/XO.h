/*
	Header file for tic tac toe
*/

#pragma once

class XO
{
public:
	XO();	// Constructor
	~XO();	// Destructor

	void PrintInstructions();
	void DisplayBoxes();
	bool CheckBox(const int boxId);

	bool IsGameOver();

private:
	char mBoxes[9];
	bool mPlayer1;
};
