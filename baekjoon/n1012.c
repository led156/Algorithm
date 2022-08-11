#include <stdio.h>

int M, N;
int farm[50][50];
int visit[50][50];

int isRange(int x, int y) {
    if (x < 0 || y < 0 || x >= N || y >= M) return 0;
    return 1;
}

int hasChance(int x, int y) {
    return !visit[x][y] && farm[x][y];
}

void around(int x, int y) {
    visit[x][y] = 1;
    //printf("around (%d, %d) : hasChance is %d\n", x, y, hasChance(x,y));
    // 좌
    if (isRange(x, y-1) && hasChance(x, y-1)) around(x, y-1);
    // 우
    if (isRange(x, y+1) && hasChance(x, y+1)) around(x, y+1);
    // 상
    if (isRange(x-1, y) && hasChance(x-1, y)) around(x-1, y);
    // 하
    if (isRange(x+1, y) && hasChance(x+1, y)) around(x+1, y);
}


int main() {
    int T, K;
    scanf("%d", &T);

    int x, y;

    for (int i = 0; i < T; i++) {
        /* 초기화 */
        int ans = 0;
        for (int X = 0; X < 50; X++) {
            for (int Y = 0; Y < 50; Y++) {
                farm[X][Y] = 0;
                visit[X][Y] = 0;
            }
        }

        /* 각각 케이스의 해충 입력받기 */
        scanf("%d %d %d", &N, &M, &K);
        for (int k = 0; k < K; k++) {
            int pos1, pos2;
            scanf("%d %d", &pos2, &pos1);
            farm[pos2][pos1] = 1;
        }

        /* */
        for (int X = 0; X < N; X++) {
            for (int Y = 0; Y < M; Y++) {
                if (hasChance(X, Y)) {
                    ans++;
                    around(X, Y);
                }
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}