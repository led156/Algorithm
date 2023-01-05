#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, shark_x, shark_y, shark_size = 2, shark_cnt = 0;
int board[20][20];
int eat_cnt[8];

int ans = 0;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void b_p() {
    cout << "\t*******************\n\t";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << board[i][j] << ' ';
        }
        cout << '\n' << '\t';
    }
    cout << "******************\n";
}

bool inRange(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

void bfs() {
    queue<pair<int, pair<int, int> > > que; // cnt, x, y
    int cnt = 0;
    que.push(make_pair(cnt, make_pair(shark_x, shark_y)));

    bool visited[20][20];
    fill(&visited[0][0], &visited[0][0] + 400, false);

    
    priority_queue<pair<int, int> > p_que;
    bool going = true;
    while(!que.empty()) {
        int top_cnt = que.front().first;
        int top_x = que.front().second.first;
        int top_y = que.front().second.second;
        que.pop();

        // cout << "[pop] " << top_cnt << " : " << top_x << " ," << top_y << '\n';

        
        for (int i = 0; i < 4; ++i) {
            int new_x = top_x + dx[i];
            int new_y = top_y + dy[i];

            int new_size = board[new_x][new_y];
            if (inRange(new_x, new_y) && !visited[new_x][new_y] && new_size <= shark_size) {
                visited[new_x][new_y] = true;
                if ((new_size == shark_size || new_size == 0)) { // 지나간다
                    if (going) que.push(make_pair(top_cnt+1, make_pair(new_x, new_y)));
                }
                else { // 먹는다 (new_size < shark_size)
                    if (cnt != 0 && cnt <= top_cnt)
                        continue;
                    // cout << "\t\t push " << new_x << "," << new_y << " (" << top_cnt << ")\n"; 
                    p_que.push(make_pair(-new_x, -new_y));
                    going = false;
                    cnt = top_cnt+1;
                }
            }
        }
    }
        if (!p_que.empty()) {
            int new_x = -p_que.top().first;
            int new_y = -p_que.top().second;

            int new_size = board[new_x][new_y];

            board[new_x][new_y] = 0;

            if (++shark_cnt >= shark_size) {
                ++shark_size;
                shark_cnt = 0;
            }

            shark_x = new_x;
            shark_y = new_y;

            for (int k = new_size+1; k < 8; ++k) {
                --eat_cnt[k];
            }

            ans += (cnt);

            // cout << "\t eat " << new_size << " fish\n";
            // cout << "\t shark size is " << shark_size << ", and size_count is " << shark_cnt << '\n';
            // cout << "\t step is " << cnt << ", total step is " << ans << '\n';
            // b_p();

            return ;
        }
    

}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    /* INPUT */
    cin >> N;
    fill(eat_cnt, eat_cnt+8, 0);
    

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];

            if (board[i][j] == 9) {
                shark_x = i;
                shark_y = j;
                board[i][j] = 0;
            }
            else if (board[i][j] != 0) {
                for (int k = board[i][j]+1; k < 8; ++k) {
                    ++eat_cnt[k];
                }
                
            }
        }
    }
    //b_p();
    /* SOLUTION */
    int can_eat_cnt = eat_cnt[7];
    //cout <<  '\n' <<  eat_cnt[7] << "...\n";
    for (int i = 0; i < can_eat_cnt; ++i) {
        //cout << i << " eat_cnt:" << eat_cnt[7] << " -------------\n";
        bfs();
    }
    
    cout << ans;

    return 0;
}