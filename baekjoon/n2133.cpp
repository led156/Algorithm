#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> tiles(N+1, 0);

    tiles[0] = 1;
    tiles[2] = 3;

    for (int i = 4; i <= N; i+=2) {
        tiles[i] = tiles[i-2]*3;
        for (int j = i-4; j >= 0; j-=2) {
            tiles[i] += tiles[j]*2;
        }
    }
    
    cout << tiles[N];

    return 0;
}