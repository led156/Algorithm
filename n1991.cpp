#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
char arr[26][3];
vector<char> out;

int findAlpha(char c) {
    for (int i = 0; i < N; i++) {
        if (arr[i][0] == c) return i;
    }
    return -1;
}

int isAlpha(char c) {
    return (c-'A') >= 0 && (c-'Z') <= 0;
}

void preorder(int d, char prt) {
    int lineN = findAlpha(prt);
    out.push_back(prt);
    for (int i = 1; i < 3; i++) {
        if (isAlpha(arr[lineN][i])) {
            preorder(d+1, arr[lineN][i]);
        }
    }
}

void inorder(int d, char prt) {
    int lineN = findAlpha(prt);
    // 왼쪽 자식
    if (isAlpha(arr[lineN][1])) inorder(d+1, arr[lineN][1]);
    // 나 자신
    out.push_back(prt);
    // 오른쪽 자식
    if (isAlpha(arr[lineN][2])) inorder(d+1, arr[lineN][2]);
}

void postorder(int d, char prt) {
    int lineN = findAlpha(prt);
    // 왼쪽 자식
    if (isAlpha(arr[lineN][1])) postorder(d+1, arr[lineN][1]);
    // 오른쪽 자식
    if (isAlpha(arr[lineN][2])) postorder(d+1, arr[lineN][2]);
    // 나 자신
    out.push_back(prt);
}

void print() {
    for (int i = 0; i < out.size(); i++) {
        cout << out[i];
    }
    cout << endl;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }
    preorder(1, arr[0][0]);
    print();
    out.clear();
    vector<char>().swap(out);
    inorder(1, arr[0][0]);
    print();
    out.clear();
    vector<char>().swap(out);
    postorder(1, arr[0][0]);
    print();
}