#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, ans = 0;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    while (N > 0) {
        if (N%5 == 0) {
            ans += N/5;
            N = 0;

            continue;
        }

        N -= 3;
        ans += 1;
    }

    if (N < 0) cout << -1;
    else cout << ans;

    return 0;
}