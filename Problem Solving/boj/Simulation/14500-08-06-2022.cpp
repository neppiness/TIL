#include <queue>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int board[502][502];
bool vis[502][502];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int MAX = 0, IDX = 0;

int lengthCalc(int x, int y) {
    bool vis2[502][502] = {0};
    queue<pair<int,int>> Q;

    int sum = 0, len = 0;
    for(int idx = 0; idx < 16; idx++) {
        int nx = x + idx / 4;
        int ny = y + idx % 4;
        if(vis[nx][ny]) {
            Q.push({nx,ny});
            vis2[nx][ny] = 1;
            sum += board[nx][ny];
            len++; break;
        }
    }

    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        int cx = cur.first; int cy = cur.second;

        for(int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir]; int ny = cy + dy[dir];

            if(nx >= N || nx < 0 || ny >= M || ny < 0) continue;
            if(vis2[nx][ny] || !vis[nx][ny]) continue;

            vis2[nx][ny] = 1; Q.push({nx, ny});

            sum += board[nx][ny];
            len++;
        }
    }

    if(len == 4) return sum;
    else return 0;
}

void solve(int times, int a) {
    int cx = IDX / (M-3), cy = IDX % (M-3);

    if(times == 4) {
        MAX = max(MAX, lengthCalc(cx, cy)); return;
    }

    for(int i = a; i < 16; i++) {
        int nx = cx + i / 4;
        int ny = cy + i % 4;

        if(vis[nx][ny]) continue;
        vis[nx][ny] = 1;
        solve(times + 1, i);
        vis[nx][ny] = 0;
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); 

    cin >> N >> M;

    for(int row = 0; row < N; row++)
        for(int col = 0; col < M; col++) cin >> board[row][col];

    int MX = (N - 3)*(M - 3);

    for(; IDX < MX; IDX++) solve(0, 0);

    cout << MAX;
}