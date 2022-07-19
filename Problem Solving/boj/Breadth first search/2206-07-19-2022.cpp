#include <queue>
#include <utility>
#include <iostream>
#include <string>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    queue<pair<int,int>> blockQ;
    string str;
    int N, M; cin >> N >> M;

    int dat[N][M], dist[N][M];
    bool vis[N][M];

    blockQ.push({0,0});

    for(int i = 0; i < N; i++) {
        cin >> str;
        for(int j = 0; j < M; j++) {
            dat[i][j] = (str[j] - '0');
            if(dat[i][j] == 1) blockQ.push({i,j});
        }
    }

    int min = 2^30 - 1;
    bool isPossible = false;

    while(!blockQ.empty()) {
        pair<int,int> removed = blockQ.front(); blockQ.pop();
        dat[removed.first][removed.second] = 0;

        dist[0][0] = 1;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                vis[i][j] = false;
            }
        }

        queue<pair<int,int>> Q;

        vis[0][0] = true;
        Q.push({0,0});

        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();

            for(int dir = 0; dir < 4; dir++){
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];

                if(nx >= N || nx < 0 || ny >= M || ny < 0) continue;
                if(vis[nx][ny] == true || dat[nx][ny] == 1) continue;

                dist[nx][ny] = dist[cur.first][cur.second] + 1;
                vis[nx][ny] = true;
                Q.push({nx,ny});
            }
        }

        if(vis[N-1][M-1] != false) {
            isPossible = true;
            min = (min < dist[N-1][M-1]) ? min : dist[N-1][M-1];
        }

        // Finalize
        dat[removed.first][removed.second] = 1;
    }

    if(!isPossible) cout << -1 << '\n';
    else cout << min << '\n';

}