#include <stdio.h>

int min(int a, int b) {
    if (a > b) return b;
    return a;
}

int main() {
    /* INPUT1 */
    int N;
    scanf("%d", &N);
    int memo[N][3];
    int info[N][3];

    /* INPUT2 */
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &info[i][0], &info[i][1], &info[i][2]);
    }

    memo[0][0] = info[0][0];
    memo[0][1] = info[0][1];
    memo[0][2] = info[0][2];

    for (int i = 1; i < N; i++) {
        memo[i][0] = min(memo[i-1][1] + info[i][0], memo[i-1][2] + info[i][0]);
        memo[i][1] = min(memo[i-1][0] + info[i][1], memo[i-1][2] + info[i][1]);
        memo[i][2] = min(memo[i-1][0] + info[i][2], memo[i-1][1] + info[i][2]);
    }

    printf("%d", min(memo[N-1][2], min(memo[N-1][0], memo[N-1][1])));

    return 0;
}