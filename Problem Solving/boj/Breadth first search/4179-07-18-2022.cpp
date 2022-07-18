#include <queue>
#include <iostream>
#include <utility>
#include <string>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int R, C;
    string str;

    cin >> R >> C;

    int fire[R][C] = {0}, jh[R][C] = {0};
    queue<pair<int,int>> fireQ, jhQ;

    for(int i = 0; i < R; i++){
        cin >> str;
        for(int j = 0; j < C; j++) {
            if (str[j] == '#') {fire[i][j] = -1; jh[i][j] = -1;}
            else if (str[j] == '.') {fire[i][j] = 0; jh[i][j] = 0;}
            else if (str[j] == 'J') {jh[i][j] = 1; jhQ.push({i,j});}
            else if (str[j] == 'F') {fire[i][j] = 1; fireQ.push({i,j});}
        }
    }

    // Fire check
    while(!fireQ.empty()) {
        int nx, ny;

        pair<int,int> cur = fireQ.front(); fireQ.pop();

        for(int dir = 0; dir < 4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if(fire[nx][ny] != 0) continue;

            fire[nx][ny] = fire[cur.first][cur.second] + 1;
            fireQ.push({nx, ny});
        }
    }

    // jh check
    while(!jhQ.empty()){
        int nx, ny;

        pair<int,int> cur = jhQ.front(); jhQ.pop();

        for(int dir = 0; dir < 4; dir++){
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if(nx < 0 || nx >= R || ny < 0 || ny >= C) {cout << jh[cur.first][cur.second]; return 0;}
            if(jh[nx][ny] != 0 || jh[nx][ny] >= fire[nx][ny]) continue;

            jh[nx][ny] = jh[cur.first][cur.second] + 1;
            jhQ.push({nx, ny});
        }
    }
    cout << "IMPOSSIBLE";
}