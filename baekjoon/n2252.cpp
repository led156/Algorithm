#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX_N 32001

int N, M, A, B;
vector<vector<int>> graph(MAX_N);
int indegree[MAX_N];
queue<int> que;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        cin >> A >> B; // A -> B
        graph[A].push_back(B);
        ++indegree[B];
    }

    /* SOLUTION */
    for (int i = 1; i <= N; ++i) {
        if (indegree[i]==0) que.push(i);
    }

    while (!que.empty()) {
        A = que.front();
        que.pop();
        cout << A << " ";

        for (int i = 0; i < graph[A].size(); ++i) {
            B = graph[A][i];
            if (--indegree[B]==0) {
                que.push(B);
            }
        }
    }

    return 0;
}