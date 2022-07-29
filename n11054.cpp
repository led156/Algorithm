#include <iostream>
using namespace std;

int N, ans;
int A[1002];
int memo[1002][2];


int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d",&A[i]);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < i; j++) {
            if (A[i]>A[j]) {
                memo[i][0] = max(memo[i][0], memo[j][0]+1);
            }
        }
        for (int j = N+1; j > i; j--) {
            if (A[i]>A[j]) {
                memo[i][1] = max(memo[i][1], memo[j][1]+1);
            }
        }
    }

    for (int i = N; i > 0; i--) {
        for (int j = N; j > i; j--) {
            if (A[i]>A[j]) {
                memo[i][1] = max(memo[i][1], memo[j][1]+1);
            }
        }
        //printf("%d : %d + %d\n", i, memo[i][0], memo[i][1]);
        ans = max(ans, memo[i][0]+memo[i][1]);
    }

    cout << ans-1;
    return 0;
}