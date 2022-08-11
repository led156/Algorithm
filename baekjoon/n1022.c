#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int max(int a, int b) {
    a = abs(a); b = abs(b);
    if(a > b) return a;
    return b;
}

int main() {
    int r1, r2, c1, c2;
    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);

    int r = r2-r1+1;
    int c = c2-c1+1;
    
    int arr[r][c];
    
    int value;
    int cnt = -1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int x, y, m, n; // m은 항상 양수
            x = r1 + i;
            y = c1 + j;
            m = max(x, y);
            n = 2*m + 1;

            if (abs(x) == m) {
                if (x < 0) {
                    value = (n-2)*(n-2) + n - 1 + m - y;
                    //printf("[%d, %d] : %d (case1 : %d, %d)\n", i, j, value, x, y);
                }
                else {
                    value = n*n - m + y;
                    //printf("[%d, %d] : %d (case2 : %d, %d)\n", i, j, value, x, y);
                }
            }
            else {
                if (y > 0) {
                    value = (n-2)*(n-2) + m - x;
                    //printf("[%d, %d] : %d (case3 : %d, %d)\n", i, j, value, x, y);
                }
                else {
                    value = (n-1)*(n-1) + 1 + m + x;
                    //printf("[%d, %d] : %d (case4 : %d, %d)\n", i, j, value, x, y);
                }
            }

            if (value > cnt) cnt = value;
            arr[i][j] = value;
        }
    }

    int cntdigit = floor(log10(cnt)+1);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            value = arr[i][j];
            if (value < cnt) {
                int digit = (int)(log10(value)+1);
                digit = cntdigit - digit;
                for (int k = 0; k < digit; k++) printf(" ");
            }
            printf("%d ", value);
        }
        printf("\n");
    }

    return 0;
}