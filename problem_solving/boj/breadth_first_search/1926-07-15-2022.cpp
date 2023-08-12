#include <iostream>
#include <utility>
#include <queue>
#define X first
#define Y second

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

const int MX = 500;
int board[500][500] = {0};
bool vis[500][500] = {false};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int cnt = 0, maxArea = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            queue<pair<int, int>> Q;
            int temp = 0;

            if(vis[i][j] == false && board[i][j] == 1) {
                cnt++;
                Q.push({i,j});
                vis[i][j] = true;
            }

            while(!Q.empty()) {
                pair<int, int> cur = Q.front(); Q.pop(); temp++;
                for(int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(vis[nx][ny] == true || board[nx][ny] != 1) continue;
                    vis[nx][ny] = true;
                    Q.push({nx, ny});
                }
            }

            maxArea = (maxArea >= temp) ? maxArea : temp;
        }
    }
    cout << cnt << '\n';
    cout << maxArea;
}