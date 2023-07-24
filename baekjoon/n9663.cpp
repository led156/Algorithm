#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_LEN 16

int N, ans = 0;
int board[MAX_LEN];

bool promising(int x) {
    for (int i = 1; i < x; ++i) {
        if (board[i] == board[x] || x-i == abs(board[x]-board[i])) return false;
    }
    return true;
}

void bt(int x) {
    if (x > N) {
        ++ans;
        return ;
    }

    for (int y = 1; y <= N; ++y) {
        board[x] = y;
        if (promising(x)) bt(x+1);
    }
}

int main() {
    cin >> N;

    bt(1);

    cout << ans;

    return 0;
}