#include <iostream>

using namespace std;

char board[70][70];

bool check(int N, int x, int y) {
    for(int row = x; row < x + N; row++)
        for(int col = y; col < y + N; col++)
            if (board[row][col] != board[x][y]) return false;
    return true;
}

void compress(int N, int x, int y){
    if(check(N, x, y)) {
        cout << (char)board[x][y];
    } else {
        cout << '(';
        compress(N/2, x, y);
        compress(N/2, x, y + N/2);
        compress(N/2, x + N/2, y);
        compress(N/2, x + N/2, y + N/2);
        cout << ')';
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;

    string str;

    for(int row = 0; row < N; row++) {
        cin >> str;
        for(int col = 0; col < N; col++) board[row][col] = str[col];
    }

    compress(N, 0, 0);
}