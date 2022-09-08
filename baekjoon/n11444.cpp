#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

map<long long, long long> fibo;

long long Fibo(long long n) {   // 도가뉴 항등식
    if (n == 0) return 0;
    else if (n == 1) return fibo[1] = 1;
    else if (n == 2) return fibo[2] = 1;

    if (fibo.count(n) <= 0) {
        if (n % 2 == 0) {
            long long n_ = Fibo(n/2);
            long long n_1 = Fibo(n/2-1);

            fibo[n] = n_ * (n_ + 2*n_1) % 1000000007;
        }
        else {
            long long n_1 = Fibo(n/2+1);
            long long n_ = Fibo(n/2);

            fibo[n] = (n_1*n_1 + n_*n_) % 1000000007;
        }
    }

    return fibo[n];
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long n;
    cin >> n;

    cout << Fibo(n);

    return 0;
}