#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 987654321

int min_cnt = INF;
long long A, B;

void dfs(long long num, int cnt) {
    if (num > B) return ;
    if (num == B) {
        min_cnt = min(min_cnt, cnt);
        return ;
    }

    dfs(num*2, cnt+1);

    dfs(num*10+1, cnt+1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> A >> B;
    dfs(A, 0);

    if (min_cnt == INF) cout << -1;
    else cout << min_cnt+1;

    return 0;
}