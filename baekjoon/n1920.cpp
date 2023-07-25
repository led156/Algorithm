#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, k;
vector<int> A;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> k;
        A.push_back(k);
    }

    sort(A.begin(), A.end());

    cin >> M;

    for (int i = 0; i < M; ++i) {
        cin >> k;
        if (upper_bound(A.begin(), A.end(), k) - lower_bound(A.begin(), A.end(), k)) cout << "1\n";
        else cout << "0\n";
    }


    return 0;
}