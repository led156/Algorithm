#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
vector<pair<int, pair<int, int> > > ver;
int parent[100001];

int find(int node) {
    if (parent[node] == node) return node;
    else return parent[node] = find(parent[node]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    int node1, node2, cost;
    for (int i = 0; i < M; ++i) {
        cin >> node1 >> node2 >> cost;
        ver.push_back(make_pair(cost, make_pair(node1, node2)));
    }

    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
    }

    sort(ver.begin(), ver.end());


    int ans = 0;
    int last = 0;
    for (int i = 0; i < ver.size(); ++i) {
        cost = ver[i].first;
        node1 = ver[i].second.first;
        node2 = ver[i].second.second;

        int node1_p = find(node1);
        int node2_p = find(node2);
        if (node1_p != node2_p) {
            ans += cost;
            last = cost;
            parent[node1_p] = node2_p;
        }
    }

    cout << ans - last;

    return 0;
}