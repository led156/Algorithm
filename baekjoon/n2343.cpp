#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    
    long long low = 0, high = 0;
    vector<int> video(N);
    for (int i = 0; i < N; i++) {
        cin >> video[i];
        high += video[i];
        low = max(low, (long long)video[i]);
    }

    ++high;
    while (low < high) {
        long long mid = (low+high)/2;
        int cnt = 1;
        long long remain = mid;
        for (int i = 0; i < N; i++) {
            if (remain >= video[i]) {
                remain -= video[i];
            }
            else {
                ++cnt;
                remain = mid - video[i];
            }
        }

        if (cnt <= M) {
            high = mid; // 블루레이 용량을 줄이고 싶을 때 -> 개수가 늘어남
        }
        else {
            low = mid+1;
        }
    }

    cout << low;

    return 0;
}