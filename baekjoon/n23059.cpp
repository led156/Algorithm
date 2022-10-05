#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;

int N;
unordered_map<string, int> sTOi; //kv
unordered_map<int, string> iTOs; // vk
vector<string> ans[400000];

int indeg[400000];
vector<int> order[400000];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    string A, B;
    int idx = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A >> B;
        if (sTOi.find(A) == sTOi.end()) {
            sTOi.insert(make_pair(A, idx));
            iTOs.insert(make_pair(idx++, A));
        }
        if (sTOi.find(B) == sTOi.end()) {
            sTOi.insert(make_pair(B, idx));
            iTOs.insert(make_pair(idx++, B));
        }
        int a = sTOi[A]; int b = sTOi[B];
        ++indeg[b];
        order[a].push_back(b);
    }

    
    queue<pair<int, int> > que;
    for (int i = 0; i < idx; ++i) {
        if (indeg[i] == 0) {
            que.push(make_pair(i, 0));
            ans[0].push_back(iTOs[i]);
        }
    }

    for (int i = 0; i < idx; ++i) {
        if (que.empty()) {
            cout << "-1";
            return 0;
        }

        int top_idx = que.front().first;
        int cnt = que.front().second;
        que.pop();

        for (int i = 0; i < order[top_idx].size(); ++i) {
            int nxt_idx = order[top_idx][i];

            if (--indeg[nxt_idx] == 0) {
                que.push(make_pair(nxt_idx, cnt+1));
                ans[cnt+1].push_back(iTOs[nxt_idx]);
            }
        }
    }

    for (int i = 0; ; i++) {
        if (!ans[i].size()) return 0;
 
        sort(ans[i].begin(), ans[i].end());
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << '\n';
        }
    }

    return 0;
}