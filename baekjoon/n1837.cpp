#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_NUM 1000001

string P;
int K;
bool isNotPrime[MAX_NUM];

int oil(string s, int p) {
    int prev_res = 0;
    for (int i = 0; i < s.size(); ++i) {
        prev_res = ((10*prev_res) + s[i]-'0')%p;
    }

    return prev_res;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    isNotPrime[1] = true;
    for (int i = 2; i*i < MAX_NUM; ++i) {
        if (!isNotPrime[i]) {
            for (int j = i*i; j < MAX_NUM; j+=i) isNotPrime[j] = true;
        }
    }
    
    
    cin >> P >> K;
    for (int i = 2; i < K; i++) { // K보다 작은 소수들로 P를 나누었을 때, 나누어 떨어지는지 확인한다. => 나누어 떨어지면 BAD, 아니면 GOOD
        if (!isNotPrime[i]) { // 소수이면 이걸로 P를 나누어 본다.
            int p = oil(P, i);
            // cout << "p is "<< i << " ==>" << p << '\n';
            if(p==0) { // BAD
                cout << "BAD " << i;
                return 0;
            }
        }
    }

    cout << "GOOD";


    return 0;
}