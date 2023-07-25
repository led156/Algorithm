#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define MAX_N 50

int N, ans = 1000001;
char board[MAX_N][MAX_N];
int flyboard[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
vector<int> fly;
int x, y, house_size = 0;


int dx[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

bool isRange(int a, int b) {
    return a >= 0 && a < N && b >= 0 && b < N;
}

bool bfs(int minfly, int maxfly) {
    queue<pair<int, int> > que;
    que.push({x, y});
    visited[x][y] = true;

    int nx, ny, cnt = 0;
    while (!que.empty()) {
        pair<int, int> xy = que.front();
        que.pop();

        if (board[xy.first][xy.second] == 'K') {
            ++cnt;
            if (cnt == house_size) return true;
        }


        for (int dir = 0; dir < 8; ++dir) {
            nx = xy.first + dx[dir];
            ny = xy.second + dy[dir];
            if (isRange(nx, ny) && !visited[nx][ny] && flyboard[nx][ny] >= minfly && flyboard[nx][ny] <= maxfly) {
                que.push({nx, ny});
                visited[nx][ny] = true;
            }

        }
    }
    return false;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 'P') {
                x = i;
                y = j;
            }
            if (board[i][j] == 'K') ++house_size;
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> flyboard[i][j];
            fly.push_back(flyboard[i][j]);
        }
    }

    sort(fly.begin(), fly.end());
    fly.erase(unique(fly.begin(), fly.end()), fly.end());

    int left_idx = 0;
    int right_idx = 0;

    while (right_idx < fly.size()) {
        while (true) {
            if (flyboard[x][y] >= fly[left_idx] && flyboard[x][y] <= fly[right_idx]) {
                memset(visited, false, sizeof(visited));
                // cout << "\nBFS ";
                if (!bfs(fly[left_idx], fly[right_idx])) break;

                if (fly[right_idx] - fly[left_idx] < ans) ans = fly[right_idx] - fly[left_idx];
                ++left_idx;
            }
            else break;
        }
        ++right_idx;
    }

    cout << ans;

    return 0;
}