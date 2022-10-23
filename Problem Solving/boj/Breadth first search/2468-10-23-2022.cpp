#include <bits/stdc++.h>
using namespace std;

int n;
int b[102][102];
int no[102][102];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

queue<pair<int,int>> q;
int solve(int lev) {
  int area = 0;
  for(int i = 0; i < n; i++)
    fill(no[i], no[i] + n, 0);

  int cx, cy, nx, ny;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
      if(no[i][j] || (b[i][j] <= lev)) continue;
      q.push({i, j});
      no[i][j] = ++area;
      while(!q.empty()) {
        tie(cx, cy) = q.front(); q.pop();
        for(int dir = 0; dir < 4; dir++) {
          nx = cx + dx[dir];
          ny = cy + dy[dir];

          if(nx >= n || nx < 0) continue;
          if(ny >= n || ny < 0) continue;
          if(b[nx][ny] <= lev) continue;
          if(no[nx][ny]) continue;

          no[nx][ny] = area;
          q.push({nx, ny});
        }
      }
    }
  return area;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> b[i][j];

  int ans = 0;
  for(int i = 0; i <= 100; i++)
    ans = max(ans, solve(i));
  cout << ans;
}