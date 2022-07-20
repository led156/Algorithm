#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, minn = 1000000001;
int arr[100];
vector<int> m;

int gcd(int p, int q) {
    if (q == 0) return p;
    else return gcd(q, p%q);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+N);

    int g = gcd(arr[1] - arr[0], arr[1] - arr[0]);
    for (int i = 1; i < N-1; i++) {
        g = gcd(g, arr[i+1] - arr[i]);
    }
    
    for (int i = 1; i*i <= g; i++) {
        if (g%i == 0) {
            m.push_back(i);
            if (g/i != i) m.push_back(g/i);
        }
    }
    sort(m.begin(), m.end());

    for (int i = 1; i < m.size(); i++) {
        cout << m[i] << " ";
    }
    
    return 0;
}