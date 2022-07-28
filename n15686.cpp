#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M, ans = 987654321;
int city[50][50];
int save[100][13];
vector<pair<int, int> > homelist;
vector<pair<int, int> > chcklist;
vector<int> com;

void cals() {
    int dist = 0;
    for (int i = 0; i < homelist.size(); i++) {
        int minn = 201;
        for (int j = 0; j < M; j++) {
            //printf("%d(%d,%d)\n", save[i][com[j]], i, com[j]);
            minn = (save[i][com[j]] < minn) ? save[i][com[j]] : minn;
        }
        //cout << minn << " " << dist << endl;
        dist += minn;
    }
    ans = ans > dist ? dist : ans;
}


void combination(int n, int k) {
    if (n == chcklist.size()) {
        if (k == M) {
            cals();
        }
        return ;
    }
    // 뽑
    com.push_back(n);
    combination(n+1, k+1);
    com.pop_back();

    // 안뽑
    combination(n+1, k);
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> city[i][j];
            if (city[i][j]==1) { // home
                homelist.push_back(make_pair(i, j));
            }
            else if (city[i][j]==2) {// chck
                chcklist.push_back(make_pair(i, j));
            }
        }
    }

    for (int i = 0; i < homelist.size(); i++) {
        for (int j = 0; j < chcklist.size(); j++) {
            int dist = abs(homelist[i].first - chcklist[j].first) + abs(homelist[i].second - chcklist[j].second);
            //printf("|%d-%d|+|%d-%d|=%d", homelist[i].first, chcklist[i].first, homelist[i].second, chcklist[i].second, dist);
            save[i][j] = dist;
        }
    }

    combination(0, 0);

    cout << ans;

    return 0;
}