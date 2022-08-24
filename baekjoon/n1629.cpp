#include <iostream>
using namespace std;

int A, B, C;

long long foo(int n) {
    if (n == 1) {
        return A%C;
    }
    if (n%2 == 0) {
        long long n2 = foo(n/2)%C;
        return n2*n2%C;
    }
    else {
        long long n2 = foo((n-1)/2)%C;
        return n2*n2%C*A%C;
    }
}

int main() {
    cin >> A >> B >> C;

    long long ans = foo(B);
    cout << ans%C;

    return 0;
}