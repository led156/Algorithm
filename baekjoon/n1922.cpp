#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 1001

struct edge
{
    /*
        cost : 비용
        A : 노드1
        B : 노드2
    */
    int cost;
    int A;
    int B;
};

bool comp(edge& e1, edge& e2) {
    if (e1.cost == e2.cost){
        if (e1.A == e2.A) return e1.B < e2.B;
        else return e1.A < e2.A;
    }
    else return e1.cost < e2.cost;
}

int N, M, a, b, c, cnt = 0, ans = 0;
int parent[MAX_N];
vector<edge> edges;

void init_parent() {
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
    }
}

int find_parent(int a) {
    if (a == parent[a]) return a;
    return parent[a] = find_parent(parent[a]);
}

void union_parent(int a, int b) {
    int ap = parent[a];
    int bp = parent[b];

    if (ap!=bp) {
        if (ap >= bp) {
            parent[bp] = ap;
        }
        else {
            parent[ap] = bp;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    init_parent();

    for (int i = 0; i < M; ++i) {
        cin >> a >> b >> c;
        edges.push_back({c, a, b});
    }

    sort(edges.begin(), edges.end(), comp);

    for (int i = 0; i < edges.size() && cnt < N-1; ++i) {
        edge e = edges[i];
        if (find_parent(e.A) == find_parent(e.B)) continue;
        
        ans += e.cost;
        ++cnt;
        union_parent(e.A, e.B);
    }

    cout << ans;

    return 0;
}