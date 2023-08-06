#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX_N 100001
#define MAX_H 21
#define PARENT 0
#define SHORT 1
#define LONG 2
#define INF 987654321

int N, A, B, C, K, D, E;

int parent[MAX_H][MAX_N][3];
int depth[MAX_N];
vector<pair<int, int>> edges[MAX_N];
pair<int, int> res;

void bfs(int cur_node) {
    queue<int> que;
    que.push(cur_node);
    depth[cur_node] = 1;
    parent[0][cur_node][SHORT] = INF;
    
    while (!que.empty()) {
        cur_node = que.front();
        que.pop();

        for (pair<int, int> nxt : edges[cur_node]) {
            int nxt_node = nxt.first;
            int nxt_cost = nxt.second;

            if (depth[nxt_node]) continue;

            depth[nxt_node] = depth[cur_node] + 1;
            parent[0][nxt_node][PARENT] = cur_node;
            parent[0][nxt_node][SHORT] = parent[0][nxt_node][LONG] = nxt_cost;

            for (int h = 1; h < MAX_H; ++h) {
                parent[h][nxt_node][PARENT] = parent[h-1][parent[h-1][nxt_node][PARENT]][PARENT];
                parent[h][nxt_node][SHORT] = min(parent[h-1][parent[h-1][nxt_node][PARENT]][SHORT], parent[h-1][nxt_node][SHORT]);
                parent[h][nxt_node][LONG] = max(parent[h-1][parent[h-1][nxt_node][PARENT]][LONG], parent[h-1][nxt_node][LONG]);
            }

            que.push(nxt_node);
        }
    }
}

pair<int, int> lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);

    pair<int, int> res = {INF, 0};

    for (int h = 20; h >= 0; --h) { // 같을 때까지 올라가기
        if (depth[b] <= depth[parent[h][a][PARENT]]) {
            res.first = min(res.first, parent[h][a][SHORT]);
            res.second = max(res.second, parent[h][a][LONG]);
            a = parent[h][a][PARENT];
        }
        // cout << '-';
    }

    // cout << "== " << a << " " << b << '\n';
    

    if (a == b) return res;
    
    for (int h = 20; h >= 0; --h) {
        if (parent[h][a][PARENT] != parent[h][b][PARENT]) {
            res.first = min(res.first, min(parent[h][a][SHORT], parent[h][b][SHORT]));
            res.second = max(res.second, max(parent[h][a][LONG], parent[h][b][LONG]));
            a = parent[h][a][PARENT];
            b = parent[h][b][PARENT];
        }
        // cout << '+';
    }

    res.first = min(res.first, min(parent[0][a][SHORT], parent[0][b][SHORT]));
    res.second = max(res.second, max(parent[0][a][LONG], parent[0][b][LONG]));
    return res;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N-1; ++i) {
        cin >> A >> B >> C;
        edges[A].push_back({B, C});
        edges[B].push_back({A, C});
    }

    // 루트부터 시작해 부모 조상, 조상으로부터의 최단, 최장 가중치를 저장
    bfs(1);

    cin >> K;
    for (int i = 0; i < K; ++i) {
        cin >> D >> E;
        res = lca(D, E);
        cout << res.first << " " << res.second << '\n';
    }
    // LCA
    // 같은 높이까지 올라간 후
    // 줄이면서 이동
    return 0;
}