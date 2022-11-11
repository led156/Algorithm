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
            sumCost[j] = sumCost[j-1] + cost[j]; // j장까지의 cost 합
        }

        for (int d = 1; d <= K; d++) { // 시작-끝 장수의 차이
            for (int a = 1; a <= K - d; a++) { // 시작장수
                dp[a][a + d] = INF;
                for (int k = a; k < a + d; k++) { // 시작-끝장 사이의 mid
                    dp[a][a + d] = min(dp[a][a + d], dp[a][k] + dp[k + 1][a + d] + sumCost[a + d] - sumCost[a - 1]); // 비용 : 두 개의 파일을 합칠 때 필요한 비용(시간 등)이 두 파일 크기의 합
                }
            }
        }

        cout << dp[1][K] << endl;
        
    }

    return 0;
}