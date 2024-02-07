#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

#define X first
#define Y second

const int ROW = 12;
const int COL = 6;

char board[ROW][COL];
bool vis[ROW][COL] = {false};
bool isPopped;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int chainCnt = 0;

using namespace std;

void moveDown() {
    char aColumn[ROW];

    for(int col = 0; col < COL; col++) {
        int tmp = ROW - 1;
        fill(aColumn, aColumn + ROW, '.');

        for(int row = ROW - 1; row >= 0; row--) {
            if(board[row][col] == '.') continue;
            aColumn[tmp--] = board[row][col];
        }
        for(int row = 0; row < ROW; row++) board[row][col] = aColumn[row];
    }
}

void BFS(int x, int y) {
    queue<pair<int,int>> Q, qTemp;
    char cval = board[x][y];

    vis[x][y] = 1;
    Q.push({x, y}); qTemp.push({x, y});

    int length = 1;
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        int cx = cur.X; int cy = cur.Y;

        for(int dir = 0; dir < 4; dir++){
            int nx = cx + dx[dir]; int ny = cy + dy[dir];
            if(nx >= ROW || nx < 0 || ny >= COL || ny < 0) continue;
            
            char nval = board[nx][ny];
            if(vis[nx][ny] || nval != cval) continue;

            vis[nx][ny] = 1;
            Q.push({nx, ny}); qTemp.push({nx, ny});
            length++;
        }
    }

    if(length >= 4) {
        isPopped = true;
        while(!qTemp.empty()) {
            auto cur = qTemp.front(); qTemp.pop();
            board[cur.X][cur.Y] = '.';
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); 

    for(int row = 0; row < ROW; row++)
        for(int col = 0; col < COL; col++) cin >> board[row][col];
    
    do {
        for(int row = 0; row < ROW; row++) fill(vis[row], vis[row] + COL, false);
        isPopped = false;

        for(int row = 0; row < ROW; row++) {
            for(int col = 0; col < COL; col++) {
                if(board[row][col] != '.') BFS(row, col);
            }
        }
        if(isPopped) {chainCnt++; moveDown();}
    } while(isPopped);

    cout << chainCnt;
}