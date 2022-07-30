#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 987654321

int n, m;
vector<pair<int, int> > ver[1001];
int d[1001];
int dd[1001];
vector<int> list;
int start, endd;

void dijk(int snode) {
    priority_queue<pair<int, int> > que;
    fill(d, d+1001, INF);
    que.push(make_pair(0, snode));
    
    while (!que.empty()) {
        int tnode = que.top().second; int tcost = que.top().first;
        que.pop();

        if (d[tnode] < tcost) continue;

        for (int i = 0; i < ver[tnode].size(); i++) {
            int nnode = ver[tnode][i].first; int ncost = ver[tnode][i].second + tcost;
            if (ncost < d[nnode]) {
                d[nnode] = ncost;
                dd[nnode] = tnode;
                que.push(make_pair(ncost, nnode));
            }
        }
    }
}

void search() {
    int node = endd, pre_node;
    list.push_back(node);
    while (node != start) {
        pre_node = dd[node];
        if (pre_node == 0) {
            list.push_back(start);
            node = start;
        }
        else {
            list.push_back(pre_node);
            node = pre_node;
        }
    }
}

int main() {
    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        ver[a].push_back(make_pair(b, c));
    }
    cin >> start >> endd;

    dijk(start);
    search();
    cout << d[endd] << '\n';
    cout << list.size() << '\n';
    for (int i = list.size()-1; i >= 0; i--) {
        cout << list[i] << " ";
    }

    return 0;
}