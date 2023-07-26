#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 1000001
typedef long long ll;

int N, M, K, Q, a, b;
ll c;
ll datas[MAX_N], tree[4*MAX_N];

ll init(int idx, int start, int end) {
    if (start==end) {
        return tree[idx] = datas[start];
    }

    return tree[idx] = init(idx*2, start, (start+end)/2) + init(idx*2+1, (start+end)/2 + 1, end);
}

void update(int cur_idx, int start, int end, int target_idx, ll value) {
    /*
        cur_idx : 현재 노드의 인덱스
        start : 현재 노드의 구간 시작값
        end : 현재 노드의 구간 끝값
        target_idx : 업데이트하고자하는 데이터 idx
        value : 업데이트 한 값과 원래 값의 차이
    */
    // target이 포함되지 않을 때
    if (target_idx < start || end < target_idx) return ;

    tree[cur_idx] += value;
    // cout << "[update tree] " << cur_idx << " => +" << value << '\n';

    if (start != end) { // 리프노드 아닐 때
        update(cur_idx*2, start, (start+end)/2, target_idx, value);
        update(cur_idx*2+1, (start+end)/2+1, end, target_idx, value);
    }
}

ll sum(int idx, int start, int end, int left, int right) {
    /*
        idx : 현재 노드의 인덱스
        start : 현재 노드의 구간 시작값
        end : 현재 노드의 구간 끝값
        left : 구하고자하는 구간의 시작값
        right : 구하고자하는 구간의 끝값
    */
    
    // 1. 구하고 싶은 범위에 아예 맞지 않을 때
    if (start > right || end < left) return 0;

    // 2. 구하고 싶은 범위가 모두 포함될 때
    if (left <= start && end <= right) return tree[idx];

    // 3. 구하고 싶은 범위가 일부 포함될 때
    return sum(idx*2, start, (start+end)/2, left, right) + sum(idx*2+1, (start+end)/2+1, end, left, right);
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;
    Q = M+K;

    for (int i = 0; i < N; ++i) {
        cin >> datas[i];
    }
    init(1, 0, N-1);


    for (int i = 0; i < Q; ++i) {
        cin >> a >> b >> c;

        if (a==1) { // update
            c = c - datas[b-1];
            datas[b-1] += c;

            // cout << "update idx" << b-1 << " =>" << datas[b-1] << ", diff" << c << '\n';
            update(1, 0, N-1, b-1, c);
        }
        else if (a==2) { // 구간합 구하기
            cout << sum(1, 0, N-1, b-1, c-1) << '\n';
        }
    }

    return 0;
}