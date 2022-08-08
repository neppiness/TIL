#include <iostream>

using namespace std;

int N, L;
int board[102][102];

int pathCnt = 0;

void rotate() {
    int temp[102][102];

    for(int row = 0; row < N; row++)
        for(int col = 0; col < N; col++) temp[col][N-1-row] = board[row][col];
    for(int row = 0; row < N; row++)
        for(int col = 0; col < N; col++) board[row][col] = temp[row][col];
}

void pathCheck(int row) {
    int len[102] = {0}, diffH[102] = {0};

    int val = board[row][0];
    len[0] = 1; diffH[0] = 0;

    int idx = 0;
    for(int col = 1; col < N; col++) {
        int diff = board[row][col] - board[row][col-1];
        // diff = 1 when the right side is higher than left side
        // diff = -1 when the right side is lower than left side
        if(diff > 1 || diff < -1) {return;}
        if(diff == 1 || diff == -1) {diffH[++idx] = diff;}
        len[idx]++;
    }

    int noDom = idx + 1; // noDom = no. of domains

    if(len[0] == N) {pathCnt++; return;}

    for(int i = 1; i < noDom; i++) {
        if(diffH[i] == -1) {
            len[i] -= L;
            if(len[i] < 0) return;
        }
        else if(diffH[i] == 1) {
            len[i-1] -= L;
            if(len[i-1] < 0) return;
        }
    }

    pathCnt++; return;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); 

    cin >> N >> L;

    for(int row = 0; row < N; row++)
        for(int col = 0; col < N; col++) cin >> board[row][col];

    for(int row = 0; row < N; row++) pathCheck(row);
    rotate();
    for(int row = 0; row < N; row++) pathCheck(row);

    cout << pathCnt;
}