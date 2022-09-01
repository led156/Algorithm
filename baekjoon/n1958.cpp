#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int dp[101][101][101];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            for (int k = 1; k <= s3.size(); k++) {
                dp[i][j][k] = max(max(max(dp[i-1][j][k], dp[i][j-1][k]), dp[i][j][k-1]), dp[i-1][j-1][k-1]+(s1[i-1]==s2[j-1]&&s2[j-1]==s3[k-1]));
            }
        }
    }

    cout << dp[s1.size()][s2.size()][s3.size()];
    return 0;
}