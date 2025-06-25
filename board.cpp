#include "board.h"
#include <iostream>
using namespace std;

void initBoard(char board[9]) {
    for (int i = 0; i < 9; i++) {
        board[i] = ' ';
    }
}

void printBoard(const char board[9]) {
    cout << "\n";
    for (int i = 0; i < 9; i++) {
        cout << " " << (board[i] == ' ' ? '.' : board[i]) << " ";
        if ((i + 1) % 3 == 0) {
            if (i != 8) cout << "\n---+---+---\n";
            else cout << "\n";
        }
        else {
            cout << " ";
        }
    }
    cout << "\n";
}

bool checkWinner(const char board[9], char mark) {
    int lines[8][3] = {
        {0,1,2},{3,4,5},{6,7,8},
        {0,3,6},{1,4,7},{2,5,8},
        {0,4,8},{2,4,6}
    };

    for (int i = 0; i < 8; i++) {
        if (board[lines[i][0]] == mark &&
            board[lines[i][1]] == mark &&
            board[lines[i][2]] == mark) {
            return true;
        }
    }
    return false;
}

bool isFull(const char board[9]) {
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') return false;
    }
    return true;
}
