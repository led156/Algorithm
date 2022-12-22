#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<int> arr;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;

    int num;
    while(N--) {
        cin >> num;
        arr.push_back(num);
    }

    sort(arr.begin(), arr.end());

    cout << arr[K-1];

    return 0;
}