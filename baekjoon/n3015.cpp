#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int N;
stack<pair<int, int> > st; // {키, 같은 키를 가지고 있는 사람의 수}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    /* INPUT */
    cin >> N;

    /* SOLUTION */
    int height;
    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        cin >> height;

        // 앞 사람보다 키가 클 때
        while (!st.empty() && st.top().first < height) {
            ans += st.top().second;
            st.pop();
        }

        int cnt = 1;
        if (!st.empty()) {
            if (st.top().first == height) { // 앞 사람과 같은 키를 가질 때
                ans += st.top().second;
                cnt = st.top().second + 1;
                st.pop();

                if (!st.empty()) // 앞의 사람들 중 같은 키를 가진 사람을 제외하면, 본인보다 큰 키를 가진 사람이 남는다. : 그 사람도 볼 수 있음
                    ++ans;
            }
            else { // 앞 사람보다 키가 작을 때 : 앞 사람만 볼 수 있다.
                ++ans;
            }
        }

        st.push(make_pair(height, cnt));
    }

    cout << ans;

    return 0;
}