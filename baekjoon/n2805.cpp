#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long N, M;
    cin >> N >> M;
    long long low = 0, high = 0;
    vector<long long> tree_height(N);
    for (int i = 0; i < N; i++) {
        cin >> tree_height[i];
        high = max(high, tree_height[i]);
    }
    sort(tree_height.begin(), tree_height.end());

    while (low < high) {
        long long mid = (low+high)/2;
        long long sum = 0;
        for (int i = 0; i < N; i++) {
            if (tree_height[i] > mid) sum += tree_height[i] - mid; 
        }

        if (sum < M) {
            high = mid;
        }
        else {
            low = mid+1;
        }
    }
    cout << low-1;

    return 0;
}