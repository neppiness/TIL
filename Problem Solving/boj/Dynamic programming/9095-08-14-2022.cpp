#include <iostream>

using namespace std;

int board[13];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int T; cin >> T;

    board[1] = 1;
    board[2] = 2;
    board[3] = 4;

    while(T--) {
        int n; cin >> n;

        if(!board[n]) {
            for(int i = 4; i <= n; i++) {
                board[i] = board[i-1] + board[i-2] + board[i-3];
            }
        }
        cout << board[n] << '\n';
    }
}