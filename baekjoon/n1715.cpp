#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main() {
    int N;
    cin >> N;
    priority_queue<int, vector<int>, greater<int> > page;
    int pages;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        cin >> pages;
        page.push(pages);
    }

    
    while (!page.empty()) {
        int a = page.top();
        page.pop();
        if (!page.empty()) {
            int b = page.top();
            page.pop();
            page.push(a+b);
            ans += (a+b);
            // printf("(%d+%d) => %d\n", a, b, ans);
        }
    }
    cout << ans;
    return 0;
}