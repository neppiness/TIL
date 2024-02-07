#include <bits/stdc++.h>
using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int n, m;
char b[52][52];
int dist[52][52];
int ans;

queue<pair<int,int>> q;

int cnt = 0;

bool oob(int x, int y) {
  return (x >= n || x < 0 || y >= m || y < 0);
}

void bfs(int x, int y) {
  b[x][y] = '1' + cnt;
  dist[x][y] = 0;
  q.push({x, y});
  while(!q.empty()) {
    auto [cx, cy] = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(oob(nx, ny)) continue;
      if(b[nx][ny] != 'X') continue;
      b[nx][ny] = '1' + cnt;
      dist[nx][ny] = 0;
      q.push({nx, ny});
    }
  }
  cnt++;
}

void floodfill() {
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      if(b[i][j] == 'X') bfs(i, j);
}

void getstartingpoints() {
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      if(b[i][j] == '1') q.push({i, j});
}

void connect() {
  while(!q.empty()) {
    auto [cx, cy] = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(oob(nx, ny)) continue;
      if(b[nx][ny] == '2') {
        ans = dist[cx][cy];
        return;
      }
      if(dist[nx][ny] != -1) continue;
      dist[nx][ny] = dist[cx][cy] + 1;
      q.push({nx, ny});
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dist, -1, sizeof(dist));

  cin >> n >> m;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> b[i][j];
  
  floodfill();
  getstartingpoints();
  connect();
  
  cout << ans;
}