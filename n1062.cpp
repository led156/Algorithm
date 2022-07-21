#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int K;
char store[26];
string arr[50];
int maxx = 0;

int cnt() {  // 
    int cntt = 0;
    for (int i = 0; i < N; i++) {
        int j;
        for (j = 4; j < arr[i].length() - 4; j++) {
            //cout << arr[i][j];
            if (find(store, store + K, arr[i][j]) == store + K) break;
        }
        if (j >= arr[i].length() - 4) cntt++;
    }
    //cout << cntt << store << "\t";
    return cntt;
}

void choose(int d) {
    if (d == K-5) {
        // 단어 count
        // max 비교
        maxx = max(maxx, cnt());
        return ;
    }
    int pre = 'b';
    if (d>0) pre = store[d+4] + 1;
    for (int i = pre; i <= 'z'-(K-5-(d+1)); i++) {
        if (i == 'a' || i == 'n' || i == 't' || i == 'i' || i == 'c') {
            continue;
        }
        store[5+d] = i;
        choose(d+1);
    }
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    if (K < 5) {
        cout << 0;
        return 0;
    }
    store[0] = ('a');
    store[1] = ('n');
    store[2] = ('t');
    store[3] = ('i');
    store[4] = ('c');
    choose(0);
    cout << maxx;
    return 0;
}