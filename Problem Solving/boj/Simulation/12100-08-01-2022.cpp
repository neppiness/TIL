#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int BOARD[22][22], board[22][22];
int moves[5] = {0};
int maxNum = 0;

void rotate(){
    int temp[22][22];

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) temp[j][N-i-1] = board[i][j];

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) board[i][j] = temp[i][j];
}

void move(int rot) {
    if(rot == 0) return;
        
    while(--rot) rotate();

    for(int row = 0; row < N; row++) {

        int tmp = 0;
        for(int col = 1; col < N; col++) {
            if(board[row][col] == 0) continue;

            //if(board[now][col] != 0)
            if(board[row][tmp] == 0) {
                board[row][tmp] = board[row][col];
                board[row][col] = 0;
            } else {
                if(board[row][tmp] == board[row][col]) {
                    board[row][tmp++] *= 2;
                    board[row][col] = 0;
                } else {
                    board[row][++tmp] = board[row][col];
                    board[row][col] = 0;
                }
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); 

    cin >> N;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            cin >> BOARD[i][j];

    for(int cases = 625; cases < 3125; cases++) {
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++) board[i][j] = BOARD[i][j];

        int temp = cases, idx = 0;
        while(temp) {
            moves[N - idx + 1] = temp % 5; idx++;
            temp /= 5;
        }
        
        for(int i = 0; i < 5; i++) move(moves[i]);

        for(int row = 0; row < N; row++)
            for(int col = 0; col < N; col++)
                maxNum = max(board[row][col], maxNum);
    }

    cout << maxNum;
}