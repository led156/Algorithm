#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_NUM 9

int N, M, n;
vector<int> num;
int ans[MAX_NUM];
bool used[MAX_NUM];

void bt(int idx) {
    if (idx > M) {
        for (int i = 1; i <= M; ++i) {
            cout << ans[i] << " ";
        }
        cout << '\n';
        return;
    }

    int printed = -1;

    for (int i = 0; i < num.size(); ++i) {
        if (!used[i] && printed != num[i]) {
            ans[idx] = num[i];
            used[i] = true;
            printed = num[i];
            bt(idx+1);
            used[i] = false;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> n;
        num.push_back(n);
    }
    sort(num.begin(), num.end());

    bt(1);

    return 0;
}