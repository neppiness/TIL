#include <iostream>

using namespace std;

int N, M;
int r, c, d;
bool board[52][52];
bool cleaned[52][52];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); 

    cin >> N >> M;
    cin >> r >> c >> d;

    for(int row = 0; row < N; row++)
        for(int col = 0; col < M; col++) cin >> board[row][col];

    int ans = 0;
    while(1) {
        cleaned[r][c] = 1; ans++;

        int cnt = 0;
        for(; cnt < 4; cnt++) {
            d = (d + 3)%4;
            int nr = r + dx[d]; int nc = c + dy[d];
            if(nr >= N || nr < 0 || nc >= M || nc < 0) continue;
            if(board[nr][nc] || cleaned[nr][nc]) continue;
            else {r = nr; c = nc; break;}
        }

        if(cnt == 4) {
            int nr = r + dx[(d + 2)%4];
            int nc = c + dy[(d + 2)%4];
            if(board[nr][nc]) {cout << ans; return 0;}
            r = nr; c = nc; ans--;
        }
    }
}