#include <iostream>
using namespace std;

int N, M, n_know;
int invite[50][51];
int know[51];


void theyTrue(int n) {
    for (int i = 0; i <= N; i++) {
        if (invite[n][i] && !know[i]) {
            know[i] = 1;
            n_know++;
        }
    }
}

int main() {
    cin >> N >> M;
    cin >> n_know;
    int temp;
    for (int i = 0; i < n_know; i++) {
        cin >> temp;
        know[temp] = 1;
    }
    for (int i = 0; i < M; i++) {
        cin >> invite[i][0];
        for (int j = 0; j < invite[i][0]; j++) {
            cin >> temp;
            invite[i][temp] = 1;
        }
    }
    
    do {
        temp = n_know;
        for (int i = 0; i < M; i++) {
            for (int j = 1; j <= N; j++) {
                if (invite[i][j] && know[j]) {
                    theyTrue(i);
                    break;
                }
            }
        }
    }   while (temp != n_know);

    int cntt = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 1; j <= N; j++) {
            if (invite[i][j] && know[j]) {
                break;
            }
            if (j==N) cntt++;
        }
    }

    cout << cntt;
    return 0;
}