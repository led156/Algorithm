#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 1001

int N, K;
int isNotPrime[MAX_N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;

    for (int i = 2; i <= N; ++i) {
        if (!isNotPrime[i]) {
            for (int j = i; j <= N; j+=i) { // (int j = 1; i * j <= n; ++j)
                if (!isNotPrime[j]) {
                    isNotPrime[j] = true;
                    if (--K<=0) {
                        cout << j;
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}