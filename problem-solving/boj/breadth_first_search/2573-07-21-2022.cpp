#include <iostream>
#include <queue>
#include <utility>

#define X first
#define Y second

using namespace std;

int years[303][303];
int dat[303][303];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N, M; cin >> N >> M;

    for(int i = 0; i < N; i++) {
        fill(years[i], years[i] + M, 0);
        for(int j = 0; j < M; j++) cin >> dat[i][j];
    }

    int cnt = 0, result, yr = 0;
    do {
        yr++; cnt = 0;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(dat[i][j] == 0) continue;
                if(years[i][j] == yr) continue;

                queue<pair<int,int>> Q;
                Q.push({i,j}); years[i][j] = yr; cnt++;
                if(cnt == 2) {cout << (yr - 1); return 0;}

                while(!Q.empty()) {
                    auto cur = Q.front(); Q.pop();
                    int waterCnt = 0;

                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if(nx >= N || nx < 0 || ny >= M || ny < 0) continue;
                        if(years[nx][ny] == yr) continue;

                        if(dat[nx][ny] == 0) waterCnt++;
                        else {Q.push({nx,ny}); years[nx][ny] = yr;}
                    }
                    dat[cur.X][cur.Y] -= waterCnt;
                    if(dat[cur.X][cur.Y] < 0) dat[cur.X][cur.Y] = 0;
                }
            }
        }
    } while(cnt == 1);
    cout << 0;
}