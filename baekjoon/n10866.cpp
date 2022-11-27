#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int N;

int main() {
    /* INPUT */
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    /* SOLUTION */
    deque<int> que;
    string operators = "";
    int operand;
    for (int i = 0; i < N; ++i) {
        cin >> operators;
        if (operators == "push_back") {
            cin >> operand;
            que.push_back(operand);
        }
        else if (operators == "push_front") {
            cin >> operand;
            que.push_front(operand);
        }
        else if (operators == "pop_front") {
            if (que.empty()) cout << "-1\n";
            else {
                cout << que.front() << endl;
                que.pop_front();
            }
        }
        else if (operators == "pop_back") {
            if (que.empty()) cout << "-1\n";
            else {
                cout << que.back() << endl;
                que.pop_back();
            }
        }
        else if (operators == "size") {
            cout << que.size() << endl;
        }
        else if (operators == "empty") {
            if (que.empty()) cout << "1\n";
            else cout << "0\n";
        }
        else if (operators == "front") {
            if (que.empty()) cout << "-1\n";
            else cout << que.front() << endl;
        }
        else if (operators == "back") {
            if (que.empty()) cout << "-1\n";
            else cout << que.back() << endl;
        }
    }

    return 0;
}