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

    /* 1. 왼쪽; 자신보다 더 작은 원소 -> 증가하는 부분수열 체크 */
    for (int i = 1; i <= N; i++) {
        memo[i][0] = 1;
        for (int j = 0; j < i; j++) {
            if (A[i]>A[j]) {
                memo[i][0] = max(memo[i][0], memo[j][0]+1);
            }
        }
    }

    /* 2. 오른쪽; 자신보다 더 작은 원소 -> 감소하는 부분수열 체크 */
    for (int i = N; i >= 1; i--) {
        memo[i][1] = 1;
        for (int j = N; j > i; j--) {
            if (A[i]>A[j]) {
                memo[i][1] = max(memo[i][1], memo[j][1]+1);
            }
        }

        /* 최대값(정답) 계산 */
        ans = max(ans, memo[i][0]+memo[i][1]);
    }


    cout << ans-1;
    return 0;
}