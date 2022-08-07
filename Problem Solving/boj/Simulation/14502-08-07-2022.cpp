#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

#define X first
#define Y second

using namespace std;

int N, M;
int board[10][10];

int MX = 0, wallCnt = 0;
int initVirCnt = 0, virCnt;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

queue<pair<int,int>> Q;

void bfs(queue<pair<int,int>> dupQ) {
    queue<pair<int,int>> virQ;

    bool vis[10][10] = {false};

    while(!dupQ.empty()) {
        auto cur = dupQ.front(); dupQ.pop();
        int cx = cur.X, cy = cur.Y;
        vis[cx][cy] = 1;

        for(int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir], ny = cy + dy[dir];
            if(nx >= N || nx < 0 || ny >= M || ny < 0) continue;
            if(vis[nx][ny] || (board[nx][ny] == 1)) continue;

            vis[nx][ny] = 1;
            board[nx][ny] = 2;
            virCnt++;
            dupQ.push({nx, ny}); virQ.push({nx, ny});
        }
    }

    while(!virQ.empty()) {
        auto cur = virQ.front(); virQ.pop();
        board[cur.X][cur.Y] = 0;
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;

    for(int row = 0; row < N; row++){
        for(int col = 0; col < M; col++) {
            cin >> board[row][col];
            if(board[row][col] == 2) {Q.push({row, col}); initVirCnt++;}
            if(board[row][col] == 1) wallCnt++;
        }
    }

    bfs(Q);

    int NM = N*M;

    int comb[NM] = {0};
    fill(comb+NM-3,comb+NM,1);

    do{
        queue<pair<int,int>> tempQ;
        for(int idx = 0; idx < NM; idx++) {
            if(comb[idx] == 0) continue;

            // for comb[idx] == 1
            int cx = idx / M; int cy = idx % M;
            if(board[cx][cy] != 0) break;

            // for board[cx][cy] == 0
            board[cx][cy] = 1;
            tempQ.push({cx, cy});
        }

        virCnt = initVirCnt;
        bfs(Q);

        int ans = NM - virCnt - (wallCnt + 3);
        MX = max(MX, ans);

        // Wall restoration
        while(!tempQ.empty()) {
            auto cur = tempQ.front(); tempQ.pop();
            board[cur.X][cur.Y] = 0;
        }

    } while(next_permutation(comb, comb+NM));

    cout << MX;
}