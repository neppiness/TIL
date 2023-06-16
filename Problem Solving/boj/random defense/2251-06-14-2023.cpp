#include <bits/stdc++.h>
using namespace std;

int a, b, c;
int dx, dy, dz;
int nxt_x, nxt_y, nxt_z;

bool vis[202][202][202];
queue<tuple<int, int, int>> q;

set<int> ans;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> a >> b >> c;
  q.push({0, 0, c});
  vis[0][0][c] = 1;

  while (!q.empty()) {
    auto [x, y, z] = q.front(); q.pop();
    if (x == 0) ans.insert(z);

    // y to x
    nxt_x = min(x + y, a);
    dy = nxt_x - x;
    if (!vis[nxt_x][y - dy][z]) {
      vis[nxt_x][y - dy][z] = 1;
      q.push({nxt_x, y - dy, z});
    }

    // z to x
    nxt_x = min(x + z, a);
    dz = nxt_x - x;
    if (!vis[nxt_x][y][z - dz]) {
      vis[nxt_x][y][z - dz] = 1;
      q.push({nxt_x, y, z - dz});
    }

    // x to y
    nxt_y = min(x + y, b);
    dx = nxt_y - y;
    if (!vis[x - dx][nxt_y][z]) {
      vis[x - dx][nxt_y][z] = 1;
      q.push({x - dx, nxt_y, z});
    }

    // z to y
    nxt_y = min(y + z, b);
    dz = nxt_y - y;
    if (!vis[x][nxt_y][z - dz]) {
      vis[x][nxt_y][z - dz] = 1;
      q.push({x, nxt_y, z - dz});
    }

    // x to z
    nxt_z = min(x + z, c);
    dx = nxt_z - z;
    if (!vis[x - dx][y][nxt_z]) {
      vis[x - dx][y][nxt_z] = 1;
      q.push({x - dx, y, nxt_z});
    }

    // y to z
    nxt_z = min(y + z, c);
    dy = nxt_z - z;
    if (!vis[x][y - dy][nxt_z]) {
      vis[x][y - dy][nxt_z] = 1;
      q.push({x, y - dy, nxt_z});
    }
  }
  for (int x : ans) cout << x << ' ';
}