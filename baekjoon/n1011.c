#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    int x, y;
    for (int i = 0; i < T; i++) {
        scanf("%d %d", &x, &y);
        long long int sum = 0;
        int d = y-x;
        int dx = 1;
        while (d > sum + 2*dx) {
            sum = sum + 2*dx;
            dx++;
        }
        if (sum + dx >= d) printf("%d\n", 2*dx - 1);
        else printf("%d\n", 2*dx);
    }

    return 0;
}