#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int n;
stack<int> st;
vector<char> result;
bool isRight = true;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;

    int num, max_num = 0;
    while (n--) {
        cin >> num;

        if (!st.empty() && st.top() > num) {
            isRight = false;
        }

        if (max_num < num) {
            for (int i = 1; i <= num - max_num; ++i) {
                st.push(max_num + i);
                result.push_back('+');
            }
            max_num = num;
        }
        st.pop();
        
        result.push_back('-');
    }

    /* OUTPUT */
    if (isRight) {
        for (vector<char>::iterator iter = result.begin(); iter != result.end(); ++iter) {
            cout << *iter << '\n';
        }
    }
    else cout << "NO\n";

    return 0;
}