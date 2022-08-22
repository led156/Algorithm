#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int main() {
    cin >> N;
    vector<int> weight(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> weight[i];
    }
    sort(weight.begin(), weight.end());

    int check = 0;
    for (int i = 0; i < N; i++) {
        if (weight[i] > check+1) {
            cout << check+1;
            return 0;
        }
        check += weight[i];
    }
    cout << check+1;
    return 0;
}