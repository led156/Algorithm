#include <iostream>
#include <algorithm>
using namespace std;

int R, C, maxx = 0;
char arr[20][20];
char route[26];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int inRange(int x, int y) {
    return (x>=0 && x<R && y>=0 && y<C);
}

int promising(int x, int y, int k) {
    return inRange(x, y) && (find(route, route+k, arr[x][y]) == route+k);
}

void going(int x, int y, int k) {
    maxx = max(maxx, k);
    route[k] = arr[x][y];

    // 상하좌우 확인.
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (promising(nx, ny, k+1)) {
            going(nx, ny, k+1);
        }
    }
}

int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> arr[i][j];
        }
    }

    going(0, 0, 0);
    cout << maxx+1;
    return 0;
}