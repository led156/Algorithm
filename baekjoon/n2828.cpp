#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int J;

int main() {
    /* INPUT */
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    cin >> J;


    /* SOLUTION */
    int ans = 0;
    int apple_pos;
    int b_pos1 = 1, b_pos2 = M;
    for (int i = 0; i < J; ++i) {
        cin >> apple_pos;

        if (!(apple_pos >= b_pos1 && apple_pos <= b_pos2)) { // 사과가 바구니에 들어갈 수 없다면
            if (apple_pos > b_pos2) { // 사과가 바구니보다 오른쪽에 있을 때
                ans += apple_pos - b_pos2;
                b_pos1 = apple_pos - M + 1;
                b_pos2 = apple_pos;
            }
            else {
                ans += b_pos1 - apple_pos;
                b_pos2 = apple_pos + M - 1;
                b_pos1 = apple_pos;
            }
        }
    }

    cout << ans;
    return 0;
}