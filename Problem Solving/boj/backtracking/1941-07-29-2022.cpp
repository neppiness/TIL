#include <iostream>

using namespace std;

char board[5][5];
bool isUsed[5][5];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int cnt = 0;
char chillGJ[7];

bool OOB(int nx, int ny) {
    if(nx >= 5 || nx < 0 || ny >= 5 || ny < 0) return 1;
    return 0;
}

void search(int m, int cx, int cy) {
    if(m == 7) {
        int sCnt = 0;
        for(int i = 0; i < 7; i++) {
            if(chillGJ[i] == 'S') sCnt++;
        }
        if(sCnt >= 4) cnt++;
        return;
    }

    for(int dir = 0; dir < 4; dir++) {
        int nx = cx + dx[dir]; int ny = cy + dy[dir];
        if(OOB(nx, ny) || isUsed[nx][ny]) continue;
        isUsed[nx][ny] = 1;
        chillGJ[m] = board[nx][ny];
        search(m+1, nx, ny);
        isUsed[nx][ny] = 0;
    }
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    string input;

    for(int row = 0; row < 5; row++) {
        cin >> input;
        for(int col = 0; col < 5; col++) board[row][col] = input[col];
    }

    for(int row = 0; row < 5; row++) {
        for(int col = 0; col < 5; col++) {
            chillGJ[0] = board[row][col];
            isUsed[row][col] = 1;
            search(1, row, col);
        }
    }
    cout << cnt;
}