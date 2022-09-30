#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    vector<int> A(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    cin >> M;
    int num;
    for (int i = 0; i < M; ++i) {
        cin >> num;
        int cnt = upper_bound(A.begin(), A.end(), num) - lower_bound(A.begin(), A.end(), num);

        if (cnt > 0) cout << 1 << '\n';
        else cout << 0 << '\n';
    }

    return 0;
}