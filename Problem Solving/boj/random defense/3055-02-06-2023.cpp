#include <bits/stdc++.h>
using namespace std;

const int MX = 50;

char b[MX + 2][MX + 2];
int dist[MX + 2][MX + 2];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

pair<int, int> s;
vector<pair<int, int>> w;

int n, m;

bool oob(int x, int y) { return (x >= n || x < 0 || y >= m || y < 0); }

void solve() {
  queue<tuple<int, int, bool>> q; // x, y, code: 0 for water, 1 for hedgehog
  for(auto [x, y] : w) q.push({x, y, 0});
  dist[s.first][s.second] = 0;
  q.push({s.first, s.second, 1});

  while(!q.empty()) {
    auto [cx, cy, code] = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(oob(nx, ny)) continue;
      if(b[nx][ny] == '*') continue;
      if(b[nx][ny] == 'X') continue;
      if(b[nx][ny] == 'D') {
        if(!code) continue;
        cout << dist[cx][cy] + 1;
        return;
      }
      if(code == 0) { // 0 for water
        b[nx][ny] = '*'; // 물 확장
        q.push({nx, ny, code});
      } else { // 1 for hedgehog
        if(dist[nx][ny] != -1) continue;
        dist[nx][ny] = dist[cx][cy] + 1;
        q.push({nx, ny, code});
      }
    }
  }
  cout << "KAKTUS";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dist, -1, sizeof(dist));

  cin >> n >> m;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) {
      char x; cin >> x;
      b[i][j] = x;
      if(x == '*') w.push_back({i, j}); 
      else if(x == 'S') s = {i, j};
    }
  solve();
}