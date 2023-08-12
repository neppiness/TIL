// #include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <stack>
#include <tuple>

using namespace std;

int dat[100][100]; // input data, 0: water, 1: land
int isldat[100][100]; // where bridges from
int dist[100][100];

bool vis1[100][100]; // visit used for island classification
bool vis2[100][100]; // visit used for bridge consturction

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    // insert data
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> dat[i][j];
            dist[i][j] = 0;
            vis1[i][j] = false;
            vis2[i][j] = false;
        }
    }

    // Queue for the points at a perimeter of islands
    queue<tuple<int,int>> periQ;

    // Island classification
    int iscnt = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(dat[i][j] == 0) continue;
            if(vis1[i][j] == true) continue;

            queue<tuple<int,int>> Q;
            Q.push({i,j});
            vis1[i][j] = true;
            isldat[i][j] = ++iscnt;

            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                int cx, cy; tie(cx, cy) = cur;

                bool isPeri = false;
                for(int dir = 0; dir < 4; dir++){
                    int nx = cx + dx[dir];
                    int ny = cy + dy[dir];

                    if(nx >= N || nx < 0 || ny >= N || ny < 0) continue;
                    if(vis1[nx][ny] == true) continue;
                    if(dat[nx][ny] == 0) {isPeri = true; continue;}

                    isldat[nx][ny] = iscnt;
                    Q.push({nx,ny});
                    vis1[nx][ny] = true;
                }
                if(isPeri) periQ.push({cx, cy});
            }
        }
    }

    while(!periQ.empty()){
        auto cur = periQ.front(); periQ.pop();
        int cx, cy; tie(cx, cy) = cur;
        vis2[cx][cy] = true;

        for(int dir = 0; dir < 4; dir++){
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];

            if(nx >= N || nx < 0 || ny >= N || ny < 0) continue;
            if(dat[nx][ny] != 0) continue;
            if(vis2[nx][ny] == true) {
                if (isldat[nx][ny] != isldat[cx][cy]){
                    cout << (dist[nx][ny] + dist[cx][cy]);
                    return 0;
                } else continue;
            }

            vis2[nx][ny] = true;
            dist[nx][ny] = dist[cx][cy] + 1;
            isldat[nx][ny] = isldat[cx][cy];
            periQ.push({nx, ny});
        }
    }
}