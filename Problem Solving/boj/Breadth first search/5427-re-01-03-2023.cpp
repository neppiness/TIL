#include <bits/stdc++.h>
using namespace std;

const int MX = 1'002;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int n, m, ans; // n: col limit, m: row limit
char b[MX][MX]; // b[row][col];
int dist[MX][MX]; // dist[code][row][col];

vector<pair<int, int>> fr;
pair<int, int> sb;

void getinput() {
  memset(dist, -1, sizeof(dist));
  ans = -1;
  fr.clear();

  cin >> n >> m;
  for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++) {
      cin >> b[i][j];
      if(b[i][j] == '*') fr.push_back({i, j});
      else if(b[i][j] == '@') sb = {i, j};
    }
}

bool oob(int x, int y) { return (x >= m || x < 0 || y >= n || y < 0); }

void bfs() {  
  queue<tuple<bool, int, int>> q;
  // {code, x, y} // code: 0 for fire and 1 for sb
  // init
  q.push({1, sb.first, sb.second});
  dist[sb.first][sb.second] = 0;
  for(auto [x, y] : fr) q.push({0, x, y});
  // search
  while(!q.empty()) {
    auto [code, cx, cy] = q.front(); q.pop();
    if(code && b[cx][cy] == '*') continue;
    for(int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(oob(nx, ny)) {
        if(!code) continue;
        ans = dist[cx][cy] + 1;
        return;
      }
      if(b[nx][ny] == '#') continue;
      if(b[nx][ny] == '*') continue;
      if(code && dist[nx][ny] != -1) continue;

      if(code) dist[nx][ny] = dist[cx][cy] + 1;
      else b[nx][ny] = '*';
      q.push({code, nx, ny});
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    getinput();
    bfs();
    if(ans == -1) cout << "IMPOSSIBLE" << '\n';
    else cout << ans << '\n';
  }
}