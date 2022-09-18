#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[5001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    

    dp[3] = 1;
    dp[5] = 1;
    for (int i = 6; i <= N; ++i) {
        if (dp[i-3] > 0) dp[i] = dp[i-3]+1;
        if (dp[i-5] > 0) {
            if (dp[i] > 0) dp[i] = min(dp[i], dp[i-5]+1); 
            else dp[i] = dp[i-5]+1;
        }
    }

    if (dp[N] > 0) cout << dp[N];
    else cout << -1;

    return 0;
}