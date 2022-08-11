#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int V, maxx = -1, maxnode;
vector<pair<int, int> > vlist[100001];
int visiting[100001];

void going(int v, int dist) {
    visiting[v] = 1;
    if (maxx < dist) {
        maxx = dist;
        maxnode = v;
    }
    for (int i = 0; i < (int)vlist[v].size(); i++) {
        int nextv = vlist[v][i].first;
        int distv = vlist[v][i].second;
        //cout << nextv << "\t" << distv << endl;
        if (!visiting[nextv]) {
            going(nextv, dist+distv);
        }
    }
}

int main() {
    // input
    cin >> V;
    int temp, temp1, temp2;
    for (int i = 1; i <= V; i++) {
        cin >> temp >> temp1;
        while (temp1 != -1) {
            cin >> temp2;
            vlist[temp].push_back(make_pair(temp1, temp2));
            cin >> temp1;
        }
    }
    //
    going(1, 0);
    memset(visiting, 0, sizeof(visiting));
    going(maxnode, 0);
    //
    cout << maxx;
    return 0;
}