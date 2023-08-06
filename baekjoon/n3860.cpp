#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_WH 31
#define INF 987654321

struct hole {
    hole(int src_x, int src_y, int dist_x, int dist_y, int cost) : src_x(src_x), src_y(src_y), dist_x(dist_x), dist_y(dist_y), cost(cost) {}
    int src_x, src_y, dist_x, dist_y, cost;
};

int W, H, G, X, Y, E, X2, Y2, T, ans;
int off_set[2][4] = {{-1, 0, 1, 0}, {0, 1, 0, -1}};
int is_rip[MAX_WH][MAX_WH], dist[MAX_WH][MAX_WH];
vector<hole> edges;


void init_() {
    fill(&dist[0][0], &dist[W-1][H], INF);
    // fill(dist, dist+sizeof(dist), INF);
    // memset(dist, INF, sizeof(dist));
    memset(is_rip, 0, sizeof(is_rip));
    edges.clear();
    ans = 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> W >> H;
    while (H > 0 && W > 0) {
        init_();
        cin >> G;
        for (int i = 0; i < G; ++i) {
            cin >> X >> Y;
            is_rip[X][Y] = 1;
        }
        cin >> E;
        for (int i = 0; i < E; ++i) {
            cin >> X >> Y >> X2 >> Y2 >> T;
            edges.push_back(hole(X, Y, X2, Y2, T));
            is_rip[X][Y] = 2;
        }

        // 간선 만들기
        for (int i = 0; i < W; ++i) {
            for (int j = 0; j < H; ++j) {
                if ((i == W-1 && j == H-1) || is_rip[i][j] > 0) continue;
                for (int dir = 0; dir < 4; ++dir) {
                    int ni = i + off_set[0][dir];
                    int nj = j + off_set[1][dir];
                    if (ni < 0 || ni >= W || nj < 0 || nj >= H || is_rip[ni][nj] == 1) continue;
                    edges.push_back(hole(i, j, ni, nj, 1));
                }
            }
        }
        // cout << "*"<<edges.size();
        
        // 벨만포드
        dist[0][0] = 0;
        for (int i = 0; i < W*H; ++i) {
            for (hole edge : edges) {
                if (dist[edge.src_x][edge.src_y] == INF) continue;

                if (dist[edge.dist_x][edge.dist_y] > edge.cost + dist[edge.src_x][edge.src_y]) {
                    dist[edge.dist_x][edge.dist_y] = edge.cost + dist[edge.src_x][edge.src_y];

                    if (i >= W*H-1) ans = -1;
                }
            }
        }

        if (ans == -1) cout << "Never\n";
        else if (dist[W-1][H-1] < INF) cout << dist[W-1][H-1] << '\n';
        else cout << "Impossible\n";

        cin >> W >> H;
    }


    return 0;
}