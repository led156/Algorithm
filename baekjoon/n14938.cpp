#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
using namespace std;

int n, m, r;

vector<pair<int, int> > ver[102];
int item[102];
int dist[102];


int dijk(int node) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }

    priority_queue<pair<int, int> > que;

    dist[node] = 0;
    que.push(make_pair(0, node));
    
    while (!que.empty()) {
        int tnode = que.top().second; int tcost = que.top().first;
        que.pop();

        for (int i = 0; i < ver[tnode].size(); i++) {
            int nnode = ver[tnode][i].first; int ncost = ver[tnode][i].second + tcost;
            if (ncost < dist[nnode]) {
                dist[nnode] = ncost;
                que.push(make_pair(ncost, nnode));
            }
        }
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] <= m) sum += item[i];
    }

    return sum;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m >> r;
    
    for (int i = 1; i <= n; i++) {
        cin >> item[i];
    }
    for (int i = 0; i < r; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        ver[a].push_back(make_pair(b, l));
        ver[b].push_back(make_pair(a, l));
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dijk(i));
    }

    cout << ans;

    return 0;
}