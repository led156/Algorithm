#include <iostream>
#include <cstdlib>

using namespace std;

int N, cntt, ans = 0;
long long height[50];

double equation(int x, int x_1, int x_2, int y_1, int y_2) {
    return (double(y_2-y_1)/double(x_2-x_1))*(x-x_1) + y_1;
}

int looking(int i, int j) {
    int blocking = 0;
    if (i < j) {    // i+1과 j-1 사이의..
        for (int k = i+1; k < j; k++) {
            blocking += height[k] >= equation(k, i, j, height[i], height[j]);
        }
    }
    else if (i == j) return 0;
    else {  // j < i, j+1과 i-1 사이
        for (int k = j+1; k < i; k++) {
            blocking += height[k] >= equation(k, i, j, height[i], height[j]);
        }
    }
    return blocking == 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> height[i];
    }

    for (int i = 0; i < N; i++) {   // i에서 바라보는
        cntt = 0;
        for (int j = 0; j < N; j++) {   // j빌딩
            cntt += looking(i, j);
        }
        ans = cntt > ans ? cntt : ans;
    }
    cout << ans;

    return 0;
}