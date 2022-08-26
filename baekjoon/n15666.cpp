#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> list;
int ans[8];
int used[8];


void dfs(int size, int pre_num) {
    if (size >= M) {
        for (int i = 0; i < M; i++)
            cout << ans[i] << " ";
        cout << "\n";
        return ;
    }

    int printed = -1;

    for (int i = 0; i < N; i++) {
        if (printed != list[i] && pre_num <= list[i]) {
            used[i] = 1;
            ans[size] = list[i];
            printed = list[i];
            dfs(size+1, list[i]);
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
    dfs(0, -1);
    return 0;
}