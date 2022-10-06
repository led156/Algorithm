#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int parent[500000];

int cnt = 1;
int ans = -1;

int find_p(int node) {
    if (node == parent[node]) return node;
    else return parent[node] = find_p(parent[node]);
}

void union_f(int a, int b) {
    int ap = find_p(a);
    int bp = find_p(b);

    if (ap == bp) {
        if (ans == -1) {
            ans = cnt;
        }
        return ;
    }

    if (ap > bp) {
        parent[ap] = bp;
    }
    else {
        parent[bp] = ap;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;

    for (int i = 1; i < n; ++i) {
        parent[i] = i;
    }

    int a, b;
    for (; cnt <= m; ++cnt) {
        cin >> a >> b;
        union_f(a, b);
    }

    if (ans == -1) {
        cout << 0;
    }
    else {
        cout << ans;
    }
    

    return 0;
}