#include <bits/stdc++.h>
using namespace std;

const int INF = 987987987;

int n, m;
bool b[1002][1002];
int d[1002][1002][2];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
queue<tuple<int, int, int>> q;

int solve() {
  q.push({1, 1, 0});
  d[1][1][0] = 1;
  while(!q.empty()) {
    int cx, cy, cst;
    tie(cx, cy, cst) = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      int nst = cst;
      if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
      if(d[nx][ny][cst] != -1) continue;
      if(b[nx][ny]) {
        if(!cst) nst = cst + 1;
        else continue;
      }
      q.push({nx, ny, nst});
      d[nx][ny][nst] = d[cx][cy][cst] + 1;
    }
  }
  int ans;
  for(int st = 0; st < 2; st++)
    if(d[n][m][st] == -1) d[n][m][st] = INF;
  ans = min(d[n][m][0], d[n][m][1]);
  if(ans == INF) ans = -1;
  return ans;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  char a;
  for(int i = 1; i <= n; i++) 
    for(int j = 1; j <= m; j++) {
      cin >> a;
      b[i][j] = a - '0';
    }

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
      fill(d[i][j], d[i][j] + 2, -1);

  cout << solve();
}