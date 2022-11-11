#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<pair<int, int> > list(N+1);
    int weight, value, sum = 0;
    for (int i = 1; i <= N; i++) {
        cin >> weight >> value;
        list[i] = make_pair(weight, value);
    }

    int dp[N+1][100001]; // dp[이전 아이템][가방에 남은 무게] : 일때의 가치를 값으로 가짐.
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            weight = list[i].first;
            value = list[i].second;
            if (j - weight >= 0) { // 가방에 넣을 수 있다면.
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight] + value);
                // dp[현재 아이템][현재 가방에 남은 무게] = dp[이전 아이템][현재 가방에 남은 무게], dp[이전 아이템][현재 가방에 남은 무게 - 현재 아이템의 무게]+현재 아이템의 가치
                // -> i번째 물건을 포함, i번째 물건을 포함하지않음.
            }
            else dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[N][K];
    return 0;
}