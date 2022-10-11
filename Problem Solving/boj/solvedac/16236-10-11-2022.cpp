#include <bits/stdc++.h>
using namespace std;

int b[22][22];
int dist[22][22];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

int n, m;
int sz = 2, eat = 0;
queue<pair<int, int>> q;

tuple<int, int, int> bfs(int x, int y) {
  while(!q.empty()) q.pop();
  for(int i = 0; i < 22; i++)
    fill(dist[i], dist[i] + 22, -1);

  dist[x][y] = 0;
  q.push({x, y});

  int lim = 0x7f7f7f7f;
  int cx, cy, nx, ny;

  vector<tuple<int, int, int>> v;
  v.push_back({lim, -1, -1});
  while(!q.empty()) {
    tie(cx, cy) = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++) {
      nx = cx + dx[dir]; ny = cy + dy[dir];
      if(nx >= n || nx < 0 || ny >= n || ny < 0) continue;
      if(dist[nx][ny] != -1) continue;
      dist[nx][ny] = dist[cx][cy] + 1;
      if(lim < dist[nx][ny]) continue;
      q.push({nx, ny});
      if(b[nx][ny] && sz >= b[nx][ny]) {
        lim = dist[nx][ny];
        v.push_back({lim, nx, ny});
      }
    }
  }
  sort(v.begin(), v.end());
  tie(ignore, nx, ny) = v[0];
  if(nx != -1 && ny != -1) b[nx][ny] = 0;
  eat++;
  return v[0];
}

int solve(int x, int y) {
  int ans = 0;
  int cx = x, cy = y;
  int nx, ny, cnt;
  while(1) {
    tie(cnt, nx, ny) = bfs(cx, cy);
    if(nx == -1 && ny == -1) break;
    ans += cnt;
    if(sz == eat) {
      sz++; eat = 0;
    }
    cx = nx; cy = ny;
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  int x, y;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
      cin >> b[i][j];
      if(b[i][j] == 9) {
        x = i; y = j;
        b[i][j] = 0;
      }
    }
  cout << solve(x, y);
}