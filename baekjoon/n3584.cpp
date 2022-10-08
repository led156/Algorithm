#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int T, N;
int parent_of[10001];
bool visited[10001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;

    int A, B;
    int a, b;
    while (T--) {
        cin >> N;

        memset(visited, false, sizeof(visited));
        memset(parent_of, 0, sizeof(parent_of));

        for (int i = 0; i < N-1; ++i) {
            cin >> A >> B;
            parent_of[B] = A;
        }

        cin >> a >> b;

        while (true) {
            visited[a] = true;
            if (parent_of[a] == 0) break;
            a = parent_of[a];
        }

        while (true) {
            if (visited[b]) {
                cout << b << '\n';
                break;
            }
            visited[b] = true;
            b = parent_of[b];
        }
    }

    return 0;
}