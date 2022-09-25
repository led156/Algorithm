#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N, INF = 987654321;
int W[16][16];
int dp[16][1<<16];

int tsp(int cur, int visited) {
    if (visited == (1<<N)-1) {
        if (W[cur][0] == 0) return INF;
        else return W[cur][0];
    }

    if (dp[cur][visited] != -1) return dp[cur][visited];


    dp[cur][visited] = INF;
    for (int i = 0; i < N; ++i) {
        if (visited & (1<<i) || W[cur][i] == 0) continue;

        int nxt = visited | (1<<i);
        dp[cur][visited] = min(dp[cur][visited], tsp(i, nxt) + W[cur][i]);
    }

    return dp[cur][visited];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> W[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    cout << tsp(0, 1);

    return 0;
}