#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAN_NM 201
#define MAN_N 101
#define MAX 1000000000

int N, M, K, cnt = 0;
int N_cnt = 0, M_cnt = 0;
string ans = "";
int comb[MAN_NM][MAN_NM];
int NM;

void make_comb() {
    for (int i = 0; i < MAN_NM; ++i) {
        comb[i][0] = 1;
    }

    for (int i = 1; i < MAN_NM; ++i) {
        for (int j = 1; j <= i; ++j) {
            comb[i][j] = min(MAX+1, comb[i-1][j-1] + comb[i-1][j]); // 문제 조건에서 K가 10억을 넘지 않기 때문에,
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    make_comb();

    cin >> N >> M >> K;

    N += M;
    
    for (int i = 0; i < N-1 && M > -1; ++i) {
        int num = comb[N-i-1][M];
        if (num < K) {
            ans += 'z';
            K -= num;
            --M;
        }
        else {
            ans += 'a';
        }
    }
    
    if (M > 0) ans += 'z';
    else ans += 'a';

    if (M < 0) cout << "-1";
    else cout << ans;


    return 0;
}