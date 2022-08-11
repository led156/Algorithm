#include <iostream>
#include <string>

using namespace std;

int N, M, K, maxx = 0;
string arr[50];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cin >> K;

    for (int i = 0; i < N; i++) {
        int off_cnt = 0;
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == '0') off_cnt++;
        }
        if (off_cnt <= K && K%2 == off_cnt%2) {
            int cnt = 1;
            for (int k = i+1; k < N; k++) {
                if (arr[i]==arr[k]) cnt++;
            }
            if (cnt > maxx) maxx = cnt;
        }
        //cout << off_cnt << (off_cnt <= K) << (K%2 == off_cnt%2);
    }

    cout << maxx;
    return 0;
}