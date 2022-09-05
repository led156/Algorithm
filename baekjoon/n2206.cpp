#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
using namespace std;

int N, M;
int board[1000][1000];
int visiting[1000][1000][2];
vector<pair<int, int> > walls;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int ans = INF;

int bfs() {
    queue<pair<pair<int, int>, pair<int, int> > > que;
    que.push(make_pair(make_pair(0, 0), make_pair(1, 0)));
    
    visiting[0][0][0] = 1;

    while (!que.empty()) {
        int x = que.front().first.first;
        int y = que.front().first.second;
        int cnt = que.front().second.first;
        int boole = que.front().second.second;
        que.pop();

        if (x >= N-1 && y >= M-1) return cnt;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            if (!board[nx][ny] && !visiting[nx][ny][boole]) {
                que.push(make_pair(make_pair(nx, ny), make_pair(cnt+1, boole)));
                visiting[nx][ny][boole] = 1;
            }
            else if (board[nx][ny] && boole == 0) {
                que.push(make_pair(make_pair(nx, ny), make_pair(cnt+1, boole+1)));
                visiting[nx][ny][boole+1] = 1;
            }
        }
    }
    return -1;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    
    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            board[i][j] = s[j] - '0';
        }
    }

    cout << bfs();
    
    return 0;
}