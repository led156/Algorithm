#include <iostream>
#include <string>
using namespace std;

int n, m;
string cbn[101][101];

string addF(string a, string b) {
    if (a.length() > b.length()) {
        while (a.length() != b.length()) {
            b = '0' + b;
        }
    }
    if (b.length() > a.length()) {
        while (b.length() != a.length()) {
            a = '0' + a;
        }
    }
    int n1, n2, carry = 0, num;
    string sum;
    for (int i = a.length()-1; i > -1; i--) {
        n1 = a[i] - '0';
        n2 = b[i] - '0';
        num = n1 + n2 + carry;

        carry = num/10;
        num = num%10;

        sum = to_string(num) + sum;
    }
    if (carry > 0) sum = to_string(carry) + sum;
    return sum;
}

string comb(int n, int r) {
    if (r==n || r==0) return "1";
    if (cbn[n][r].length()>0) return cbn[n][r];
    cbn[n-1][r-1] = comb(n-1, r-1);
    cbn[n-1][r] = comb(n-1, r);
    return addF(cbn[n-1][r-1], cbn[n-1][r]);
}

// n_C_r + n_C_r+1 = n+1_C_r+1
int main() {
    cin >> m >> n;
    cout << comb(m, n);
    return 0; 
}