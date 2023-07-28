#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_NUM 11

int N, K;
int factorial[MAX_NUM];


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;

    factorial[0] = 1;
    factorial[1] = 1;
    for (int i = 2; i < MAX_NUM; ++i) {
        factorial[i] = factorial[i-1] * i;
    }

    cout << factorial[N] / factorial[K] / factorial[N-K];

    return 0;
}