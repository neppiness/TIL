#include <iostream>
using namespace std;

int board[2002];
bool palin[2002][2002];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> board[i]; // 1-indexed
        palin[i][i] = true;
    }

    int M; cin >> M;

    for(int i = 1; i < N; i++)
        if(board[i] == board[i+1]) palin[i][i+1] = true;

    for(int len = 2; len < N; len++) {
        for(int i = 1; i <= N-len; i++) {
            int j = i + len;
            if(board[i] == board[j] && palin[i+1][j-1]) palin[i][j] = true;
        }
    }

    while(M--) {
        int A, B; cin >> A >> B;
        cout << palin[A][B] << '\n';
    }
}