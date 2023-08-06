#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define MAX_N 501
#define INF 987654321

int N, M, S, D, U, V, P;
vector<pair<int, int>> edges[MAX_N];
vector<pair<int, int>> redges[MAX_N];
bool is_short[MAX_N][MAX_N];

int dist[MAX_N];

void init_() {
    for (int i = 0; i < MAX_N; ++i) {
        edges[i].clear();
        redges[i].clear();
        memset(is_short, false, sizeof(is_short));
    }
}

void dijk() {
    fill(dist, dist+MAX_N, INF);
    // memset(dist, INF, sizeof(dist));
    priority_queue<pair<int, int>> que;
    que.push({0, S});
    dist[S] = 0;

    int cur_cost, cur_node, nxt_node, nxt_newcost;
    while (!que.empty()) {
        cur_node = que.top().second; cur_cost = -que.top().first;
        que.pop();
        // cout << "\n=>" << cur_node;

        if (cur_cost > dist[cur_node]) continue;

        for (pair<int, int> nxt : edges[cur_node]) {
            nxt_node = nxt.first;
            if (is_short[cur_node][nxt_node]) continue;
            nxt_newcost = cur_cost + nxt.second;
            // cout << "\n\t" << nxt_node << "   $" << nxt_newcost << " vs dist: " << dist[nxt_node];
            if (dist[nxt_node] > nxt_newcost) {
                dist[nxt_node] = nxt_newcost;
                que.push({-nxt_newcost, nxt_node});
            }
        }
    }
}

void remove_short() {
    queue<pair<int, int>> que;
    que.push({D, 0});

    int dist_node, src_node, cur_cost, s2src_cost, d2s_cost;
    while (!que.empty()) {
        dist_node = que.front().first; cur_cost = que.front().second;
        que.pop();
        
        for (pair<int, int> src : redges[dist_node]) {
            src_node = src.first;
            d2s_cost = src.second;
            s2src_cost = dist[src_node];

            if (!is_short[src_node][dist_node] && cur_cost + d2s_cost + s2src_cost == dist[D]) {
                is_short[src_node][dist_node] = true;
                que.push({src_node, cur_cost + d2s_cost});
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    while (N > 0 && M > 0) {
        init_();
        cin >> S >> D;
        for (int i = 0; i < M; ++i) {
            cin >> U >> V >> P;
            edges[U].push_back({V, P});
            redges[V].push_back({U, P});
        }

        // 최단경로를 찾고, 그 간선을 삭제.
        dijk();
        // cout << "\n-------\n";
        remove_short();
        // cout << "\n-------\n";
        dijk();

        cout << ((dist[D]!=INF) ? dist[D] : -1) << '\n';

        
        
        cin >> N >> M;
    }
    

    return 0;
}