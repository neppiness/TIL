#include <utility>
#include <queue>
#include <iostream>
#include <string>

using namespace std;

const int MX = 100;
int board[MX][MX] = {0};
bool vis[MX][MX] = {false};

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
        }
    }

    queue<pair<int,int>> Q;
    Q.push({0,0}); vis[0][0] = true;

    int cnt = 1;
    int nx = 0, ny = 0;

    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();
    
        for(int dir = 0; dir < 4; dir++) {
            nx = cur.first + dx[dir];
            ny = cur.second + dy[dir];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if((nx == (N-1)) && (ny == (M-1))) break;
            if(vis[nx][ny] == true || board[nx][ny] != 1) continue;

            vis[nx][ny] = true;
            Q.push({nx,ny});
        }
        if((nx == (N-1)) && (ny == (M-1))) break;
    }
    cout << cnt;
}