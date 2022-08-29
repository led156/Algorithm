#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;

    int low = 0, high = 0;
    vector<int> pay(N);
    for (int i = 0; i < N; i++) {
        cin >> pay[i];
        high = max(high, pay[i]);
    }
    ++high;
    
    int M;
    cin >> M;

    while (low < high)
    {
        int mid = (low+high)/2;
        int sum = 0;
        for (int i = 0; i < N; i++) {
            sum += min(mid, pay[i]);
        }

        if (sum > M) {
            high = mid;
        }
        else {
            low = mid+1;
        }
    }

    cout << low-1;
    
    return 0;
}