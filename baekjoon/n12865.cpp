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

    int dp[N+1][100001];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            weight = list[i].first;
            value = list[i].second;
            if (j - weight >= 0) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight] + value);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[N][K];
    return 0;
}