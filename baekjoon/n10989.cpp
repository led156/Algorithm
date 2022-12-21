#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int cnt[10000];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    int num;
    for (int i = 0; i < N; ++i) {
        cin >> num;
        ++cnt[num-1];
    }

    for (int i = 0; i < 10000; ++i) {
        while (cnt[i]--) {
            cout << (i+1) << '\n';
        }
    }

    return 0;
}