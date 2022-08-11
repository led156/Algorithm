#include <iostream>
#include <cstring>
using namespace std;

int N, M;
int board[100][100];
int air[100][100];
int visiting[100][100];
int check[100][100];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int inRange(int x, int y) {
    return (x>=0 && x<N && y>=0 && y<M);
}

void airCheck(int x, int y) {
    visiting[x][y] = 1;
    int nx, ny;
    for (int i = 0; i < 4; i++) {
        nx = x+dx[i]; ny = y+dy[i];
        if (inRange(nx, ny) && !board[nx][ny] && !visiting[nx][ny]) {
            air[nx][ny] = 1;
            airCheck(nx, ny);
        }
    }
}

int simulation() {
    // air, check 초기화
    memset(air, 0, sizeof(air));
    memset(check, 0, sizeof(check));
    memset(visiting, 0, sizeof(visiting));
    // air check
    airCheck(0, 0);

    // board 탐색.
    int nx, ny;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j]) {
                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    nx = i+dx[k]; ny = j+dy[k];
                    if (inRange(nx, ny) && air[nx][ny]) cnt++;
                }
                if (cnt > 1) {
                    check[i][j] = 1;
                }
            }
        }
    }

    // check 확인후, board 업데이트
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (check[i][j]) board[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j]) return 1;
        }
    }

    return 0;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    int t = 1;
    while (simulation()) t++;
    cout << t;
    return 0;
}