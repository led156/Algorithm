#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int dp[101];
vector<pair<int, int> > vec;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    int a, b;
    vec.push_back(make_pair(0, 0));
    for (int i = 0; i < N; ++i) {
        cin >> a >> b;
        vec.push_back(make_pair(a, b));
    }

    sort(vec.begin(), vec.end());

    int max_ = 0;
    for (int i = 1; i <= N; ++i) {
        dp[i] = 1;
        for (int j = 1; j < i; ++j) {
            if (vec[i].second > vec[j].second) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        max_ = max(max_, dp[i]);
    }

    cout << N - max_;
    
    return 0;
}