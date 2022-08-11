#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

int N;
vector<int> list[1000001];
int memo[1000001];

int main() {
    cin >> N;

    memo[1] = 0;
    list[1].push_back(1);
    for (int num = 2; num <= N; num++) {
        int a, b, c;
        a = b = c = INF;
        if (num%3 == 0) {
            a = memo[num/3] + 1;
        }
        if (num%2 == 0) {
            b = memo[num/2] + 1;
        }
        c = memo[num-1] + 1;

        int minn = min(a, min(b, c));
        if (minn == a) {
            memo[num] = a;
            list[num].resize(list[num/3].size(), 0);
            copy(list[num/3].begin(), list[num/3].end(), list[num].begin());
            list[num].push_back(num);
        }
        else if (minn == b) {
            memo[num] = b;
            list[num].resize(list[num/2].size(), 0);
            copy(list[num/2].begin(), list[num/2].end(), list[num].begin());
            list[num].push_back(num);
        }  
        else {
            memo[num] = c;
            list[num].resize(list[num-1].size(), 0);
            copy(list[num-1].begin(), list[num-1].end(), list[num].begin());
            list[num].push_back(num);
        }
    }

    cout << memo[N] << "\n";
    for (int i = list[N].size()-1; i >= 0; i--) {
        cout << list[N][i] << " ";
    }
    
    return 0;

}