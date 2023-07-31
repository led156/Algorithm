#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX_N 501

int N, prev_N;
int times[MAX_N];
int dp[MAX_N];
int in_degree[MAX_N];
vector<vector<int>> graph(MAX_N);
queue<int> que; // node


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> times[i] >> prev_N;
        while (prev_N != -1) {
            ++in_degree[i];
            graph[prev_N].push_back(i);
            cin >> prev_N;
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (in_degree[i]==0) {
            que.push(i);
            dp[i] = times[i];
        }
    }

    while (!que.empty()) {
        int q = que.front();
        que.pop();

        for (int i = 0; i < graph[q].size(); ++i) {
            int nxt_q = graph[q][i];
            dp[nxt_q] = max(dp[nxt_q], times[nxt_q] + dp[q]);
            if (--in_degree[nxt_q] == 0) {
                que.push(nxt_q);
            }
        }
    }

    for (int i = 1; i <= N; ++i) {
        cout << dp[i] << '\n';
    }

    return 0;
}