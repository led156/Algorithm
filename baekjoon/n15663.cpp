#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> list;
int ans[8];
int used[8];

// (1) 중복되는 답을 출력해서는 안 된다. -> 연속적으로 같은 수 선택X
// (2) 사전 순 증가 -> sort ...

void dfs(int size) {
    if (size >= M) {
        for (int i = 0; i < M; i++)
            cout << ans[i] << " ";
        cout << "\n";
        return ;
    }

    int printed = -1;

    for (int i = 0; i < N; i++) {
        if (!used[i] && printed != list[i]) {
            used[i] = 1;
            ans[size] = list[i];
            printed = list[i];
            dfs(size+1);
            used[i] = 0;
        }
    }

}

int main() {
    cin >> N >> M;
    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        list.push_back(temp);
    }
    sort(list.begin(), list.end());
    dfs(0);
    return 0;
}