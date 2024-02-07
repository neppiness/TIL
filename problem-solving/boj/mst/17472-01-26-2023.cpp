#include <bits/stdc++.h>
using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

bool b[102][102];
int board[102][102], p[6];
int n, m, id = 1;

vector<tuple<int, int, int>> e;

bool oob(int x, int y) {
  return (x >= n || x < 0 || y >= m || y < 0);
}

void bfs(int x, int y) {
  queue<pair<int, int>> q;
  board[x][y] = id;
  q.push({x, y});
  while(!q.empty()) {
    auto [cx, cy] = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(oob(nx, ny)) continue;
      if(board[nx][ny] != -1) continue;
      if(!b[nx][ny]) continue;
      board[nx][ny] = id;
      q.push({nx, ny});
    }
  }
  id++;
}

int find(int x) {
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}

bool is_diff_gr(int u, int v) {
  u = find(u); v = find(v);
  if(u == v) return 0;
  if(p[u] > p[v]) swap(u, v);
  p[u] += p[v];
  p[v] = u;
  return 1;
}

void find_edge() {
  for(int i = 0; i < n; i++) {
    int cnt = 0, no = 0;
    for(int j = 0; j < m; j++) {
      if(!board[i][j]) { cnt++; continue; }
      if(no && cnt >= 2) e.push_back({cnt, no, board[i][j]});
      no = board[i][j];
      cnt = 0;
    }
  }

  for(int j = 0; j < m; j++) {
    int cnt = 0, no = 0;
    for(int i = 0; i < n; i++) {
      if(!board[i][j]) { cnt++; continue; }
      if(no && cnt >= 2) e.push_back({cnt, no, board[i][j]});
      no = board[i][j];
      cnt = 0;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(board, -1, sizeof(board));
  memset(p, -1, sizeof(p));

  cin >> n >> m;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> b[i][j];

  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) {
      if(board[i][j] != -1) continue;
      if(b[i][j]) bfs(i, j);
      else board[i][j] = 0;
    }

  find_edge();
  sort(e.begin(), e.end());

  int cnt = 0, ans = 0;
  for(auto [cost, u, v] : e) {
    if(!is_diff_gr(u, v)) continue;
    ans += cost;
    cnt++;
    if(cnt == id - 2) break;
  }
  if(cnt != id - 2) cout << -1;
  else cout << ans;
}