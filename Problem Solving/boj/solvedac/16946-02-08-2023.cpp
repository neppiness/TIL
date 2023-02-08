#include <bits/stdc++.h>
using namespace std;

const int MX = 1000;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, m;
int p[MX*MX + 2], ar[MX + 2][MX + 2]; // idx: m*x + y
bool vis[MX + 2][MX + 2];
char b[MX + 2][MX + 2];

int find(int x) {
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}

void merge(int u, int v) {
  u = find(u); v = find(v);
  if(u == v) return;
  if(p[u] > p[v]) swap(u, v);
  p[u] += p[v];
  p[v] = u;
}

bool oob(int x, int y) { return (x >= n || x < 0 || y >= m || y < 0); }

void calcArea(int x, int y) { // 길의 면적 계산, 부모 노드의 랭크로 면적이 계산됨.
  vis[x][y] = 1;
  queue<pair<int, int>> q;
  q.push({x, y});

  while(!q.empty()) {
    auto [cx, cy] = q.front(); q.pop();
    int curidx = m*cx + cy;

    for(int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];

      if(oob(nx, ny) || vis[nx][ny]) continue;
      if(b[nx][ny] == '1') continue;

      int nxtidx = m*nx + ny;
      merge(curidx, nxtidx);

      vis[nx][ny] = 1;
      q.push({nx, ny});
    }
  }
}

void getAdjArea(int cx, int cy) {
  ar[cx][cy] = 1;
  int ptmp[] = {-1, -1, -1, -1};

  for(int dir = 0; dir < 4; dir++) {
    int nx = cx + dx[dir];
    int ny = cy + dy[dir];

    if(oob(nx, ny)) continue;
    if(b[nx][ny] == '1') continue;

    int nxtidx = m*nx + ny;
    bool is_valid = 1;
    int nxtp = find(nxtidx);
    for(int i = 0; i < 4; i++)
      if(ptmp[i] == nxtp) is_valid = 0;
    if(!is_valid) continue;

    ptmp[dir] = nxtp;
    ar[cx][cy] -= p[nxtp];
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(p, -1, sizeof(p));

  cin >> n >> m;
  for(int i = 0; i < n; i++)
    cin >> b[i];

  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      if(b[i][j] == '0' && !vis[i][j])
        calcArea(i, j);

  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      if(b[i][j] == '1') getAdjArea(i, j);

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(b[i][j] == '0') cout << 0;
      else cout << (ar[i][j] % 10);
    }
    cout << '\n';
  }
}