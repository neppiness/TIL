#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

#define X first
#define Y second

using namespace std;

int N, M;
int board[10][10];

int MX = 0;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

queue<pair<int,int>> virQ;

void bfs(queue<pair<int,int>> dupQ) {

    while(!dupQ.empty()) {
        auto cur = dupQ.front(); dupQ.pop();
        int cx = cur.X, cy = cur.Y;

        for(int dir = 0; dir < 4; dir++) {
            int nx = cx + dx[dir], ny = cy + dy[dir];
            if(nx >= N || nx < 0 || ny >= M || ny < 0) continue;
            if(board[nx][ny] != 0) continue;

            board[nx][ny] = 2;
            dupQ.push({nx, ny}); virQ.push({nx, ny});
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;

    queue<pair<int,int>> Q;
    vector<pair<int,int>> vctV;

    int vctCnt = 0;
    for(int row = 0; row < N; row++){
        for(int col = 0; col < M; col++) {
            cin >> board[row][col];
            if(board[row][col] == 2) Q.push({row, col});
            else if(board[row][col] == 0) vctV.push_back({row, col});
        }
    }

    int NM = N*M;

    int vLen = vctV.size();
    // Array to generate permutations
    int comb[vLen] = {0};
    fill(comb+vLen-3,comb+vLen,1);

    do{
        queue<pair<int,int>> tempQ;

        for(int idx = 0; idx < vLen; idx++) {
            if(comb[idx] == 0) continue;

            // for comb[idx] == 1
            // Walls installation for board[cx][cy] == 0
            int cx = vctV[idx].X; int cy = vctV[idx].Y;
            board[cx][cy] = 1;
            tempQ.push({cx, cy});
        }

        bfs(Q);

        int ans = 0;
        for(int row = 0; row < N; row++)
            for(int col = 0; col < M; col++) if(board[row][col] == 0) ans++;
        MX = max(MX, ans);

        // Uninstall walls
        while(!tempQ.empty()) {
            auto cur = tempQ.front(); tempQ.pop();
            board[cur.X][cur.Y] = 0;
        }

        // Removing virus
        while(!virQ.empty()) {
            auto cur = virQ.front(); virQ.pop();
            board[cur.X][cur.Y] = 0;
        }
    } while(next_permutation(comb, comb+vLen));

    cout << MX;
}