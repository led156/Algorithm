#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, K;
string num;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    cin >> num;
    
    deque<char> comp;

    int cnt = K;
    for (int i = 0; i < num.size(); ++i) {
        while (cnt > 0 && !comp.empty() && comp.back() < num[i]) {
            comp.pop_back();
            --cnt;
        }
        comp.push_back(num[i]);
    }

    for (int i = 0; i < comp.size() - cnt; ++i) {
        cout << comp[i];
    }

    return 0;
}