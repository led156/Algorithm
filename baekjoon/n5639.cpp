#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<int> pre_order;

void find_(int start, int end) {
    if (start >= end) return ;
    if (start == end-1) {
        cout << pre_order[start] << "\n";
        return ;
    }

    int root_num = pre_order[start];
    int idx = start;

    while (idx < end && root_num > pre_order[++idx]); // 자신을 기준으로 왼쪽 노드들은 자신보다 노드 값이 작고, 오른쪽 노드들은 자신보다 노드 값이 크다. 따라서 자신보다 큰 값이 처음 나오는 곳을 찾으면 오른쪽 자식을 구할 수 있다.

    find_(start+1, idx);
    find_(idx, end);

    cout << pre_order[start] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int temp;
    while (cin >> temp) {
        pre_order.push_back(temp);
    }

    find_(0, pre_order.size());

    return 0;
}