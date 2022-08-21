#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
int L;
string s;
vector<int> pi(1000000, 0);
 
int main(){
    cin >> L >> s;
    int j = 0;
    for (int i = 1; i < L; i++) {
        while (j > 0 && s[i] != s[j]) {
            j = pi[j-1];
        }
        if (s[i] == s[j]) {
            pi[i] = ++j;
        }
    }
    cout << L - pi[L-1];
    return 0;
}