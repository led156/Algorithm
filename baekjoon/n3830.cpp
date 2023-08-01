#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 100001

int N, M, a, b, c;
char k;
int parent[MAX_N];
long long cost[MAX_N];

void init_parent() {
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
        cost[i] = 0;
    }
}

int find_parent(int anode) {
    if (parent[anode] == anode) return anode;
    int p = find_parent(parent[anode]);
    cost[anode] += cost[parent[anode]];
    return parent[anode] = p;
}

void union_parent(int anode, int bnode, int w) {
    int ap = find_parent(anode);
    int bp = find_parent(bnode);

    if (ap == bp) return ;

    cost[bp] = cost[anode] - cost[bnode] + w;
    parent[bp] = ap;
    return ;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    while (N!=0 && M!=0) {
        init_parent();
        for (int i = 0; i < M; ++i) {
            cin >> k;
            if (k=='!') { // 무게 잼
                cin >> a >> b >> c; // a < b. a+c == b
                union_parent(a, b, c);
            }
            else { // 교수님 질문
                cin >> a >> b;
                if (find_parent(a) == find_parent(b)) {
                    cout << cost[b] - cost[a] << '\n';
                }
                else cout << "UNKNOWN\n";
            }
        }
        cin >> N >> M;
    }

    return 0;
}