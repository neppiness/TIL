#include <iostream>

using namespace std;

int N, M, K, NM;
bool board[42][42] = {false};

int R, C;
bool sticker[12][12] = {false};

int noOfStickers = 0;

void stick(int row, int col) {
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            board[row + i][col + j] = (board[row + i][col + j] || sticker[i][j]);
}

void rotate() {
    bool tempSTK[12][12] = {false};

    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            tempSTK[j][R-i-1] = sticker[i][j];

    int temp = R; R = C; C = temp; // std::swap in utility header could be applied

    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            sticker[i][j] = tempSTK[i][j];
}

void solve(void){
    int rot = 4;
    while(rot) {
        if(rot != 4) rotate(); rot--;

        for(int row = 0; row <= N - R; row++) {
            for(int col = 0; col <= M - C; col++) {
                bool canAttach = true;

                for(int i = 0; i < R; i++)
                    for(int j = 0; j < C; j++)
                        if(board[row + i][col + j] & sticker[i][j]) canAttach = false;
                
                if(canAttach) {stick(row, col); return;}
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M >> K;

    NM = N*M;
    while(K--) {
        cin >> R >> C;

        for(int row = 0; row < R; row++)
            for(int col = 0; col < C; col++)
                cin >> sticker[row][col];

        solve();
    }

    for(int row = 0; row < N; row++)
        for(int col = 0; col < M; col++)
            noOfStickers += board[row][col];

    cout << noOfStickers;
}