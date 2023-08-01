#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX_N 200001
#define MAX_H 21

int N, C, x, y, Q, q1, q2;
vector<vector<int>> edges(MAX_N);
bool visited[MAX_N];
int parent[MAX_H][MAX_N];
int depth[MAX_N], water[MAX_N];

void init_tree() {
    queue<int> que;
    que.push(C);
    visited[C] = true;
    depth[C] = 1;

    while(!que.empty()) {
        int cur_node = que.front();
        que.pop();

        for (int i = 0; i < edges[cur_node].size(); ++i) {
            int nxt_node = edges[cur_node][i];
            if (visited[nxt_node]) continue;
            visited[nxt_node] = true;
            que.push(nxt_node);
            depth[nxt_node] = depth[cur_node] + 1;
            parent[0][nxt_node] = cur_node;
            for (int k = 1; k < MAX_H; ++k) {
                parent[k][nxt_node] = parent[k-1][parent[k-1][nxt_node]];
            }
        }
    }
}

void fill_water(int cur_node) {
    // cout <<"->" <<cur_node<<'\n';
    
    while (true) {
        water[cur_node] += depth[cur_node];
        if (cur_node == C) break;
        cur_node = parent[0][cur_node];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> C;
    for (int i = 0; i < N-1; ++i) {
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    init_tree();

    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        cin >> q1 >> q2;
        if (q1 == 1) { // 물 채우기
            fill_water(q2);
        }
        else { // 출력
            cout << water[q2] << '\n';
        }
    }


    return 0;
}