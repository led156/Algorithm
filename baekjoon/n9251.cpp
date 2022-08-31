#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;

    vector<int> v(s2.size()+1);
    vector<vector<int> > arr(s1.size()+1, v);
    

    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            arr[i][j] = max(max(arr[i-1][j], arr[i][j-1]), arr[i-1][j-1]+(s1[i-1]==s2[j-1]));
        }
    }

    cout << arr[s1.size()][s2.size()];

    return 0;
}