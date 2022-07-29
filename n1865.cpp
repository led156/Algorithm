#include <iostream>
#include <vector>
using namespace std;
#define INF 987654321

int TC, N, M, W;
int d[501];
vector<pair<pair<int, int>, int> > ver;

void vp() {
    d[1] = 0;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < ver.size(); j++) {
            int snode = ver[j].first.first; int enode = ver[j].first.second;
            int cost = ver[j].second;
            if (d[enode] > d[snode] + cost) {
                d[enode] = d[snode] + cost;
            }
        }
    }

    for (int j = 0; j < ver.size(); j++) {
        int snode = ver[j].first.first; int enode = ver[j].first.second;
        int cost = ver[j].second;
        if (d[enode] > d[snode] + cost) {
            cout << "YES\n";
            return ;
        }
    }

    cout << "NO\n";
    return;
}

int main() {
    cin >> TC;
    while (TC--) {
        cin >> N >> M >> W;
        int a, b, c;
        for (int i = 0; i < M; i++) {
            cin >> a >> b >> c;
            ver.push_back(make_pair(make_pair(a, b), c));
            ver.push_back(make_pair(make_pair(b, a), c));
        }
        for (int i = 0; i < W; i++) {
            cin >> a >> b >> c;
            ver.push_back(make_pair(make_pair(a, b), -c));
        }
        fill(d, d+501, INF);
        vp();
        ver.clear();
    }
}