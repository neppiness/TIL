#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7f7f7f7f;
int n, ans = INF, id = 0;

int b[102][102];
int dist[102][102];
int dist2[102][102];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

queue<pair<int, int>> q;
int cx, cy, nx, ny;

void ff(int x, int y) { // ff: flood fill
  b[x][y] = ++id;
  q.push({x, y});
  dist[x][y] = 0;

  while(!q.empty()) {
    tie(cx, cy) = q.front(); q.pop();
    for(int d = 0; d < 4; d++) {
      nx = cx + dx[d];
      ny = cy + dy[d];
      if(nx >= n || nx < 0) continue;
      if(ny >= n || ny < 0) continue;
      if(!dist[nx][ny] || !b[nx][ny]) continue;
      dist[nx][ny] = 0;
      b[nx][ny] = id;
      q.push({nx, ny});
    }
  }
}

bool isedge(int x, int y) {
  bool is = 0;
  for(int d = 0; d < 4; d++) {
    nx = x + dx[d];
    ny = y + dy[d];
    if(nx >= n || nx < 0) continue;
    if(ny >= n || ny < 0) continue;
    if(!b[nx][ny]) is = 1;
  }
  return is;
}

void solve(int x, int y) {
  if(!isedge(x, y)) return;

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      dist2[i][j] = dist[i][j];

  while(!q.empty()) q.pop();

  q.push({x, y});
  while(!q.empty()) {
    tie(cx, cy) = q.front(); q.pop();
    for(int d = 0; d < 4; d++) {
      nx = cx + dx[d];
      ny = cy + dy[d];

      if(nx >= n || nx < 0) continue;
      if(ny >= n || ny < 0) continue;

      if(b[nx][ny]) {
        if(b[nx][ny] != b[x][y]) {
          ans = min(ans, dist2[cx][cy]);
          return;
        } else continue;
      }
      if(dist2[nx][ny] != -1) continue;
      dist2[nx][ny] = dist2[cx][cy] + 1;
      q.push({nx, ny});
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> b[i][j];
  
  for(int i = 0; i < n; i++)
    fill(dist[i], dist[i] + n, -1);

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      if(dist[i][j] == -1 && b[i][j]) ff(i, j);

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      if(!dist[i][j]) solve(i, j);

  cout << ans;
}