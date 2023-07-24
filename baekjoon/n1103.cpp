#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_LEN 50

int N, M;
char board[MAX_LEN][MAX_LEN];
int dp[MAX_LEN][MAX_LEN];
bool visited[MAX_LEN][MAX_LEN];
bool loop = false;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void init() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            dp[i][j] = -1;
        }
    }
}

bool isRange(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int dfs(int x, int y) {
    if (!isRange(x, y) || board[x][y] == 'H') {
        return 0;
    }

    if (visited[x][y]) {
        loop = true;
        return -1;
    }

    if (dp[x][y] != -1) {
        return dp[x][y];
    }


    dp[x][y] = 0;
    visited[x][y] = true;
    int nx, ny;
    for (int dir = 0; dir < 4 && !loop; ++dir) {
        nx = x + dx[dir]*(board[x][y]-'0');
        ny = y + dy[dir]*(board[x][y]-'0');

        dp[x][y] = max(dp[x][y], 1 + dfs(nx, ny));
    }
    visited[x][y] = false;

    return dp[x][y];
}

int main() {
    cin >> N >> M;
    
    init();

    char c;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
        }
    }

    int ans = dfs(0, 0);
    if (loop) cout << -1;
    else cout << ans;

    return 0;
}