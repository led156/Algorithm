#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr(40);

void comb(int idx, int sum, int bound, vector<int>* vec) {
    if (idx >= bound) {
        vec->push_back(sum);
        return ;
    }
    comb(idx+1, sum+arr[idx], bound, vec);
    comb(idx+1, sum, bound, vec);
}

int main() {
    int N, S;
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<int> left;
    comb(0, 0, N/2, &left);
    sort(left.begin(), left.end());
    vector<int> right;
    comb(N/2, 0, N, &right);
    sort(right.begin(), right.end());

    long long ans = 0;
    for (int i = 0; i < left.size(); i++) {
        int num = S - left[i];
        ans += ((upper_bound(right.begin(), right.end(), num) - lower_bound(right.begin(), right.end(), num)));
    }

    if (S == 0) cout << ans-1;
    else cout << ans;

    return 0;
}