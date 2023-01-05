#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<pair<int, int> > item(100002);
int dp[100002][102];

int ans = 0;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    /* INPUT */
    cin >> N >> K;
    
    for (int i = 1; i <= N; ++i) {
        cin >> item[i].first >> item[i].second;
    }

    /* SOLUTION */
    for (int i = 1; i <= N; ++i) {
        int w = item[i].first;
        int v = item[i].second;

        for (int j = 1; j <= K; ++j) {
            if (j-w >= 0) { // 담을 수 있다
                dp[j][i] = max(dp[j-w][i-1]+v, dp[j][i-1]);
            }
            else {
                dp[j][i] = dp[j][i-1];
            }
        }
    }

    cout << dp[K][N];

    return 0;
}