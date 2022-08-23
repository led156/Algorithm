#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int X, Y, D, T;
    cin >> X >> Y >> D >> T;
    
    double dist = sqrt(X*X+Y*Y);
    int jump_max = dist / D;
    double remain_dist = dist - jump_max*D;

    // (1) 그냥 걷기.
    double ans = dist;

    if (jump_max == 0) { // 점프 한 번에 넘어버림. D >= dist
        // (1) 점프 - 걸어서 돌아오기
        ans = min(ans, T + (D - remain_dist));
        // (2) 점프 - 점프해서 돌아오기
        ans = min(ans, 2.0*T);
    }
    else {
        // (1) 점프 n번 - 걸어서 가기
        ans = min(ans, jump_max*T + remain_dist);
        // (2) 점프 n+1번
        ans = min(ans, (jump_max+1.0)*T);
    }
    cout << fixed;
    cout.precision(12);
    cout << ans;
    return 0;
}