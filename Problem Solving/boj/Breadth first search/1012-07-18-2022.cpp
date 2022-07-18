#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int dX[4] = {1, 0, -1, 0};
int dY[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int testsNum;
    cin >> testsNum;

    while(testsNum--) {
        int M, N, K;
        cin >> M >> N >> K;

        bool vis[N][M];
        bool dat[N][M];

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                vis[i][j] = false;
                dat[i][j] = false;
            }
        }

        while(K--) {
            int X, Y;
            cin >> X >> Y;
            dat[Y][X] = true;
        }

        queue<pair<int,int>> Q;
        int cnt = 0;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(dat[i][j] == true && vis[i][j] == false){
                    vis[i][j] = true;
                    Q.push({i,j}); cnt++;
                }
                
                while(!Q.empty()) {
                    pair<int,int> cur;
                    cur = Q.front(); Q.pop();

                    // cout << '(' << cur.first << ',' << cur.second << ')' << '\n';

                    for(int dir = 0; dir < 4; dir++) {
                        int nx = cur.first + dX[dir];
                        int ny = cur.second + dY[dir];

                        if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                        if(vis[nx][ny] == true) continue;
                        if(dat[nx][ny] == false) continue;

                        vis[nx][ny] = true;
                        Q.push({nx, ny});
                    }
                }
            }
        }
        cout << cnt << '\n';
    }
}