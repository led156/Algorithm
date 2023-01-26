#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ball, k, m, s, d, x, y;
vector<pair<pair<int, int>, int > > board[50][50]; // ((m, s), d)

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1}; // 북, 북동, 동, 남동, 남, 남서, 서, 북서 -> 홀 : 대각선, 짝 : 상하좌우
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void progress(){
    vector<pair<pair<int, int>, int > > new_board[50][50]; // ((m, s), d)

    int mass, speed, direction, ni, nj;
    // 각 공들을 이동
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j].size() > 0) {
                //cout << "\nball (" << i << ", " << j << ") : ";
                for (int idx = 0; idx < board[i][j].size(); ++idx) {
                    speed = board[i][j][idx].first.second;
                    direction = board[i][j][idx].second;
                    //cout << mass << ", " << speed << ", " << direction;    

                    ni = (i + speed*dx[direction]);
                    nj = (j + speed*dy[direction]);
                    while (ni < 0) ni += n;
                    while (nj < 0) nj += n;
                    ni = ni%n;
                    nj = nj%n;
                    
                    new_board[ni][nj].push_back(board[i][j][idx]);
                    //cout << "\n\t -> (" << ni << ", " << nj << ") ";
                }
            }
        }
    }
    // 중복확인
    //cout << "\n중복확인\n";
    int sum_mass = 0, sum_speed = 0, sum_direction = -1;
    // sum_direction : -1 (아직 모름), 2 (걍 아님), 1 (대각선들), 0 (사방들)
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (new_board[i][j].size() >= 2) {
                sum_mass = 0; sum_speed = 0; sum_direction = -1;
                //cout << "(" << i << "," << j << ")";
                for (int num = 0; num < new_board[i][j].size(); ++num) {
                    sum_mass += new_board[i][j][num].first.first;
                    //cout << "\t mass[" << num << "]" << new_board[i][j][num].first.first << '\n';
                    sum_speed += new_board[i][j][num].first.second;
                    direction = new_board[i][j][num].second;
                    // sum_direction : -1 (아직 모름), 2 (걍 아님), 1 (대각선들), 0 (사방들, 짝수)
                    if (sum_direction == -1) { // 아직 아무것도 확인되지 않음.
                        sum_direction = direction%2;
                    }
                    else if (sum_direction == 2);
                    else {
                        sum_direction = (direction%2==sum_direction) ? sum_direction : 2;
                    }
                }
                mass = sum_mass / 5;
                if (mass == 0) {
                    
                    //cout << "mass is 0 ::" << sum_mass << '\n';
                    new_board[i][j].clear();
                    continue;
                }
                speed = sum_speed / new_board[i][j].size();
                //cout << " : " << mass << ", " << speed << ", " << sum_direction << '\n';

                // 모두 같다(상하좌우, 짝) : 0, 같다(대각선, 홀) : 1, 아직모름 : -1, 걍 아님 : 2
                new_board[i][j].clear();
                if (sum_direction == 2) { // 대각선 네 방향을 가짐
                    for (int d = 1; d < 8; d+=2) {
                        
                        new_board[i][j].push_back(make_pair(make_pair(mass, speed), d));
                    }
                }
                else {  // 상하좌우 방향을 가짐
                    for (int d = 0; d < 8; d+=2) {
                        
                        new_board[i][j].push_back(make_pair(make_pair(mass, speed), d));
                    }
                }
            }
        }
    }

    copy(&new_board[0][0], &new_board[0][0]+2500, &board[0][0]);
    return ;
}

int main() {
    /* INPUT */
    cin >> n >> ball >> k;
    while (ball--) {
        cin >> x >> y >> m >> s >> d;
        board[x-1][y-1].push_back(make_pair(make_pair(m, s), d));
    }
    
    /* SOLUTION */
    while (k--) {
        //cout << "\n -- " << k << " --\n";
        progress();
    }
        

    /* OUTPUT */
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j].size() > 0) {
                for (int num = 0; num < board[i][j].size(); ++num) {
                    ans += board[i][j][num].first.first;
                }
            }
        }
    }
    
    cout << ans;

    return 0;
}