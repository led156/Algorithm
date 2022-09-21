#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M, V;
vector<int> ver[1001];
bool visiting[1001];

void DFS(int node) {
    cout << node << " ";
    for (int i = 0; i < ver[node].size(); ++i) {
        int nxt_node = ver[node][i];
        if (!visiting[nxt_node]) {
            visiting[nxt_node] = true;
            DFS(nxt_node);
        }
    }
}

void BFS(int v) {
    queue<int> bfs;
    visiting[v] = true;
    bfs.push(v);

    while(!bfs.empty()) {
        int node = bfs.front();
        bfs.pop();
        cout << node << " ";

        for (int i = 0; i < ver[node].size(); ++i) {
            int nxt_node = ver[node][i];
            if (!visiting[nxt_node]) {
                visiting[nxt_node] = true;
                bfs.push(nxt_node);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> V;

    int a, b;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b;
        ver[a].push_back(b);
        ver[b].push_back(a);
    }

    for (int i = 1; i <= N; ++i) {
        sort(ver[i].begin(), ver[i].end());
    }

    visiting[V] = true;
    DFS(V);

    cout << "\n";

    fill(&visiting[0], &visiting[0]+N+1, false);
    BFS(V);

    return 0;
}