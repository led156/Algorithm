#include <iostream>
#include <algorithm>
using namespace std;

int m, v, N = 0;    // 벙커는 1번째부터, n번째까지 존재. (최대 1000번째)) N : 벙커+시작+최종의 개수를 나타냄
double safe[1002][2];   // 시작점 index 0, 목적지는 index 1, ... 1000th 벙커는 index 1001. (총 1002개)
int n_of_bunker[1002];
int tree[1002];

int isAlive(int n, double nx, double ny) {
    return (m*v*60)*(m*v*60) >= ((safe[n][0]-nx)*(safe[n][0]-nx)+(safe[n][1]-ny)*(safe[n][1]-ny));
}

// void next1(int n, int h) {   // n : 현위치의 벙커 넘버, 처음이라면 -1.
//     double nx, ny;
//     if (n <= -1) {
//         nx = x; ny = y;    
//     }
//     else {
//         nx = safe[n][0]; ny = safe[n][1];
//     }

//     for (int i = 0; i < N; i++) {
//         if (i != n && isAlive(i, nx, ny)) {
//             cout << "isAlive() : " << isAlive(i,nx,ny) << "... to (" << nx <<"," <<ny<<") from bunker#" << n << endl; 
//             if (i == 0) {
//                 minn = min(minn, h);
//                 return ;
//             }
//             else {
//                 cout << nx << ny << " go to next #" << i << endl;
//                 next(i, h+1);
//             }
//         }
//     }
// }


int main() {
    freopen("input.txt", "r", stdin);
    cin >> v >> m;

    while (cin >> safe[N][0] >> safe[N][1]) {
        N++;
    }

    for (int i = 0; i < N; i++) {
        n_of_bunker[i] = N+1;
    }
    int pre_n, pro_n;
    pre_n = pro_n = 0;
    n_of_bunker[pre_n] = 0;
    tree[pre_n] = 0;

    //next(-1, 0);
    while (pre_n <= pro_n) {
        int preB = tree[pre_n++];
        int nx = safe[preB][0]; 
        int ny = safe[preB][1];

        for (int i = 0; i < N; i++) {
            if (isAlive(i, nx, ny)) {
                if (n_of_bunker[preB]+1 < n_of_bunker[i]) { // 이전에, i번째 벙커에 도달하기 위해 방문해야 할 벙커 개수 > preB 벙커에서(preB의 벙커 개수) i번째 벙커에 바로(+1) 가기 위해 방문해야 할 벙커 개수
                    n_of_bunker[i] = n_of_bunker[preB]+1;
                    tree[++pro_n] = i;
                }
            }
        }
    }

    if (n_of_bunker[1] >= N+1) {
        cout << "No.";
    }
    else {
        cout << "Yes, visiting " << n_of_bunker[1]-1 << " other holes.";
    }

    return 0;
}