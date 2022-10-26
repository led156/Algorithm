#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX 1000001

int N;
int seq[MAX];
int index_[MAX];
vector<int> arr; 

int main() {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> seq[i];
    }

    arr.push_back(-2000000000);
    for (int i = 1; i <= N; ++i) {
        vector<int>::iterator idx = lower_bound(arr.begin(), arr.end(), seq[i]);
        index_[i] = idx - arr.begin();
        if (idx == arr.end()) arr.push_back(seq[i]);
        else *idx = seq[i];
    }

    int len = arr.size() - 1;
    cout << len << '\n';

    return 0;
}