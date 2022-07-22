#include <iostream>
#include <algorithm>
using namespace std;

int N;
int memo[1000001];

int main() {
    cin >> N;
    
    memo[1] = 0;

    for (int i = 2; i <= N; i++) {
        memo[i] = 1 + memo[i-1];
        if (i%3 == 0) {
            memo[i] = min(memo[i], 1 + memo[i/3]);
        }
        if (i%2 == 0) {
            memo[i] = min(memo[i], 1 + memo[i/2]);
        }
    }

    cout << memo[N];
    return 0;
}