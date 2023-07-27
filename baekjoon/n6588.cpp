#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_NUM 1000001

int n, low, high;
bool wrong = true;
bool isNotPrime[MAX_NUM];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    isNotPrime[1] = true;
    for (int i = 2; i*i < MAX_NUM; ++i) {
        if (!isNotPrime[i]) {
            for (int j = i*i; j < MAX_NUM; j+=i) isNotPrime[j] = true;
        }
    }

    while (true) {
        wrong = true;
        cin >> n;
        if (n==0) break;

        low = 3;
        high = n;

        while (low<=high) {
            if (isNotPrime[low]) {
                ++low;
                continue;
            }
            if (isNotPrime[high]) {
                --high;
                continue;
            }
            // cout << "[" << low << ", " << high <<  "] ";

            if (n > low+high) {
                ++low;
            }
            else if (n == low+high) {
                cout << n << " = " << low << " + " << high << '\n';
                wrong = false;
                break;
            }
            else {
                --high;
            }
        }

        if (wrong) cout << "Goldbach's conjecture is wrong.\n";
    }

    return 0;
}