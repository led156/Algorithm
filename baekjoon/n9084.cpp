#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, M;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> T;

    while (T--) {
        /* INPUT */
        cin >> N;
        vector<int> coin(N);
        for (int i = 0; i < N; ++i) {
            cin >> coin[i]; // 오름차순.
        }
        cin >> M;

        /* SOLUTION */
        int dp[10001] = { 0 }; // dp[i]
        dp[0] = 1;

        for (int i = 0; i < N; ++i) {
            for (int j = coin[i]; j <= M; ++j) { // 어차피 coin[i] 값보다 작은 액수는 만들지 못하므로.. coin[i] 부터 시작
                dp[j] += dp[j-coin[i]]; // coin[i] 동전을 쓸 수 있을 때 j만큼의 액수를 가질 수 있는 방법의 수
            }
        }

        cout << dp[M] << '\n';
    }


    return 0;
}