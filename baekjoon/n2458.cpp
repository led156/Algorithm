#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX_N 501


int N, M, a, b, ans = 0;
vector<int> graph[2][MAX_N];
int visited[MAX_N];

int bfs(int mode, int node) {
    queue<int> que;
    que.push(node);
    visited[node] = node;
    int cnt = 0;

    while (!que.empty()) {
        int cur_node = que.front();
        que.pop();

        for (int i = 0; i < graph[mode][cur_node].size(); ++i) {
            int nxt_node = graph[mode][cur_node][i];
            if (visited[nxt_node]!=node) {
                visited[nxt_node] = node;
                que.push(nxt_node);
                ++cnt;
            }
        }
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b; // a < b
        graph[0][a].push_back(b);
        graph[1][b].push_back(a);
    }

    for (int node = 1; node <= N; ++node) {
        if (N-1 == (bfs(0, node) + bfs(1, node))) ++ans;
    }

    cout << ans;

    return 0;
}