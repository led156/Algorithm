#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, z = 0, v = 0, maxx = -1;
int arr[8][8];
int sim[8][8];
pair<int, int> zerospace[64];
pair<int, int> vispace[10];

int inRange(int x, int y) {
    return (x>=0 && x<N && y>=0 && y<M);
}

void spread(int x, int y) {
    if (inRange(x-1, y) && sim[x-1][y] == 0) { sim[x-1][y] = 2; spread(x-1, y); }
    if (inRange(x+1, y) && sim[x+1][y] == 0) { sim[x+1][y] = 2; spread(x+1, y); }
    if (inRange(x, y-1) && sim[x][y-1] == 0) { sim[x][y-1] = 2; spread(x, y-1); }
    if (inRange(x, y+1) && sim[x][y+1] == 0) { sim[x][y+1] = 2; spread(x, y+1); }
}

int simulation(pair<int, int> w1, pair<int, int> w2, pair<int, int> w3) {   // 남은 안전지대를 리턴.
    int sum = 0;
    copy(&arr[0][0], &arr[0][0]+64, &sim[0][0]);
    sim[w1.first][w1.second] = 1; sim[w2.first][w2.second] = 1; sim[w3.first][w3.second] = 1;
    for (int i = 0; i < v; i++) {   // 바이러스 확산
        int x = vispace[i].first; int y = vispace[i].second;
        spread(x, y);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            sum += (sim[i][j] == 0);
        }
    }
    return sum;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j]==0) {
                zerospace[z++] = make_pair(i, j);
            }
            else if (arr[i][j]==2) {
                vispace[v++] = make_pair(i, j);
            }
        }
    }

    for (int i = 0; i < z-2; i++) {
        for (int j = i+1; j < z-1; j++) {
            for (int k = j+1; k < z; k++) {
                maxx = max(maxx, simulation(zerospace[i], zerospace[j], zerospace[k]));
            }
        }
    }

    cout << maxx;
    return 0;
}