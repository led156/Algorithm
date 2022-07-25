#include <iostream>
#include <cstring>
using namespace std;

int N, M;
char arr[3072][6143];

void draw(int x, int y) {
    arr[x][y] = '*'; arr[x+2][y] = '*';
    arr[x+1][y-1] = '*'; arr[x+1][y+1] = '*';
    for (int i = 1; i < 3; i++) {
        arr[x+2][y+i] = '*'; arr[x+2][y-i] = '*';
    }
}

void tri(int h, int x, int y) {
    if (h == 3) {
        return draw(x, y);
    }
    tri(h/2, x, y);
    tri(h/2, x+(h/2), y-(h/2));
    tri(h/2, x+(h/2), y+(h/2));
}

int main() {
    scanf("%d", &N);
    memset(&arr[0][0], ' ', sizeof(arr));

    tri(N, 0, N-1);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2*N-1; j++) {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}