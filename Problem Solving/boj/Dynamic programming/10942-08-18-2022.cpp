#include <iostream>
using namespace std;

int board[2002];
bool palin[2002][2002];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;

    //1-indexed
    for(int i = 1; i <= N; i++) {
        cin >> board[i];
        palin[i][i] = true;
    }

    for(int len = 1; len < N; len++) {
        for(int i = 1; i <= N - len; i++) {
            int init = i, end = i + len;
            int d = len/2;
            if(len%2 == 0) d--;
            bool isEqual = true;
            while(end > init) {
                if(board[init] != board[end]) {isEqual = false; break;}
                init++; end--;
            }
            if(isEqual) palin[i][i + len] = true;
            else palin[i][i + len] = false;
        }
    }

    int M; cin >> M;
    while(M--) {
        int A, B; cin >> A >> B;
        cout << palin[A][B] << '\n';
    }
}