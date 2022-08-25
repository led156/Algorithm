#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int gcd, lcm = a*b;
    
    while (a%b > 0) {
        int r = a%b;
        a = b;
        b = r;
    }

    gcd = b;
    lcm = lcm/gcd;

    cout << gcd << "\n" << lcm;

    return 0;
}