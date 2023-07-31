#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 1000001

int n, m, k, a, b;
int parent[MAX_N];

void init_parent() {
    for (int i = 0; i <= n; ++i) {
        parent[i] = i;
    }
}


int find_parent(int a) {
    if (parent[a] == a) return a;
    return parent[a] = find_parent(parent[a]);
}


void union_parent(int a, int b) {
    int ap = find_parent(a);
    int bp = find_parent(b);

    if (ap != bp) {
        if (ap >= bp) parent[bp] = ap;
        else parent[ap] = bp;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    init_parent();

    for (int i = 0; i < m; ++i) {
        cin >> k >> a >> b;
        if (k) { // 포함 확인
            if (find_parent(a) == find_parent(b)) cout << "YES\n";
            else cout << "NO\n";
        }
        else { // 합집합
            union_parent(a, b);
        }
    }

    return 0;
}