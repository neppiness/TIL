#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int MIN = 987654321;

bool maze[5][5][5];
bool MAZE[5][5][5];
bool vis[5][5][5] = {false};
int dist[5][5][5] = {0};

int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

void rotate(int FL) {
    bool temp[5][5];

    for(int row = 0; row < 5; row++)
        for(int col = 0; col < 5; col++) temp[col][4 - row] = maze[row][col][FL];
    for(int row = 0; row < 5; row++)
        for(int col = 0; col < 5; col++) maze[row][col][FL] = temp[row][col];

    return;
}

void reset() {
    for(int row = 0; row < 5; row++) {
        for(int col = 0; col < 5; col++) {
            for(int hgt = 0; hgt < 5; hgt++) {
                vis[row][col][hgt] = 0; dist[row][col][hgt] = 0;
            }
        }
    }
}

bool OOB(int x, int y, int z){return x >= 5 || x < 0 || y >= 5 || y < 0 || z >= 5 || z < 0;}

void bfs(){
    int x = 0, y = 0, z = 0;
    vis[0][0][0] = 1;

    queue<tuple<int,int,int>> Q;
    Q.push({x, y, z});

    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        int cx, cy, cz;
        tie(cx, cy, cz) = cur;

        for(int dir = 0; dir < 6; dir++) {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            int nz = cz + dz[dir];

            if(OOB(nx, ny, nz)) continue;
            if(vis[nx][ny][nz] || !MAZE[nx][ny][nz]) continue;
            
            Q.push({nx, ny, nz});
            vis[nx][ny][nz] = 1;
            dist[nx][ny][nz] = dist[cx][cy][cz] + 1;

            if(nx == 4 && ny == 4 && nz == 4) {
                MIN = min(dist[nx][ny][nz], MIN);
                return;
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); 

    for(int fl = 0; fl < 5; fl++)
        for(int row = 0; row < 5; row++)
            for(int col = 0; col < 5; col++) cin >> maze[row][col][fl];

    int rotateTemp[5] = {0};
    for(int cases = 0; cases < 1024; cases++) {

        rotate(0); rotateTemp[0]++;
        for(int i = 0; i < 4; i++) {
            if(rotateTemp[i] == 4) {
                rotateTemp[i] = 0;
                rotateTemp[i+1]++;
                rotate(i+1);
            }
        }

        int sequece[5] = {0, 1, 2, 3, 4};

        do {
            reset();
            for(int i = 0; i < 5; i++) {
                for(int row = 0; row < 5; row++) {
                    for (int col = 0; col < 5; col++) {
                        MAZE[row][col][sequece[i]] = maze[row][col][i];
                    }
                }
            }
            if(!MAZE[4][4][4] || !MAZE[0][0][0]) continue;
            bfs();
        } while(next_permutation(sequece, sequece+5));
    }

    if(MIN == 987654321) cout << -1;
    else cout << MIN;
}