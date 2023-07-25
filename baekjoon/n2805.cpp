#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, n;
vector<long long> trees;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        cin >> n;
        trees.push_back(n);
    }

    sort(trees.begin(), trees.end());

    long long left = 1, right = trees[trees.size()-1];
    while (left < right) {
        long long mid = (left+right)/2;
        long long cnt = 0;

        for (int i = 0; i < trees.size(); ++i) {
            if (trees[i] > mid) {
                cnt += (trees[i] - mid);
            }
        }

        if (cnt < M) {
            right = mid;
        }
        else {
            left = mid+1;
        }
    }

    cout << right-1;

    return 0;
}