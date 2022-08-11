#include <iostream>
#include <string>
#include <vector>
using namespace std;

string input;
string ex;

int main() {
    cin >> input >> ex;
    
    vector<char> ans;
    vector<char> temp;

    for (int i = 0; i < input.size(); i++) {
        ans.push_back(input[i]);

        if (ans.back() == ex[ex.size()-1] && ans.size() >= ex.size()) {
            int j;
            for (j = ex.size()-1; j >= 0; j--) {
                if (ans.back() == ex[j]) {
                    temp.push_back(ans.back());
                    ans.pop_back();
                }
                else break;
            }

            if (j == -1) {
                while (!temp.empty()) temp.pop_back();
            }
            else {
                while (!temp.empty()) {
                    ans.push_back(temp.back());
                    temp.pop_back();
                }
            }
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
    }
    if (ans.size()==0) cout << "FRULA";
    
    
    return 0;
}