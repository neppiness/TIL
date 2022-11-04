#include <bits/stdc++.h>
using namespace std;

int n, m, k;

int d[11][1002][1002]; // k, n, m
bool b[1002][1002];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int solve() {
  if(n == 1 && m == 1) return 1;

  queue<tuple<bool, int, int, int>> q;
  int ck, cx, cy;
  int nk, nx, ny;
  bool wait;

  q.push({0, 0, 0, 0});
  d[0][0][0] = 1;
  while(!q.empty()) {
    tie(wait, ck, cx, cy) = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++) {
      nk = ck + 1;
      nx = cx + dx[dir];
      ny = cy + dy[dir];

      if(nx >= n || nx < 0) continue;
      if(ny >= m || ny < 0) continue;
      if(d[ck][nx][ny]) continue;

      if(b[nx][ny]) {
        if(ck == k) continue;
        if(d[nk][nx][ny]) continue;

        if((d[ck][cx][cy] + wait)% 2 == 0)
          q.push({1, ck, cx, cy});
        else {
          q.push({0, nk, nx, ny});
          d[nk][nx][ny] = d[ck][cx][cy] + 1 + wait;
        }
      } else {
        q.push({0, ck, nx, ny});
        d[ck][nx][ny] = d[ck][cx][cy] + 1;
      }
      if(nx == n - 1 && ny == m - 1) 
        return d[ck][nx][ny];
    }
  }
  return -1;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;

  char c;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) {
      cin >> c;
      b[i][j] = (bool)(c - '0');
    }

  cout << solve();
}