#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M;
int ball_pos[4];
int table[4];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    /* INPUT */
    cin >> M;
    for (int i = 1; i < 4; ++i) {
        ball_pos[i] = i;
        table[i] = i;
    }

    /* SOLUTION */
    int a, b;
    while (M--) {
        cin >> a >> b;
        int temp = ball_pos[a];
        ball_pos[a] = ball_pos[b];
        ball_pos[b] = temp;

        table[ball_pos[a]] = a;
        table[ball_pos[b]] = b;
    }

    cout << table[1];

    return 0;
}