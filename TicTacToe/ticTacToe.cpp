#include <iostream>
#include <string>

using namespace std;

char square[10];

void board();
int setCell(int choice, char mark);
int checkwin();

int main()
{
    int player = 1, i, choice;
    char mark;

    // init square array
    for (int i = 0; i < 10; i++) {
        square[i] = '0' + i;
    }

    do {
        board();
        player = (player % 2) ? 1 : 2;

        cout << "Player " << player << ", enter a number:  ";
        cin >> choice;

        mark = (player == 1) ? 'X' : 'O';

        // set the cell of square array
        int setRet = setCell(choice, mark);
        if (setRet == -1) {
            cout << "Invalid move";
            player--;
            cin.ignore();
            cin.get();
        }
        // check if someone win
        i = checkwin();
        player++;
    } while (i == -1);
    board();

    if (i == 1) {
        cout << "==>\aPlayer " << --player << " win ";
    }
    else {
        cout << "==>\aGame draw";
    }
}

void board()
{
    system("cls");
    cout << "\n\n\tTic Tac Toe\n\n";

    cout << "Player 1 (X) - Player 2 (O)" << endl << endl;
    cout << endl;

    string cellLine = "     |     |     ";
    string cellLineWithDash = "_____|_____|_____";
    for (int i = 1; i < 8; i += 3) {
        if (i == 1) {
            cout << cellLine << endl;
        }
        cout << "  " << square[i] << "  |  " << square[i + 1] << "  |  " << square[i + 2] << endl;
        if (i != 7) {
            cout << cellLineWithDash << endl;
            cout << cellLine << endl;
        }
        else {
            cout << cellLine << endl << endl;
        }
    }
}

int checkwin()
{
    for (int i = 1; i < 10; i++) {
        if ((i % 3 == 1 && (square[i] == square[i + 1] && square[i + 1] == square[i + 2])) or
            (i <= 3 && (square[i] == square[i + 3] && square[i + 3] == square[i + 6])) or
            (i == 1 && (square[1] == square[5] && square[5] == square[9])) or
            (i == 3 && (square[3] == square[5] && square[5] == square[7]))) {
            return 1;
        }
        if (square[i] == '0' + i) {
            return -1;
        }
    }
    return 0;
}

int setCell(int choice, char mark)
{
    if (square[choice] == '0' + choice) {
        square[choice] = mark;
        return 1;
    }
    else {
        return -1;
    }
}