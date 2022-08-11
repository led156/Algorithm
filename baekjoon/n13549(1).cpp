#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 100001
using namespace std;

int N, K;
int d[MAX];

int isRange(int node) { return node >= 0 && node < MAX; }

void dijk() {
    priority_queue<pair<int, int> > que;
    fill(d, d+MAX, -1);
    d[N] = 0;
    que.push(make_pair(0, N));

    int near_cost[3] = {1, 1, 0};
    int near_node[3];
    while (!que.empty()) {
        int top_node = que.top().second; int top_cost = -que.top().first;
        que.pop();

        if (d[top_node] < top_cost) continue;
        
        near_node[0] = top_node-1; near_node[1] = top_node+1; near_node[2] = top_node*2; 
        
        for (int i = 0; i < 3; i++) {
            if (isRange(near_node[i])) {
                if (d[near_node[i]] > top_cost + near_cost[i] || d[near_node[i]] == -1) {
                    d[near_node[i]] = top_cost+near_cost[i];
                    que.push(make_pair(-d[near_node[i]], near_node[i]));
                }
            }
        }
    }
}

int main() {
    cin >> N >> K;

    dijk();
    cout << d[K];

    return 0;
}