#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, long_cost, long_node, length;
int arr[10000][3];

vector<int> pNumToLine(int pNum) {
    vector<int> list;
    for (int i = 0; i < n-1; i++) {
        if (arr[i][0]==pNum) list.push_back(i);
    }
    return list;
}

int cNumToLine(int cNum) {
    int list = -1;
    for (int i = 0; i < n-1; i++) {
        if (arr[i][1]==cNum) {
            list = i; break;
        }
    }
    return list;
}

void treeS(int node, int cost) {
    vector<int> list = pNumToLine(node);
    // node의 자식노드가 더 이상 없을 때.
    if (list.size() == 0) {
        if (long_cost < cost) {
            long_cost = cost;
            long_node = node;
        }
        return ;
    }
    // 자식노드 탐색
    for (int i = 0; i < list.size(); i++) {
        int line = list[i];
        treeS(arr[line][1], cost+arr[line][2]);
    }
}

void pick(int preNode, int node, int cost) {
    int cLine = cNumToLine(node);
    vector<int> pList = pNumToLine(node);
    if (pList.size() == 0) {
        length = max(length, cost);
    }
    
    // i. 다른 자식노드(있으면)로 가고 (만약 자식노드 = preNode라면 X)
    for (int i = 0; i < pList.size(); i++) {
        int line = pList[i];
        if (arr[line][1] != preNode) pick(node, arr[line][1], cost+arr[line][2]);
    }
    
    // ii. 부모노드(있으면)로 가기 (만약 부모노드 = preNode라면 X)
    if (cLine==-1); // node가 누구의 자식 노드도 아님. = 부모 노드가 없다.
    else if (arr[cLine][0]==preNode); // node가 이미 방문한 노드.
    else pick(node, arr[cLine][0], cost+arr[cLine][2]);

}

int main() {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    treeS(1, 0);
    length = long_cost;
    pick(long_node, arr[cNumToLine(long_node)][0], arr[cNumToLine(long_node)][2]);
    cout << length;
    return 0;
}