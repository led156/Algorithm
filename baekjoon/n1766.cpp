#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int arrow[32001]; // 들어오는 화살표의 수.
vector<int> priority[32001]; // [전위] = {후위, ...}
priority_queue<int> problems;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    int a, b;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b;
        priority[a].push_back(b);
        ++arrow[b];
    }

    for (int i = 1; i <= N; ++i) {
        if (arrow[i] == 0) {
            problems.push(-i);
        }
    }

    // queue...
    for (int j = 0; j < N; ++j) {
        // top을 꺼냄.
        int top_node = -problems.top();
        problems.pop();

        // top을 푼다. -> top을 우선으로 하는 문제들의 화살표가 풀림
        cout << top_node << " ";
        // 따라서, 해당 문제들의 거시기가 줄어듦.
        for (int i = 0; i < priority[top_node].size(); ++i) {
            if (--arrow[priority[top_node][i]] == 0) {
                problems.push(-priority[top_node][i]);
            } 
        }
    }

    return 0;
}