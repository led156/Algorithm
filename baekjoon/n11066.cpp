#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int T, K;
int sumCost[501], cost[501], dp[501][501];

int main() {
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> K;

        for (int j = 1; j <= K; j++) {
            cin >> cost[j];
            sumCost[j] = sumCost[j-1] + cost[j];
        }

        for (int d = 1; d <= K; d++) {
            for (int a = 1; a <= K - d; a++) {
                dp[a][a + d] = INF;
                for (int k = a; k < a + d; k++) {
                    dp[a][a + d] = min(dp[a][a + d], dp[a][k] + dp[k + 1][a + d] + sumCost[a + d] - sumCost[a - 1]);
                }
            }
        }

        cout << dp[1][K] << endl;
        
    }

    return 0;
}