#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX_n 100001
#define INF 987654321

int n, m, a, b, c, s, t, sum = 0;
vector<pair<int, int>> edges[MAX_n];
int dist[MAX_n];

void dijk(int cur_node) {
    priority_queue<pair<int, pair<int, int>>> que;
    int cur_cost = 0, nxt_node, nxt_cost, cur_max, new_cost;
    que.push({cur_cost, {cur_node, cur_cost}});
    dist[cur_node] = cur_cost;

    while (!que.empty()) {
        pair<int, pair<int, int>> cur = que.top();
        cur_node = cur.second.first;
        cur_cost = -cur.first;
        cur_max = cur.second.second;
        que.pop();

        if (dist[cur_node] < cur_cost) continue;

        for (pair<int, int> nxt : edges[cur_node]) {
            nxt_node = nxt.first;
            nxt_cost = nxt.second;

            // dist = 진짜 경로 - 경로 중 가장 큰 값
            // 만약 지나온 간선(cur_max)보다 현재 엣지(nxt_cost)가 더 큰 값을 지닌다면 cur_cost + cur_max + nxt_cost - nxt_cost
            // 작은값을 지닌다면 cur_cost + (cur_max - cur_max) + nxt_cost 
            new_cost = cur_cost + cur_max + nxt_cost - max(cur_max, nxt_cost);
            if (dist[nxt_node] > new_cost) {
                dist[nxt_node] = new_cost;
                que.push({-new_cost, {nxt_node, max(cur_max, nxt_cost)}});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
        sum += c;
    }
    fill(&dist[0], &dist[0]+MAX_n, INF);
    cin >> s >> t;

    dijk(s);

    cout << sum - dist[t];

    return 0;
}