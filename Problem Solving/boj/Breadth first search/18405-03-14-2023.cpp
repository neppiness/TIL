#include <bits/stdc++.h>
using namespace std;

const int MX = 200;
const int VMX = 1'000;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, k;
int b[MX + 2][MX + 2];
int dist[MX + 2][MX + 2];
vector<pair<int, int>> v[VMX + 2];

queue<pair<int, int>> q;

bool oob(int x, int y) {
  return (x >= n || x < 0 || y >= n || y < 0);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dist, -1, sizeof(dist));

  cin >> n >> k;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
      int x; cin >> x;
      if(x == 0) continue;
      b[i][j] = x;
      v[x].push_back({i, j});
      dist[i][j] = 0;
    }
  
  int S, X, Y;
  cin >> S >> X >> Y;
  X--; Y--;

  for(int i = 1; i <= k; i++)
    for(auto [x, y] : v[i])
      q.push({x, y});

  while(!q.empty()) {
    auto [cx, cy] = q.front(); q.pop();
    if(dist[cx][cy] == S) continue;

    for(int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(oob(nx, ny) || b[nx][ny] != 0) continue;
      if(dist[nx][ny] != -1) continue;
      dist[nx][ny] = dist[cx][cy] + 1;
      b[nx][ny] = b[cx][cy];
      q.push({nx, ny});
    }
  }
  cout << b[X][Y];
}