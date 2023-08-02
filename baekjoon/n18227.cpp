#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 200001
typedef long long ll;

int N, C, x, y, Q, q1, q2, k;
vector<vector<int>> edges(MAX_N);
int node[MAX_N], node_range[MAX_N][2];
int depth[MAX_N];
ll water[4*MAX_N];


void dfs(int cur) {
	node[cur] = node_range[cur][0] = ++k;

	for (int nxt : edges[cur]) {
		if (depth[nxt]>0) continue;
		depth[nxt] = depth[cur] + 1;
		dfs(nxt);
	}

	node_range[cur][1] = k;
}

ll update(int cur_node, int left, int right, int target_node) {
	if (target_node < left || right < target_node) return water[cur_node];
	if (left == right) return ++water[cur_node];
	return water[cur_node] = update(cur_node * 2, left, (left + right) / 2, target_node) + update(cur_node * 2 + 1, (left + right) / 2+1, right, target_node);
}

ll search(int cur_node, int left, int right, int target_left, int target_right) {
	if (target_right < left || right < target_left) return 0;
	if (target_left <= left && right <= target_right) return water[cur_node];
	return search(cur_node * 2, left, (left + right) / 2, target_left, target_right) + search(cur_node * 2 + 1, (left + right) / 2+1, right, target_left, target_right);
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> C;
	for (int i = 0; i < N - 1; ++i) {
		cin >> x >> y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	
	depth[C] = 1;
	dfs(C);

	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		cin >> q1 >> q2;
		if (q1 == 1) { // 물 채우기
			update(1, 1, N, node[q2]);
		}
		else { // 출력
			cout << search(1, 1, N, node_range[q2][0], node_range[q2][1])*depth[q2] << '\n';
		}
	}


	return 0;
}