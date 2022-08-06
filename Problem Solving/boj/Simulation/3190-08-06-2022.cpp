#include <iostream>
#include <deque>
#include <utility>

using namespace std;

int N, K;

int moveTime[101]; char moveDir[101];
int board[102][102] = {0};

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int ans = 0;

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); 

    cin >> N >> K;

    for(int n = 0; n < K; n++) {
        int row, col; cin >> row >> col;
        board[row-1][col-1] = 1;
    }

    int L; cin >> L;

    for(int n = 0; n < L; n++) {
        cin >> moveTime[n] >> moveDir[n];
    }

    int cx = 0, cy = 0, dir = 1;
    int idx = 0;

    deque<pair<int,int>> DQ;
    board[cx][cy] = 2;
    DQ.push_back({cx,cy});

    int nx = cx, ny = cy;
    while(1) {
        ans++;
        nx += dx[dir]; ny += dy[dir];
        auto cur = DQ.back();
        cx = cur.first; cy = cur.second;

        if(nx >= N || nx < 0 || ny >= N || ny < 0) {cout << ans; return 0;}
        if(board[nx][ny] == 2) {cout << ans; return 0;}

        if(board[nx][ny] != 1) {board[cx][cy] = 0; DQ.pop_back();}

        board[nx][ny] = 2;
        DQ.push_front({nx, ny});

        if(ans == moveTime[idx]) {
            if(moveDir[idx] == 'L') dir = (dir + 1) % 4;
            else dir = (dir + 3) % 4;
            idx++;
        }
    }
}