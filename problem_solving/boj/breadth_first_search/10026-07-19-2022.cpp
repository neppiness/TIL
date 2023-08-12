#include <iostream>
#include <queue>
#include <utility>

int dX[4] = {1, 0, -1, 0};
int dY[4] = {0, 1, 0, -1};

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int N;
    cin >> N;

    string str[N];
    int M;
    for(int i = 0; i < N; i++){
        cin >> str[i];
        M = (M > str[i].length()) ? M : (str[i].length());
    }

    char dat[N][M];

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if (str[i].length() > j) dat[i][j] = str[i][j];
            else dat[i][j] = 'U';
        }
    }

    queue<pair<int,int>> Q;
    bool vis[N][M] = {false};
    int cnt = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(vis[i][j] == false) {
                vis[i][j] = true;
                Q.push({i,j});
                cnt++;
            }

            char a = dat[i][j];
            pair<int,int> cur;

            while(!Q.empty()){
                cur = Q.front(); Q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.first + dX[dir];
                    int ny = cur.second + dY[dir];

                    if(nx >= N || nx < 0 || ny < 0 || ny >= M) continue;
                    if(vis[nx][ny] == true) continue;
                    if(dat[nx][ny] != a) continue;

                    vis[nx][ny] = true;
                    Q.push({nx,ny});
                }
            }
        }
    }

    cout << cnt << ' ';

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            vis[i][j] = false;
            if(dat[i][j] == 'R') dat[i][j] = 'G';
        }
    }

    cnt = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(vis[i][j] == false) {
                vis[i][j] = true;
                Q.push({i,j});
                cnt++;
            }

            char a = dat[i][j];
            pair<int,int> cur;

            while(!Q.empty()){
                cur = Q.front(); Q.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.first + dX[dir];
                    int ny = cur.second + dY[dir];

                    if(nx >= N || nx < 0 || ny < 0 || ny >= M) continue;
                    if(vis[nx][ny] == true) continue;
                    if(dat[nx][ny] != a) continue;

                    vis[nx][ny] = true;
                    Q.push({nx,ny});
                }
            }
        }
    }

    cout << cnt;
}