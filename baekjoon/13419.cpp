#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    /* INPUT */
    cin >> T;

    /* SOLUTION */
    string s;
    while (T--) {
        cin >> s;

        string s1 = "", s2 = "";
        if (s.length()%2 == 1) 
            s += s;
        
        for (int i = 0; i < s.length(); i += 2) {
            s1 += s[i];
        }
        for (int i = 1; i < s.length(); i += 2) {
            s2 += s[i];
        }

        cout << s1 << endl << s2 << endl;
    }

    return 0;
}