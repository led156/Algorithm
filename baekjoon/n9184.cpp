#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int a, b, c;
int dp[101][101][101];

int w(int a, int b, int c) {
    if (dp[a][b][c] != -1) return dp[a][b][c];

    if (a <= 50 || b <= 50 || c <= 50) return dp[a][b][c] = 1;

    if (a > 70 || b > 70 || c > 70) return dp[a][b][c] = w(70, 70, 70);

    if (a < b && b < c) return dp[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);

    return dp[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b >> c;
    memset(dp, -1, sizeof(dp));

    while (a != -1 || b != -1 || c != -1) {
        cout << "w(" << a << ", " << b << ", " << c << ") = ";
        cout << w(a+50, b+50, c+50) << '\n';
        cin >> a >> b >> c;
    }

    return 0;
}