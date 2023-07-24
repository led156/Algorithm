#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_BOARD 20
#define MAX_STUDENT 101
#define MAX_VOTE 1001

int N, M, k; // 사진 개수, 총 추천 횟수, 학생 번호

struct Board
{
    /*
    학생 번호
    투표수
    게시된 시간
    */
    int idx;
    int vote;
    int time;
};

vector<Board> board(MAX_BOARD, {0, 0, 0});

int min_time = MAX_VOTE, min_vote = MAX_VOTE, del_idx = 0;
bool isBoard = false;

bool comp(const Board &b1, Board &b2) {
    return b1.idx < b2.idx;
}

int main() {
    cin >> N >> M;

    for (int i = 1; i <= M; ++i) {
        cin >> k;

        min_time = MAX_VOTE, min_vote = MAX_VOTE, del_idx = 0;
        isBoard = false;

        for (int board_idx = 0; board_idx < N; ++board_idx) {
            if (board[board_idx].idx == 0) {
                board[board_idx] = {k, 1, i};
                isBoard = true;
                break;
            }
            if (board[board_idx].idx == k) {
                ++board[board_idx].vote;
                isBoard = true;
                break;
            }
            
            if (board[board_idx].vote == min_vote && board[board_idx].time < min_time) {
                min_time = board[board_idx].time;
                del_idx = board_idx;
            }
            else if (board[board_idx].vote < min_vote) {
                min_time = board[board_idx].time;
                min_vote = board[board_idx].vote;
                del_idx = board_idx;
            }
        }

        if (!isBoard) {
            board[del_idx] = {k, 1, i};
        }

    }

    sort(board.begin(), board.begin() + N, comp);

    for (int board_idx = 0; board_idx < N; ++board_idx) {
        if (board[board_idx].idx != 0) cout << board[board_idx].idx << " ";
    }

    return 0;
}
