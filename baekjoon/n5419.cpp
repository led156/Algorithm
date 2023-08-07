#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
#define MAX_N 75001

int T, n, x, y, N;
vector<pair<int, int>> island;
map<int, int> y_mapping;
ll tree[MAX_N*4], ans;

void init_() {
    island.clear();
    y_mapping.clear();
    ans = 0;
    fill(&tree[0], &tree[MAX_N*4], 0);
}

void update(int cur_node, int start, int end, int target_node) {
    if (start > target_node || end < target_node) return ;
    
    tree[cur_node] += 1;

    if (start != end) {
        update(cur_node*2, start, (start+end)/2, target_node);
        update(cur_node*2+1, (start+end)/2+1, end, target_node);
    }
}

ll search(int cur_node, int start, int end, int target_start, int target_end) {
    if (target_end < start || end < target_start) return 0;
    if (target_start <= start && end <= target_end) return tree[cur_node];
    return search(cur_node*2, start, (start+end)/2, target_start, target_end) + search(cur_node*2+1, (start+end)/2+1, end, target_start, target_end);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        init_();
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> x >> y;
            island.push_back({x, -y});
            y_mapping.insert({-y, 0});
        }
        // y 매핑
        y = 1;
        for (pair<int, int> ym : y_mapping) {
            y_mapping[ym.first] = y++;
        }
        // for (int i = 0; i < n; ++i) {
        //     // cout << "\n(" << island[i].first << "," << island[i].second << ")";
        //     island[i].second = y_mapping[island[i].second];
        // }
        N = y_mapping.size();
        // 정렬
        sort(island.begin(), island.end());
        // 순서대로 서치 & 업데이트
        for (pair<int, int> xy : island) {
            y = y_mapping[xy.second];
            ans += search(1, 1, N, 1, y);
            update(1, 1, N, y);
        }

        cout << ans << '\n';
    }


    return 0;
}