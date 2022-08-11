#include <iostream>
using namespace std;

int T, N;
int memo[41][2];

int main() {
    cin >> T;

    memo[0][0] = 1; memo[0][1] = 0;
    memo[1][0] = 0; memo[1][1] = 1;
    for (int i = 2; i < 41; i++) {
        memo[i][0] = memo[i-1][0] + memo[i-2][0];
        memo[i][1] = memo[i-1][1] + memo[i-2][1];
    }

    for (int i = 0; i < T; i++) {
        cin >> N;
        cout << memo[N][0] << " " << memo[N][1] << "\n";
    }

    return 0;
}