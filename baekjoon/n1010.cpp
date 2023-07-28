#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_NUM 31

long long comb[MAX_NUM][MAX_NUM];
int T, N, M;

void solCombination() {
    for (int i = 0; i < MAX_NUM; ++i) {
        comb[i][0] = 1;
    }

    for (int i = 1; i < MAX_NUM; ++i) {
        for (int j = 1; j <= i; ++j) {
            comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    solCombination();

    while (T--) {
        cin >> N >> M;
        cout << comb[M][N] << '\n';
    }

    return 0;
}