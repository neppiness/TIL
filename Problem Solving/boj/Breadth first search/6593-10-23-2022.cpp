#include <bits/stdc++.h>
using namespace std;

int l, r, c;
char b[32][32][32];
int d[32][32][32];
tuple<int, int, int> init;

int dx[] = {1, 0, -1, 0, 0, 0};
int dy[] = {0, 1, 0, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

string solve() {
  queue<tuple<int, int, int>> q;
  int ans = 0;
  int cx, cy, cz;
  int nx, ny, nz;

  for(int k = 0; k < l; k++)
    for(int i = 0; i < r; i++)
      fill(d[k][i], d[k][i] + c, 0);

  q.push(init);
  tie(cz, cx, cy) = init;
  d[cz][cx][cy] = 1;
  while(!q.empty()) {
    tie(cz, cx, cy) = q.front(); q.pop();
    for(int dir = 0; dir < 6; dir++) {
      nx = cx + dx[dir];
      ny = cy + dy[dir];
      nz = cz + dz[dir];
      if(nx >= r || nx < 0) continue;
      if(ny >= c || ny < 0) continue;
      if(nz >= l || nz < 0) continue;
      if(d[nz][nx][ny]) continue;
      if(b[nz][nx][ny] == '#') continue;
      d[nz][nx][ny] = d[cz][cx][cy] + 1;
      if(b[nz][nx][ny] == 'E') ans = d[nz][nx][ny];
      q.push({nz, nx, ny});
    }
  }
  if(!ans) return "Trapped!\n";
  else return "Escaped in " + to_string(ans - 1) + " minute(s).\n";
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> l >> r >> c;
  while(l != 0 && r != 0 && c != 0) {
    for(int k = 0; k < l; k++)
      for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++) {
          cin >> b[k][i][j];
          if(b[k][i][j] == 'S') init = {k, i, j};
        }
    cout << solve();
    cin >> l >> r >> c;
  }
}