#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int M, ans;
    cin >> M;

    string operators;
    int operands;
    for (int i = 0; i < M; ++i) {
        cin >> operators;

        if (operators == "add") {
            cin >> operands;
            ans = ans | (1<<operands);
        }
        else if (operators == "remove") {
            cin >> operands;
            ans = ans & ~(1<<operands);
        }
        else if (operators == "check") {
            cin >> operands;
            if (ans & (1 << operands)) 
                cout << 1 << "\n";
            else 
                cout << 0 << "\n";
        }
        else if (operators == "toggle") {
            cin >> operands;
            ans = ans ^ (1<<operands);
        }
        else if (operators == "all") {
            ans = (1 << 21) - 1;
        }
        else {
            ans = 0;
        }
    }


    return 0;
}