#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int x1, y1, x2, y2, x3, y3;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int ccw = x1*y2+x2*y3+x3*y1 - (x1*y3+x2*y1+x3*y2);

    if (ccw == 0) cout << 0;
    else if (ccw > 0) cout << 1;
    else cout << -1;

    return 0;
}