#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define RIPE 1
#define NRIPE 0

int N, M, ans = 0;
int board[1000][1000];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int> > ripe;
int not_ripe_cnt;

bool isRipe() {
    int cnt_notRipe = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (board[i][j] == 0)
                ++cnt_notRipe;
        }
    }
    return (cnt_notRipe == 0);
}

void simulation() {
    queue<pair<int, int> > new_ripe;

    while (!ripe.empty()) {
        int x = ripe.front().first;
        int y = ripe.front().second;

        ripe.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && board[nx][ny] == NRIPE) {
                board[nx][ny] = RIPE;
                --not_ripe_cnt;
                new_ripe.push(make_pair(nx, ny));
            } 
        }
    }

    ripe = new_ripe;

    if (!new_ripe.empty()) ++ans;
    return ;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> M >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
            if (board[i][j] == RIPE) ripe.push(make_pair(i, j));
            if (board[i][j] == NRIPE) ++not_ripe_cnt;
        }
    }

    while (!ripe.empty()) simulation();

    // if (isRipe()) cout << ans;
    // else cout << -1;

    if (not_ripe_cnt > 0) cout << -1;
    else cout << ans;

    return 0;
}