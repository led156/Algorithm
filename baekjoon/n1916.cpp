#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321

int N, M, A, B;
int d[1001];
vector<pair<int, int> > cost[1001];

void djk(int node) {
    fill(d, d + 1001, INF);
    d[node] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que;
    que.push(make_pair(0, node));
    

    while (!que.empty()) {
        int tnode = que.top().second; int tcost = -que.top().first;
        que.pop();

        if (d[tnode] < tcost) continue;

        for (int i = 0; i < cost[tnode].size(); i++) {
            int nnode = cost[tnode][i].first;
            int ncost = cost[tnode][i].second + tcost;
            if (d[nnode] > ncost) {
                d[nnode] = ncost;
                que.push(make_pair(-d[nnode], nnode));
            }
        }
    }
}

int main() {
    cin >> N >> M;
    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        cost[a].push_back(make_pair(b, c));
    }
    cin >> A >> B;
    djk(A);
    cout << d[B];
    return 0;
}