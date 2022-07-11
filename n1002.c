#include <stdio.h>

int main() {
    int x1, x2, y1, y2, r1, r2;
    
    /*** 입력 ***/
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        int d = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);

        int rm = (r1-r2)*(r1-r2);
        int rp = (r1+r2)*(r1+r2);
        
        /* 같은 위치에 */
        if (d == 0 && rm == 0) {
            printf("-1\n");
        }
        /* 두 점에서 만남 */
        else if (rm < d && d < rp) {
            printf("2\n");
        }
        /* 한 점에서 만남 */
        else if (rm == d || rp == d) {
            printf("1\n");
        }
        /* 만나지 않음 */
        else {
            printf("0\n");
        }
    }

    return 0;
}