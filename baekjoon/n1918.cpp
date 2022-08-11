#include <iostream>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;

char ss[101];
stack<char> operators;
char operatorl[6] = {'(', ')', '*', '/', '+', '-'};

int isOperator(char c) {
    return c == '(' || c == ')' || c == '*' || c == '/' || c == '+' || c == '-';
}

int operatorPriority(char c, int isTop) {
    if (c == '(') {
        if (isTop) return 0;
        else return 4;
    }
    if (c == ')') return 1;
    if (c == '*' || c == '/') return 3;
    if (c == '+' || c == '-') return 2;
    return -1;
}

void operatorPrint(char c) {
    if (c != '(' && c != ')') cout << c;
}

void operatorPush(char c) {
    // stack이 비어있는지 체크.
    if (operators.empty()) {
        operators.push(c);
        return ;
    }
    while (!operators.empty() && operatorPriority(c, 0) <= operatorPriority(operators.top(), 1)) {
        operatorPrint(operators.top());
        operators.pop();
    }
    if (c != ')') operators.push(c);
    else operators.pop();
    return ;
}

void postfix() {
    for (int i = 0; i < strlen(ss); i++) {
        if (isOperator(ss[i])) {
            operatorPush(ss[i]);        
        }
        else {
            cout << ss[i];
        }
    }
    while (!operators.empty()) {
        operatorPrint(operators.top());
        operators.pop();
    }
}

int main() {
    cin >> ss;
    postfix();
    return 0;
}