#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define RIPE 1
#define NRIPE 0

int N, M, H, ans = 0;
int board[100][100][100];
int dx[6] = {-1, 0, 1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
queue<pair<pair<int, int>, int> > ripe;

bool isRipe() {
    int cnt_notRipe = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int k = 0; k < H; ++k) {
                if (board[k][i][j] == 0)
                ++cnt_notRipe;
            }
        }
    }
    return (cnt_notRipe == 0);
}

void simulation() {
    queue<pair<pair<int, int>, int> > new_ripe;

    while (!ripe.empty()) {
        int x = ripe.front().first.first;
        int y = ripe.front().first.second;
        int z = ripe.front().second;

        ripe.pop();

        for (int i = 0; i < 6; ++i) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            int nz = z+dz[i];

            if (nz >= 0 && nz < H && nx >= 0 && nx < N && ny >= 0 && ny < M && board[nz][nx][ny] == NRIPE) {
                board[nz][nx][ny] = RIPE;
                new_ripe.push(make_pair(make_pair(nx, ny), nz));
            } 
        }
    }

    ripe = new_ripe;

    if (!new_ripe.empty()) ++ans;
    return ;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> M >> N >> H;
    for (int k = 0; k < H; ++k) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cin >> board[k][i][j];
                if (board[k][i][j] == RIPE) ripe.push(make_pair(make_pair(i, j), k));
            }
        }
    }
    

    while (!ripe.empty()) simulation();

    if (isRipe()) cout << ans;
    else cout << -1;

    return 0;
}