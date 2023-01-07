#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, ans = 0;
vector<pair<int, int> > list;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    /* INPUT */
    cin >> N;
    int a, b;
    while (N--) {
        cin >> a >> b;
        list.push_back(make_pair(a, b));
    }

    /* SOLUTION */
    sort(list.begin(), list.end());
    
    int start_time = -1, end_time = -1;
    int cur_start, cur_end;
    for (int i = 0; i < list.size(); ++i) {
        cur_start = list[i].first;
        cur_end = list[i].second;

        if (end_time > cur_start) {
            if (end_time > cur_end) {
                start_time = cur_start;
                end_time = cur_end;
            }
        }
        else {
            start_time = cur_start;
            end_time = cur_end;
            ++ans;
        }

        // cout << i << "(" << cur_start << "," << cur_end << ") " << ans << '\n';
    }

    cout << ans;

    return 0;
}