#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int N, M, X, ans = -1;
vector<pair<int, int> > T[10001];
int d[1001];
int store_dist[1001];

void dijk(int node) {
    fill(d, d + 1001, INF);
    d[node] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > vlist;
    vlist.push(pair<int, int>(0, node));

    while (!vlist.empty()) {
        int s_node = vlist.top().second;
        int s_dist = vlist.top().first;
        vlist.pop();

        for (int i = 0; i < T[s_node].size(); i++) {
            int n_node = T[s_node][i].first;
            int n_dist = s_dist + T[s_node][i].second;
            if (n_dist < d[n_node]) {
                d[n_node] = n_dist;
                vlist.push(pair<int, int>(n_dist, n_node));
            }
        }
    }
}

int main() {
    // 1. input.
    cin >> N >> M >> X;
    int one, two, thr;
    for (int i = 0; i < M; i++) {
        cin >> one >> two >> thr;
        T[one].push_back(pair<int, int>(two, thr));
    }

    // 2. -> X.
    for (int i = 1; i <= N; i++) {
        dijk(i);
        store_dist[i] = d[X];
    }

    // 3. X ->
    dijk(X);
    for (int i = 1; i <= N; i++) {
        store_dist[i] += d[i];
        ans = max(ans, store_dist[i]);
    }
    cout << ans;
    
    return 0;
}