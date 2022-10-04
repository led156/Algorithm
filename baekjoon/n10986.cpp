#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
long long arr[1000001];
long long cnt[1001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
        arr[i] += arr[i-1];
        arr[i] %= M;
        ++cnt[arr[i]];
    }

    long long ans = cnt[0];
    for (int i = 0; i < M; ++i) {
        ans += cnt[i] * (cnt[i] - 1) / 2; // combination n_C_2 
    }

    cout << ans;

    return 0;
}