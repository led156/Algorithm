#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, n, right, left;
priority_queue<int, vector<int>, greater<int>> pq_right;
priority_queue<int, vector<int>, less<int>> pq_left;
int mid;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    cin >> n;
    mid = n;
    cout << n << '\n';

    for (int i = 1; i < N; ++i) {
        cin >> n;
        
        if (mid < n) {
            // 1. left(a) + (1) + right(a)
                // -> left(a) + (1) + right(a+1) ; 들어온걸 right에 = mid 그대로
            // 2. left(a) + (1) + right(a+1)
                // -> left(a) + (1) + right(a+2) : 들어온걸 right에
                // -> left(a+1) + right(a+2) ; mid를 left에
                // -> left(a+1) + (1) + right(a+1) ; right를 꺼낸다.
            
            pq_right.push(n);
            
            if (pq_right.size()-pq_left.size() > 1) {
                pq_left.push(mid);
                mid = pq_right.top();
                pq_right.pop();
            }
        }
        else { // n <= mid
            // 1. left(a) + (1) + right(a)
                // -> left(a+1) + (1) + right(a) ; 들어온걸 left에
                // -> left(a+1) + right(a+1) ; mid를 right에
                // -> left(a) + (1) + right(a+1) ; left를 꺼낸다.
            // 2. left(a) + (1) + right(a+1)
                // -> left(a+1) + (1) + right(a+1) : 들어온걸 left에. = mid 그대로

            pq_left.push(n);

            if (pq_right.size() < pq_left.size()) {
                pq_right.push(mid);
                mid = pq_left.top();
                pq_left.pop();
            }
        }
        cout << mid << '\n';
    }
    

    return 0;
}