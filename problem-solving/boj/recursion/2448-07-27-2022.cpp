#include <iostream>

using namespace std;

int N, SZ;
char board[3100][3100];

void inputStars(int n, int x, int y){
    if(n == 3) {
        board[x][y] = '*';
        board[x+1][y-1] = '*';
        board[x+1][y+1] = '*';
        for(int col = y - 2; col < y + 3; col++) board[x+2][col] = '*';
    } else {
        int nxt = n/2;
        inputStars(nxt, x, y);
        inputStars(nxt, x + nxt, y - nxt);
        inputStars(nxt, x + nxt, y + nxt);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    SZ = 2*N - 1;

    for(int row = 0; row < N; row++) fill(board[row], board[row] + SZ, ' ');

    inputStars(N, 0, N-1);
    for(int row = 0; row < N; row++) {
        for(int col = 0; col < SZ; col++) cout << board[row][col];
        cout << '\n';
    }
}