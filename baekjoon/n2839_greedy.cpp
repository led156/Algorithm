#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;

    int ans = 0;
    while (N >= 0) {
        if (N%5 == 0) {
            ans += (N/5);
            cout << ans;
            return 0;
        }

        N -= 3;
        ++ans;
    }

    cout << -1;

    return 0;
}