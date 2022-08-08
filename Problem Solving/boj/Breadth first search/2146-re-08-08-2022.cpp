#include <iostream>
#include <queue>
#include <utility>
#include <tuple>

#define X first
#define Y second

using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int N;
int islCnt = 0;

bool board[102][102];
int board2[102][102] = {0};
int dist[102][102] = {0};

bool vis[102][102] = {false};

queue<pair<int,int>> landQ;
queue<tuple<int,int,int>> periQ;
queue<pair<int,int>> bridgeQ;

void landBFS(int cx, int cy) {
    if(vis[cx][cy]) return;

    vis[cx][cy] = 1; islCnt++;
    landQ.push({cx, cy});

    while(!landQ.empty()) {
        auto cur = landQ.front(); landQ.pop();
        
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir]; int ny = cur.Y + dy[dir];
            if(nx >= N || nx < 0 || ny >= N || ny < 0) continue;
            if(vis[nx][ny]) continue;
            if(!board[nx][ny]) {periQ.push({cur.X, cur.Y, islCnt}); continue;}

            vis[nx][ny] = 1; landQ.push({nx, ny});
        }
    }
}

void bridgeBFS() {
    int ans, MIN = 987654321;

    while(!bridgeQ.empty()) {
        queue<pair<int,int>> Q;
        for(int row = 0; row < N; row++) fill(dist[row], dist[row] + N, -1);

        auto cur = bridgeQ.front(); bridgeQ.pop();
        int cx = cur.X, cy = cur.Y;

        dist[cx][cy] = 0;
        Q.push({cx,cy});
        int isID = board2[cx][cy];

        bool isDone = false;
        while(!Q.empty()) {
            auto qCur = Q.front(); Q.pop();

            for(int dir = 0; dir < 4; dir++) {
                int nx = qCur.X + dx[dir], ny = qCur.Y + dy[dir];
                if(nx >= N || nx < 0 || ny >= N || ny < 0) continue;

                int val = board2[nx][ny];
                if(val != 0 && val != isID) {
                    MIN = min(MIN, dist[qCur.X][qCur.Y]);
                    isDone = 1;
                    break;
                }

                dist[nx][ny] = dist[qCur.X][qCur.Y] + 1;
                Q.push({nx, ny});
            }
            if(isDone) break;
        }
    }

    cout << MIN;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    for(int row = 0; row < N; row++)
        for(int col = 0; col < N; col++) cin >> board[row][col];

    for(int row = 0; row < N; row++)
        for(int col = 0; col < N; col++) if(board[row][col]) landBFS(row, col);

    while(!periQ.empty()) {
        int x, y, isID;
        tie(x, y, isID) = periQ.front(); periQ.pop();

        board2[x][y] = isID;
        bridgeQ.push({x,y});
    }

    bridgeBFS();
}