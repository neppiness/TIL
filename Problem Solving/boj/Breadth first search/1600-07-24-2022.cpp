#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int mx[4] = {1, 0, -1, 0};
int my[4] = {0, 1, 0, -1};
int hx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
int hy[8] = {1, -1, 2, -2, 2, -2, 1, -1};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int K; cin >> K;
    int W, H; cin >> W >> H;

    bool board[H][W];
    for(int i = 0; i < H; i++)
        for(int j = 0; j < W; j++) cin >> board[i][j];

    int dist[H][W][K+1];

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++) fill(dist[i][j], dist[i][j] + (K+1), -1);

    queue <tuple<int,int,int>> Q;

    if(W-1 == 0 && H-1 == 0) {cout << 0; return 0;}
    dist[0][0][K] = 0; Q.push({0,0,K});

    while(!Q.empty()) {
        int cx, cy, ck;
        tie(cx, cy, ck) = Q.front(); Q.pop();

        if(ck > 0) {
            int nk = ck - 1;
            for(int dir = 0; dir < 8; dir++) {
                int nx = cx + hx[dir]; int ny = cy + hy[dir];

                if(nx >= H || nx < 0 || ny >= W || ny < 0) continue;
                if(dist[nx][ny][nk] != -1) continue;
                if(board[nx][ny]) continue;
                Q.push({nx, ny, nk});
                dist[nx][ny][nk] = dist[cx][cy][ck] + 1;
                if(nx == H-1 && ny == W-1) {cout << dist[nx][ny][nk]; return 0;}
            }
        }

        for(int dir = 0; dir < 4; dir++) {
            int nx = cx + mx[dir]; int ny = cy + my[dir];
            int nk = ck;

            if(nx >= H || nx < 0 || ny >= W || ny < 0) continue;
            if(dist[nx][ny][nk] != -1) continue;
            if(board[nx][ny]) continue;
            Q.push({nx, ny, nk});
            dist[nx][ny][nk] = dist[cx][cy][ck] + 1;
            if(nx == H-1 && ny == W-1) {cout << dist[nx][ny][nk]; return 0;}
        }
    }

    cout << -1;
}