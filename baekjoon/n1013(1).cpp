/*
 * regex
 */

#include <iostream>
#include <string>
#include <regex>
using namespace std;

int T;
string s;

int main() {
    cin >> T;

    while (T--) {
        cin >> s;
        if (regex_match(s, regex("(100+1+|01)+"))) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}