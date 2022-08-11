#include <iostream>
#include <cmath>
using namespace std;

int N, cnt = 0;
int arr[15];

/*
 *  같은 열, 같은 행, 대각선 상에 있으면 X.
 */
int promising(int n) {
    for (int i = 0; i < n; i++) {
        //  같은 행에 존재    ||   대각선 상
        if (arr[i]==arr[n] || (n-i==abs(arr[n]-arr[i]))) return 0;
    }
    return 1;
}

void bt(int n) {
    if (n == N) {
        cnt++;
        return;
    }
    for (int i = 0; i < N; i++) {
        arr[n] = i;
        if (promising(n)) {
            bt(n+1);
        }
    }
}

int main() {
    cin >> N;
    bt(0);
    cout << cnt;
    return 0;
}