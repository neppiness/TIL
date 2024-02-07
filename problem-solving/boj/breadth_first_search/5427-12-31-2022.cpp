#include <bits/stdc++.h>
using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

char b[1002][1002];
int n, m, ans; // n: col, m: row
vector<pair<int, int>> fr;
pair<int, int> sb;
int d[2][1002][1002]; // 0: fire, 1: sangbum

bool oob(int x, int y) { return (x >= m || x < 0 || y >= n || y < 0); }

void bfs(bool code) {
  queue<pair<int, int>> q;
  if(!code) {
    for(auto f : fr) {
      q.push(f);
      d[0][f.first][f.second] = 0;
    }
  } else {
    q.push(sb);
    d[1][sb.first][sb.second] = 0;
  }
  while(!q.empty()) {
    auto [cx, cy] = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(oob(nx, ny)) { 
        if(!code) continue;
        ans = d[1][cx][cy] + 1;
        return;
      }
      if(b[nx][ny] == '#') continue;
      if(d[code][nx][ny] != -1) continue;
      if(code && (d[0][nx][ny] <= d[1][cx][cy] + 1)) continue;
      d[code][nx][ny] = d[code][cx][cy] + 1;
      q.push({nx, ny});
    }
  }
}

void solve() {
  memset(d, -1, sizeof(d));
  fr.clear();
  ans = 0;

  cin >> n >> m;
  for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++) {
      char &c = b[i][j]; cin >> c;
      if(c == '@') sb = {i, j};
      else if(c == '*') fr.push_back({i, j});
    }
  
  bfs(0);
  bfs(1);

  if(!ans) cout << "IMPOSSIBLE\n";
  else cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int t; cin >> t;
  while(t--) solve();
}
