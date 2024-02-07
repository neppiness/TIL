#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;

int N, M;
char board[12][12];

int MIN = 987654321;

int rotCases[10];

void rotate() {
    char temp[12][12];

    for(int row = 0; row < N; row++)
        for(int col = 0; col < M; col++) temp[col][N-row-1] = board[row][col];

    swap(M, N);

    for(int row = 0; row < N; row++)
        for(int col = 0; col < M; col++) board[row][col] = temp[row][col];
}

void rRotate() {
    char temp[12][12];

    for(int row = 0; row < N; row++)
        for(int col = 0; col < M; col++) temp[M-col-1][row] = board[row][col];

    swap(M, N);

    for(int row = 0; row < N; row++)
        for(int col = 0; col < M; col++) board[row][col] = temp[row][col];
}

void doubleRotate() {
    char temp[12][12];

    for(int row = 0; row < N; row++)
        for(int col = 0; col < M; col++) temp[N-1-row][M-1-col] = board[row][col];

    for(int row = 0; row < N; row++)
        for(int col = 0; col < M; col++) board[row][col] = temp[row][col];
}

bool moveLeft() {
    bool blueOut = 0, redOut = 0;

    for(int row = 0; row < N; row++) {
        queue<pair<int,int>> Q;
        bool exitIsOnQ = 0;
        for(int col = 0; col < M; col++) {
            char val = board[row][col];
            if(val == '#') {
                while(!Q.empty()) Q.pop();
                exitIsOnQ = 0;
            } else if(val == 'O') {Q.push({row, col}); exitIsOnQ = 1;}
            else if(val == '.') {
                if(exitIsOnQ) continue;
                Q.push({row, col});
            } else if(val == 'B' || val == 'R') {
                if(Q.empty()) continue;
                if(exitIsOnQ) {
                    if(val == 'B') blueOut = 1 ;
                    else redOut = 1;
                    board[row][col] = '.'; 
                } else {
                    auto cur = Q.front(); Q.pop();
                    board[cur.first][cur.second] = val;
                    board[row][col] = '.';
                }
            }
        }
    }

    if(blueOut) return 0;
    else return 1;
}

void solve(int cnt) {
    if(cnt == 10) {return;}

    cnt++;
    for(int rot = 0; rot < 4; rot++) {
        if(moveLeft()) {MIN = min(MIN, cnt); return;}

        solve(cnt);
        doubleRotate();
        moveLeft();
        rRotate();
    }
}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); 

    cin >> N >> M;

    for(int row = 0; row < N; row++) cin >> board[row];

    solve(0);

    if(MIN == 987654321) cout << -1;
    else cout << MIN;
}