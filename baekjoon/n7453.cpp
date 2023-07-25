#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_LEN 4000

int n, a, b, c, d;
vector<int> A(MAX_LEN), B(MAX_LEN), C(MAX_LEN), D(MAX_LEN);
vector<long long> AB, CD;
long long ans = 0;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            AB.push_back(A[i]+B[j]);
            CD.push_back(C[i]+D[j]);
        }
    }

    sort(AB.begin(), AB.end());
    sort(CD.begin(), CD.end());

    for (int i = 0; i < AB.size(); ++i) {
        long long cnt = upper_bound(CD.begin(), CD.end(), -AB[i])-lower_bound(CD.begin(), CD.end(), -AB[i]);
        ans += cnt;
    }

    cout << ans;

    return 0;
}