#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MN 123456*2

bool notPrimes[MN+1];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    notPrimes[1] = true;

    for (int i = 2; i*i < MN; ++i) {
        if (!notPrimes[i]) {
            for (int j = i*i; j <= MN; j += i) {
                notPrimes[j] = true;
            }
        }
    }


    while ((cin >> n) && n != 0) {
        int ans = 0;
        for (int i = n+1; i <= 2*n; ++i) {
            if (!notPrimes[i]) {
                ++ans;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}