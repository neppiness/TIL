#include <iostream>

using namespace std;

int N;
char board[2200][2200];

void blankPattern(int n, int x, int y) {
    for(int row = x; row < x + n; row++)
        for(int col = y; col < y + n; col++) board[row][col] = ' ';
}

void inputPattern(int n, int x, int y) {
    if(n == 3) {
        for(int row = x; row < x + 3; row++)
            for(int col = y; col < y + 3; col++) board[row][col] = '*';
        board[x + 1][y + 1] = ' ';
    }
    else {
        int inc = n/3;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(i == 1 && j == 1) {blankPattern(inc, x + i*inc, y + j*inc); continue;}
                inputPattern(inc, x + i*inc, y + j*inc);
            }
        }
    }
}

void outputPattern() {
    for(int row = 0; row < N; row++) {
        for(int col = 0; col < N; col++) cout << board[row][col];
        cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    inputPattern(N,0,0);
    outputPattern();
}