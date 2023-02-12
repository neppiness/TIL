#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000;

int n, m;
char b[MX + 2][MX + 2];
int p[MX * MX + 2]; // id: mx + y
bool chk[MX * MX + 2];

int find(int x) {
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}

void try_merge(int u, int v) {
  u = find(u); v = find(v);
  if(u == v) return;
  if(p[u] > p[v]) swap(u, v);
  p[u] += p[v];
  p[v] = u;
}

pair<int, int> find_coord(int x, int y) {
  if(b[x][y] == 'U') return {x - 1, y};
  else if(b[x][y] == 'D') return {x + 1, y};
  else if(b[x][y] == 'L') return {x, y - 1};
  else return {x, y + 1};
}

bool oob(int x, int y) { return (x >= n || x < 0 || y >= m || y < 0); }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  memset(p, -1, sizeof(p));

  cin >> n >> m;
  for(int i = 0; i < n; i++)
    cin >> b[i];
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) {
      int cur = m*i + j;
      auto [ni, nj] = find_coord(i, j);
      if(oob(ni, nj)) continue;
      int nxt = m*ni + nj;
      try_merge(cur, nxt);
    }

  int cnt = 0;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) {
      int cur = m*i + j;
      cur = find(cur);
      if(chk[cur]) continue;
      chk[cur] = 1;
      cnt++;
    }
  cout << cnt;
}