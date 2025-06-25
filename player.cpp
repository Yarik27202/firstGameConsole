#include "player.h"
#include <iostream>
using namespace std;

void playerMove(char board[9], char mark) {
    string playerName = (mark == 'X') ? "����� 1" : "����� 2";
    int row, col;
    while (true) {
        cout << playerName << " (" << mark << "), ������� ���������� ���� (������ � �������, 1-3): ";
        cin >> row >> col;

        if (row < 1 || row > 3 || col < 1 || col > 3) {
            cout << "�������� ����������. ���������� �����.\n";
            continue;
        }

        int idx = (row - 1) * 3 + (col - 1);
        if (board[idx] == ' ') {
            board[idx] = mark;
            break;
        }
        else {
            cout << "������ ������, �������� ������.\n";
        }
    }
}

void aiMove(char board[9], char mark) {
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            board[i] = mark;
            cout << "��������� �������� " << mark << " � ������ " << (i + 1) << "\n";
            break;
        }
    }
}