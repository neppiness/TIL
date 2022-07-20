#include <iostream>
#include <queue>
#include <tuple>
#include <string>

int N, M;

using namespace std;

bool vis[1000][1000];
int dist[1000][1000];
int wall[1000][1000];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool oob(int nx, int ny){
    return (nx >= N || nx < 0 || ny >= M || ny < 0);
}

void initialize(int N, int M) {
    string str;
    for(int i = 0; i < N; i++) {
        cin >> str;
        for(int j = 0; j < M; j++) {
            wall[i][j] = str[j] - '0';
            vis[i][j] = false;
        }
    }
}

int bfs(){
    queue<tuple<int, int, bool>> Q;

    dist[0][0] = 1; vis[0][0] = true;
    Q.push({0,0,0});

    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();

        int cx, cy;
        tie(cx, cy, ignore) = cur;

        for(int dir = 0; dir < 4; dir++){
            bool brokeWall;
            tie(ignore, ignore, brokeWall) = cur;

            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if(oob(nx,ny)) continue;
            if(vis[nx][ny]) continue;
            
            if(wall[nx][ny] == 1) {
                if(brokeWall) continue;
                else brokeWall = true;
            }

            dist[nx][ny] = dist[cx][cy] + 1;

            if((nx == N - 1) && (ny == M - 1)) return dist[nx][ny];

            vis[nx][ny] = true;
            Q.push({nx, ny, brokeWall});
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;
    initialize(N, M);

    if(N == 1 && M == 1) {cout << 1; return 0;}
    cout << bfs();
    return 0;
}