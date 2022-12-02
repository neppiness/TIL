#include <bits/stdc++.h>
using namespace std;

int n, m;
bool b[52][52];
bool vis[52][52];

int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};

bool oob(int x, int y) { return (x >= n || x < 0 || y >= m || y < 0); }

void bfs(int x, int y) {
  queue<pair<int,int>> q;
  q.push({x, y});

  while(!q.empty()) {
    auto [cx, cy] = q.front(); q.pop();
    for(int dir = 0; dir < 8; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(oob(nx, ny)) continue;
      if(!b[nx][ny] || vis[nx][ny]) continue;
      vis[nx][ny] = 1;
      q.push({nx, ny});
    }
  }
}

int solve() {
  for(int i = 0; i < n; i++)
    fill(vis[i], vis[i] + m, 0);
  
  int cnt = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(!b[i][j]) continue;
      if(!vis[i][j]) {
        vis[i][j] = 1;
        cnt++;
        bfs(i, j);
      }
    }
  }
  return cnt;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n;
  while(n != 0 && m != 0) {
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        cin >> b[i][j];
    cout << solve() << '\n';
    cin >> m >> n;
  }
}