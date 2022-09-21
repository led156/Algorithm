#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
string board[100];
bool visiting[100][100];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        cin >> board[i];
    }

    queue<pair<pair<int, int>, int> > bfs;
    bfs.push(make_pair(make_pair(0, 0), 1));
    visiting[0][0] = true;

    while(!bfs.empty()) {
        int x = bfs.front().first.first;
        int y = bfs.front().first.second;
        int cnt = bfs.front().second;
        bfs.pop();

        if (x == N-1 && y == M-1) {
            cout << cnt;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if (nx >= 0 && ny >= 0 && nx < N && ny < M && board[x][y] == '1' && !visiting[nx][ny]) {
                visiting[nx][ny] = true;
                bfs.push(make_pair(make_pair(nx, ny), cnt+1));
            }
        }
    }

    return 0;
}