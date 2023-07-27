#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define END 0
#define EXIT 1
#define MAX_N 14

vector<int> idx;
vector<int> tree_out[MAX_N];
int tree_in[MAX_N];
bool visited[MAX_N];

void init() {
    idx.clear();

    for (int i = 0; i < MAX_N; ++i) {
        tree_out[i].clear();
        tree_in[i] = -1;
        visited[i] = false;
    } 
}

int input() {
    int a, b;
    while (true) {
        cin >> a >> b;
        
        if (a == -1 && b == -1) return EXIT;
        if (a == 0 && b == 0) return END;
        
        if (find(idx.begin(), idx.end(), a)==idx.end()) {
            idx.push_back(a);
            tree_in[a] = 0;
        } 
        if (find(idx.begin(), idx.end(), b)==idx.end()) {
            idx.push_back(b);
            tree_in[b] = 0;
        }
        tree_out[a].push_back(b);
        ++tree_in[b];
    }
    return END;
}

int find_root() {
    for (int i = 0; i < idx.size(); ++i) {
        if (tree_in[idx[i]]==0) return idx[i];
    }
    return -1;
}


bool BFS(int root) {
    // 사이클이 존재하는지 확인할 수 있다. = visited 다시 체크하면
    // 트리가 하나로 구성되어 있는가 = 노드중에 방문 안 한 노드가 있다면
    // cout << "<1> ";
    if (root < 0) return false;

    queue<int> que;
    que.push(root);
    visited[root] = true;

    while (!que.empty()) {
        int node = que.front();
        que.pop();

        int nxt_node;
        // cout << "[node" << node << "]->";
        for (int i = 0; i < tree_out[node].size(); ++i) {
            nxt_node = tree_out[node][i];
            // cout << nxt_node << " ";
            if (visited[nxt_node]) {
                return false;
            }
            visited[nxt_node] = true;
            que.push(nxt_node);
        }
    }
    // cout << "<2> ";

    for (int i = 0; i < idx.size(); ++i) {
        if (!visited[idx[i]]) return false;
    }
    // cout << "<3> ";

    return true;
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T = 0;
    while (true) {
        ++T;
        init();
        int inputs = input();
        if (inputs == EXIT) return 0;
        if (idx.size()==0) {
            cout << "Case "<<T<<" is a tree.\n";
            continue;
        }
        

        if (BFS(find_root())) cout << "Case "<<T<<" is a tree.\n";
        else cout << "Case "<<T<<" is not a tree.\n";
    }

    return 0;
}