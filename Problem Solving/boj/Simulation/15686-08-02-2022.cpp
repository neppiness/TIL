#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

#define X first
#define Y second

int N, M;
int board[52][52];
int MIN = 987654321;

pair<int,int> house[2502];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};


int main(void){
    ios::sync_with_stdio(0); cin.tie(0); 

    cin >> N >> M;

    queue <pair<int,int>> chickQ;
    int houseCnt = 0;
    for(int row = 0; row < N; row++) {
        for(int col = 0; col < N; col++) {
            cin >> board[row][col];
            if(board[row][col] == 2) chickQ.push({row, col});
            else if(board[row][col] == 1) house[houseCnt++] = {row, col};
        }
    }

    int chickCnt = chickQ.size();
    pair<int,int> chickBoard[chickCnt];
    bool isDeleted[chickCnt] = {false};

    int idx = 0;
    while(!chickQ.empty()){
        auto cur = chickQ.front(); chickQ.pop();
        chickBoard[idx++] = cur;
    }

    for(int i = M; i < chickCnt; i++) {isDeleted[i] = true;}


    do {
        int dist[52][52] = {0};
        bool vis[52][52] = {0};
        int chickDist = 0;

        for(int i = 0; i < chickCnt; i++) {
            int chickR = chickBoard[i].X;
            int chickC = chickBoard[i].Y;
            if(isDeleted[i]) board[chickR][chickC] = 0;
            else {
                chickQ.push({chickR, chickC});
                vis[chickR][chickC] = 1;
            }
        }

        while(!chickQ.empty()) {
            auto cur = chickQ.front(); chickQ.pop();
            int cx = cur.X; int cy = cur.Y;

            for(int dir = 0; dir < 4; dir++) {
                int nx = cx + dx[dir]; int ny = cy + dy[dir];
                if(nx >= N || nx < 0 || ny >= N || ny < 0) continue;
                if(vis[nx][ny]) continue;
                vis[nx][ny] = 1;
                dist[nx][ny] = dist[cx][cy] + 1;
                chickQ.push({nx, ny});
            }
        }

        for(int i = 0; i < houseCnt; i++) {
            int cx = house[i].X, cy = house[i].Y;
            chickDist += dist[cx][cy];
        }

        MIN = min(chickDist, MIN);

        for(int i = 0; i < chickCnt; i++) {
            if(isDeleted[i]) {
                int chickR = chickBoard[i].X;
                int chickC = chickBoard[i].Y;
                board[chickR][chickC] = 2;
            }
        }
    } while(next_permutation(isDeleted, isDeleted + chickCnt));

    cout << MIN;
}