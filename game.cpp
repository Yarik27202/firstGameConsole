#include <iostream>
#include <windows.h>
#include <fstream>
#include "board.h"
#include "player.h"
using namespace std;

static void saveResult(const string& result) {
    ofstream file("result.txt");
    if (file.is_open()) file << result << "\n";
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    cout << "Игра Крестики-нолики\n";

    int mode;
    do {
        cout << "Выберите режим:\n1 - Против компьютера\n2 - Для двух игроков\nВведите: ";
        cin >> mode;
    } while (mode != 1 && mode != 2);

    char answer = 'д';
    while (answer == 'д' || answer == 'Д') {
        char board[9];
        initBoard(board);

        char current = 'X';
        bool gameOver = false;

        while (!gameOver) {
            printBoard(board);

            if (mode == 1 && current == 'O') aiMove(board, current);
            else playerMove(board, current);

            if (checkWinner(board, current)) {
                printBoard(board);
                string result = (current == 'X') ? "Победил игрок X" :
                    (mode == 1 ? "Победил компьютер O" : "Победил игрок O");
                cout << result << "\n";
                saveResult(result);
                gameOver = true;
            }
            else if (isFull(board)) {
                printBoard(board);
                cout << "Ничья!\n";
                saveResult("Ничья");
                gameOver = true;
            }

            current = (current == 'X') ? 'O' : 'X';
        }

        cout << "Сыграть ещё раз? (д/н): ";
        cin >> answer;
    }

    cout << "Спасибо за игру!\n";
    return 0;
}
