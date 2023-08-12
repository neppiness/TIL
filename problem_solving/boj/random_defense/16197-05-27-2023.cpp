#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7f7f7f7f;

int n, m;
int buttons[12];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

char B[22][22], b[22][22];
pair<int, int> oc[2];

bool oob(int x, int y) {
  return (x >= n || x < 0 || y >= m || y < 0);
}

int moveAndCount(int noc) {
  pair<int, int> cc[2], nc[2]; // cur_coord & nxt_coord

  cc[0] = oc[0]; cc[1] = oc[1];
  for (int i = 0; i < noc; i++) {
    int dir = buttons[i];
    for (int j = 0; j < 2; j++) {
      auto [cx, cy] = cc[j];
      if (cx < 0 && cy < 0) continue;
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];

      if (oob(nx, ny)) {
        nc[j] = {-(j + 1), -(j + 1)};
        continue;
      }
      if (b[nx][ny] == '#') {
        nc[j] = {cx, cy};
        continue;
      }
      nc[j] = {nx, ny};
    }

    if (nc[0] == nc[1]) continue;
    for (int j = 0; j < 2; j++) {
      auto [cx, cy] = cc[j];
      if (oob(cx, cy)) continue;
      b[cx][cy] = '.';
    }
    for (int j = 0; j < 2; j++) {
      auto [nx, ny] = nc[j];
      if (!oob(nx, ny)) b[nx][ny] = 'o';
      swap(cc[j], nc[j]);
    }
  }

  int count = 0;
  for (int j = 0; j < 2; j++) {
    if (cc[j].first < 0 && cc[j].second < 0) continue;
    count++;
  }
  return count;
}

bool solve(int noc, int lv) {
  if (lv == noc) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        b[i][j] = B[i][j];
    return (moveAndCount(noc) == 1);
  }

  for (int dir = 0; dir < 4; dir++) {
    buttons[lv] = dir;
    if (solve(noc, lv + 1)) return 1;
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int idx = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> B[i][j];
      if (B[i][j] == 'o') oc[idx++] = {i, j}; 
    }
  }

  // noc: no of commands
  for (int noc = 1; noc <= 10; noc++) {
    if (!solve(noc, 0)) continue;
    cout << noc; return 0;
  }
  cout << -1;
}