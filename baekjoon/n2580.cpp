#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_LEN 9

int board[MAX_LEN][MAX_LEN];
vector<pair<int, int> > empty_list;

bool promising(int num, int x, int y) {
    for (int i = 0; i < MAX_LEN; ++i) {
        if (board[i][y] == num) return false;
    }

    for (int i = 0; i < MAX_LEN; ++i) {
        if (board[x][i] == num) return false;
    }

    int gridx = (x/3)*3, gridy = (y/3)*3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[gridx+i][gridy+j] == num) return false;
        }
    }
    return true;
}

void print_board() {
    for (int i = 0; i < MAX_LEN; ++i) {
        for (int j = 0; j < MAX_LEN; ++j) {
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }
}

void bt(int idx) {
    if (idx >= empty_list.size()) {
        print_board();
        exit(0);
    }

    int x = empty_list[idx].first, y = empty_list[idx].second;

    for (int num = 1; num <= MAX_LEN; ++num) {
        if (promising(num, x, y)) {
            board[x][y] = num;
            bt(idx+1);
            board[x][y] = 0;
        }
    }
}


int main() {
    for (int i = 0; i < MAX_LEN; ++i) {
        for (int j = 0; j < MAX_LEN; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 0) empty_list.push_back({i, j});
        }
    }

    bt(0);

    return 0;
}