#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_LEN 10001

int N, M, n, ans = 0;
int nums[MAX_LEN];
int summation[MAX_LEN];


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        cin >> n;
        nums[i] = n;
        summation[i+1] = summation[i] + n;
    }
    // summation[N] = summation[N-1];

    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j < i; ++j) {
            // cout << "sum " << j << " " << i << " =" << summation[i] - summation[j] << '\n';
            if (summation[i] - summation[j] == M) ++ans;
        }
    }

    cout << ans;

    return 0;
}