#include <queue>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int board[502][502];
bool vis[502][502] = {0};
bool visT[502][502] = {0};

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int dt[4][4][2] = {{{1,0},{1,1},{0,1},{2,1}},
{{0,0},{1,0},{1,1},{2,0}},
{{0,0},{0,1},{1,1},{0,2}},
{{1,0},{1,1},{1,2},{0,1}}};

int sum = 0, MAX = 0;

void BT(int times, int cx, int cy) {
    if(times == 4) {MAX = max(MAX, sum); return;}
    
    for(int dir = 0; dir < 4; dir++) {
        int nx = cx + dx[dir];
        int ny = cy + dy[dir];

        if(nx >= N || nx < 0 || ny >= M || ny < 0) continue;
        if(vis[nx][ny]) continue;

        vis[nx][ny] = 1;
        sum += board[nx][ny];
        BT(times + 1, nx, ny);
        vis[nx][ny] = 0;
        sum -= board[nx][ny];
    }
}

void considerTShape(int cx, int cy) {
    for(int type = 0; type < 4; type++) {
        queue<pair<int,int>> Q;
        sum = 0;
        bool isOOB = 0;
        for(int pt = 0; pt < 4; pt++) {
            int nx = cx + dt[type][pt][0];
            int ny = cy + dt[type][pt][1];
            if(nx >= N || nx < 0 || ny >= M || ny < 0) {isOOB = 1; break;}
            Q.push({nx, ny});
        }
        if(isOOB) continue;
        while(!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            sum += board[cur.first][cur.second];
        }
        MAX = max(MAX, sum);
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); 

    cin >> N >> M;

    for(int row = 0; row < N; row++)
        for(int col = 0; col < M; col++) cin >> board[row][col];

    for(int row = 0; row < N; row++)
        for(int col = 0; col < M; col++) {
            vis[row][col] = 1;
            sum += board[row][col];
            BT(1, row, col); 
            sum -= board[row][col];
        }

    for(int row = 0; row < N; row++)
            for(int col = 0; col < M; col++) considerTShape(row, col);

    cout << MAX;
}