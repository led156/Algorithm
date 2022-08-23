#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define INF 987654321;

int N;
vector<pair<int, int> > point;
vector<int> start;
int sum_x, sum_y;
double ans;

double cal() {
    int x = 0, y = 0;
    double start_x = sum_x, start_y = sum_y;
    for (int i = 0; i < start.size(); i++) {
        start_x -= 2.0*point[start[i]].first;
        start_y -= 2.0*point[start[i]].second;
    }
    return sqrt((start_x*start_x) + (start_y*start_y));
}


void dfs(int cnt, int points) {
    if (cnt >= N/2) {
        ans = min(ans, cal());
        return ;
    }
    if (points >= N) {
        return ;
    }

    start.push_back(points);
    dfs(cnt+1, points+1);
    start.pop_back();

    dfs(cnt, points+1);
}


int main() {
    int T;
    cin >> T;

    cout << fixed;
    cout.precision(12);

    while (T--) {
        point.clear();
        ans = INF;
        sum_x = 0, sum_y = 0;

        cin >> N;
        
        int x, y;
        for (int i = 0; i < N; i++) {
            cin >> x >> y;
            point.push_back(make_pair(x, y));
            sum_x += x;
            sum_y += y;
        }

        dfs(0, 0);

        cout << ans << "\n";
    }

    return 0;
}
