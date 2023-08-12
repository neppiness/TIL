#include <iostream>
#include <utility>
#include <queue>

#define X first
#define Y second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int M, N;
    cin >> M >> N;

    int val[N][M];

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> val[i][j];
        }
    }

    queue<pair<int,int>> Q;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(val[i][j] == 1) {
                Q.push({i, j});
            } else continue;
        }
    }

    int nx = 0, ny = 0;
    while(!Q.empty()) {
        pair<int,int> cur;
        cur = Q.front(); Q.pop();

        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if(val[nx][ny] != 0) continue;

            Q.push({nx, ny});
            val[nx][ny] = val[cur.X][cur.Y] + 1;
        }
    }

    int max = 0; bool zeroFound = false;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(val[i][j] == 0) {zeroFound = true; break;}
            max = ((max > val[i][j]) ? max : val[i][j]);
        }
        if (zeroFound) break;
    }

    if (zeroFound) cout << -1;
    else cout << (max - 1);
}