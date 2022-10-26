#include <bits/stdc++.h>
using namespace std;

int n, m, k;
bool b[1002][1002];
int dist[12][1002][1002];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int solve() {
  queue<tuple<int, int, int>> q;
  q.push({0, 0, 0});
  dist[0][0][0] = 1;
  if(n == 1 && m == 1) return 1;
  
  int cx, cy, ck;
  int nx, ny, nk;
  while(!q.empty()) {
    tie(ck, cx, cy) = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++) {
      nx = cx + dx[dir];
      ny = cy + dy[dir];
      nk = ck + 1;
      if(nx < 0 || nx >= n) continue;
      if(ny < 0 || ny >= m) continue;
      if(dist[ck][nx][ny]) continue;
      if(!b[nx][ny]) {
        dist[ck][nx][ny] = dist[ck][cx][cy] + 1;
        q.push({ck, nx, ny});
      } else {
        if(ck == k) continue;
        if(dist[nk][nx][ny]) continue;
        dist[nk][nx][ny] = dist[ck][cx][cy] + 1;
        q.push({nk, nx, ny});
      }
      if(nx == (n - 1) && ny == (m - 1))
        return dist[ck][nx][ny];
    }
  }
  return -1;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;

  char a;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) {
      cin >> a;
      b[i][j] = a - '0';
    }
  cout << solve();
}