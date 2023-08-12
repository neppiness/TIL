#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n;
char board[102][102], b[102][102];
int g[102][102];

int solve(bool rg) {
  for(int i = 0; i < n; i++)
    fill(g[i], g[i] + n, 0);

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
      b[i][j] = board[i][j];
      if(rg && board[i][j] == 'R')
        b[i][j] = 'G';
    }

  queue<pair<int, int>> q;

  int cnt = 0;
  int cx, cy, nx, ny;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
      if(g[i][j]) continue;
      q.push({i, j});
      g[i][j] = cnt++;
      while(!q.empty()) {
        tie(cx, cy) = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++) {
          nx = cx + dx[dir];
          ny = cy + dy[dir];
          if(nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;
          if(g[nx][ny]) continue;
          if(b[nx][ny] != b[cx][cy]) continue;
          g[nx][ny] = cnt;
          q.push({nx, ny});
        }
      }
    }
    
  return cnt;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> board[i][j];

  cout << solve(0) << ' ' << solve(1);
}