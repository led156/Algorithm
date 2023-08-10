#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 1001
typedef long long ll;

int N, P, C, ap, bp;
ll sum = 0;
vector<pair<int, int>> PC(MAX_N);
vector<pair<int, pair<int, int>>> edges;
vector<int> new_edges[MAX_N];
int parent[MAX_N];


int find_parent(int a) {
    if (parent[a] == a) return a;
    return parent[a] = find_parent(parent[a]);
}

void dfs(int cur, int target) {
    for (int nxt : new_edges[cur]) {
        if (nxt != target) dfs(nxt, cur);
    }
    if (target) cout << target << " " << cur << '\n'; 
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> P >> C;
        parent[i] = i;
        PC[i] = {P, C};
    }
    for (int i = 1; i < N; ++i) {
        for (int j = i+1; j <= N; ++j) {
            edges.push_back({ (PC[i].second+PC[j].second)/abs(PC[i].first-PC[j].first) , {i, j} });
        }
    }

    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());
    for (pair<int, pair<int, int>> e : edges) {
        ap = find_parent(e.second.first);
        bp = find_parent(e.second.second);
        if (ap != bp) {
            sum += e.first;
            
            new_edges[e.second.first].push_back(e.second.second);
            new_edges[e.second.second].push_back(e.second.first);
            
            parent[ap] = bp;
        }
    }

    cout << sum << '\n';
    dfs(1, 0);

    return 0;
}