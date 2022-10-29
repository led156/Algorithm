#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;
vector<int> smaller_than[501], bigger_than[501];
bool visited[501];
int cnt = 0, ans = 0;

void dfs(vector<int> arr[], int cur) {
    visited[cur] = true;

    for (int i = 0; i < arr[cur].size(); ++i) {
        int nxt = arr[cur][i];

        if (visited[nxt]) continue;

        ++cnt;
        dfs(arr, nxt);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    
    int a, b;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b; // a -> b
        smaller_than[b].push_back(a);
        bigger_than[a].push_back(b);
    }

    for (int i = 1; i <= N; ++i) {
        cnt = 0;

        memset(visited, false, sizeof(visited));
        dfs(smaller_than, i);

        memset(visited, false, sizeof(visited));
        dfs(bigger_than, i);

        if (cnt == N-1) ++ans;
    }

    cout << ans;

    return 0;
}