#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int N, M;
    
    cin >> N;
    vector<int> N_num(N);
    for (int i = 0; i < N; i++) {
        cin >> N_num[i];
    }
    sort(N_num.begin(), N_num.end());

    int temp;
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> temp;
        cout << upper_bound(N_num.begin(), N_num.end(), temp) - lower_bound(N_num.begin(), N_num.end(), temp) << " ";
    }
    return 0;
}