#include <iostream>
#include <queue>

using namespace std;

int T, K;
int page;
long long int ans;
long long int sum;


int main() {
    ios_base::sync_with_stdio(false);
    cin >> T;

    while (T--) {
        cin >> K;
        ans = 0;
        priority_queue<long long int, vector<long long int>, greater<long long int> > pq;
        for (int i = 0; i < K; i++) {
            cin >> page;
            pq.push(page);
        }
        for (int i = 0; i < K-1; i++) {
            sum = pq.top();
            pq.pop();
            sum += pq.top();
            pq.pop();
            ans += sum;
            pq.push(sum);
        }
        cout << ans << endl;
        pq.pop();
    }

    return 0;
}