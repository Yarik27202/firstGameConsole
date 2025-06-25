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

    cout << "���� ��������-������\n";

    int mode;
    do {
        cout << "�������� �����:\n1 - ������ ����������\n2 - ��� ���� �������\n�������: ";
        cin >> mode;
    } while (mode != 1 && mode != 2);

    char answer = '�';
    while (answer == '�' || answer == '�') {
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
                string result = (current == 'X') ? "������� ����� X" :
                    (mode == 1 ? "������� ��������� O" : "������� ����� O");
                cout << result << "\n";
                saveResult(result);
                gameOver = true;
            }
            else if (isFull(board)) {
                printBoard(board);
                cout << "�����!\n";
                saveResult("�����");
                gameOver = true;
            }

            current = (current == 'X') ? 'O' : 'X';
        }

        cout << "������� ��� ���? (�/�): ";
        cin >> answer;
    }

    cout << "������� �� ����!\n";
    return 0;
}
