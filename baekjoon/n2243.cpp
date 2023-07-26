#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 1000001
typedef long long ll;

ll n, A, B, C;
ll candy_cnt[MAX_N], tree[MAX_N*4];
/*
    candy_cnt : 리프 노드. 해당 idx값의 캔디가 몇 개 있는지
    tree : idx에 해당하는 캔디의 합을 나타내는 세그먼트트리
*/



void update(ll node_idx, int start, int end, int target, ll value) {
    if (target < start || end < target) return ;

    tree[node_idx] += value;
    if (start == end) return ;

    update(node_idx*2, start, (start+end)/2, target, value);
    update(node_idx*2+1, (start+end)/2+1, end, target, value);
}



int search(ll node_idx, int start, int end, ll target_cnt) { // *** 구간합을 사용해서
    
    while (start != end) {
        if (tree[node_idx*2] < target_cnt) {
            target_cnt -= tree[node_idx*2]; // *** 오른쪽 자식으로 이동하면서 찾는 등수가 바뀌는 것 중요.
            node_idx = node_idx*2+1;
            start = (start+end)/2+1;
        }
        else {
            node_idx = node_idx*2;
            end = (start+end)/2;
        }
    }

    update(1, 0, MAX_N-1, end, -1);

    return end+1;
}



int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> A >> B;

        if (A==1) { // B번째 사탕 꺼냄
            cout << search(1, 0, MAX_N-1, B) << '\n';
        }
        else {  // B맛(값)을 가지는 사탕 넣거나 빼기
            cin >> C;
            candy_cnt[B] += C;
            update(1, 0, MAX_N-1, B-1, C);
        }
    }

    return 0;
}