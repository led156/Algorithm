#include <iostream>
#include <algorithm>
using namespace std;

int N;
int list[100000];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> list[i];
    }
    sort(list, list+N);

    int left = 0;
    int right = N-1;

    int ans = abs(list[left]+list[right]);
    int ans_l = list[left], ans_r = list[right];
    while (left < right) {
        int sum = list[left] + list[right];
        if (abs(sum) < ans) {
            ans = abs(sum);
            ans_l = list[left];
            ans_r = list[right];
        }
        if (sum < 0) left++;
        else right--;
    }

    cout << ans_l << " " << ans_r;

    return 0;
}