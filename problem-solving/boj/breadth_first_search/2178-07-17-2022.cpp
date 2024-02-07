#include <utility>
#include <queue>
#include <iostream>
#include <string>

using namespace std;

const int MX = 100;
int board[MX][MX] = {0};
int dist[MX][MX];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N, M;
    cin >> N >> M;

    string str;

    for(int i = 0; i < N; i++){
        cin >> str;

        for(int j = 0; j < M; j++){
            board[i][j] = str[j] - '0';
            dist[i][j] = -1;
        }
    }

    queue<pair<int,int>> Q;
    Q.push({0,0}); dist[0][0] = 1;

    int nx, ny;

    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
    
        for(int dir = 0; dir < 4; dir++) {
            nx = cur.first + dx[dir];
            ny = cur.second + dy[dir];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(dist[nx][ny] != -1 || board[nx][ny] != 1) continue;

            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            Q.push({nx,ny});
        }
    }
    cout << dist[N-1][M-1];
}