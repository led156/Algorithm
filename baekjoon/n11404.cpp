#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_n 101

int n, m, a, b, c;
int dist[MAX_n][MAX_n];



int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	memset(dist, -1, sizeof(dist));
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		if (dist[a][b] == -1) dist[a][b] = c;
		else dist[a][b] = min(dist[a][b], c);
	}

	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (i == j || i == k || j == k || dist[i][k] == -1 || dist[k][j] == -1) continue;

				if (dist[i][j] != -1) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				else dist[i][j] = dist[i][k] + dist[k][j];
				
			}
		}
	}


	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (dist[i][j] == -1) cout << "0 ";
			else cout << dist[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}