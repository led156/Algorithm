#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, maxx, ans = 0;
int arr[500][500];
int memo[500][500];
vector<int> list;

void save() {
    int ans = 0;
    for (int i = 0; i < list.size(); i++) {
        ans += list[i];
    }
    maxx = (ans>maxx) ? ans : maxx;
}

void findat(int x, int y) {
    if (x+1==n) {
        return save();
    }
    for (int i = 0; i < 2; i++) {
        list.push_back(arr[x+1][y+i]);
        findat(x+1, y+i);
        list.pop_back();
    }
}

void dfs() {
    list.push_back(arr[0][0]);
    findat(0, 0);
    cout << maxx;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> arr[i][j];
        }
    }

    //bfs();

    memo[0][0] = arr[0][0];

    memo[1][0] = memo[0][0] + arr[1][0];
    memo[1][1] = memo[0][0] + arr[1][1];
    
    for (int i = 2; i < n; i++) {
        memo[i][0] = memo[i-1][0] + arr[i][0];
        for (int j = 1; j <= i; j++) {
            memo[i][j] = max(memo[i-1][j] + arr[i][j], memo[i-1][j-1] + arr[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        ans = max(ans, memo[n-1][i]);
    }

    cout << ans;

    return 0;
}