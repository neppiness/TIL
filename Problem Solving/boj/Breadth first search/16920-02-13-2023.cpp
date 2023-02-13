#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000 + 2;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, m, p;
int s[10], cnt[10];
char b[MX][MX];
int dist[MX][MX];
bool valid[MX][MX];

queue<pair<int, int>> q[10];

bool oob(int x, int y) { return (x >= n || x < 0 || y >= m || y < 0); }

bool solve(int pl) {
  bool is_valid = 0;
  while(!q[pl].empty()) {
    auto [cx, cy] = q[pl].front(); q[pl].pop();
    if(dist[cx][cy] == s[pl]) continue;
    valid[cx][cy] = 0;
    for(int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(oob(nx, ny)) continue;
      if(b[nx][ny] != '.') continue;
      if(!valid[nx][ny]) continue;
      b[nx][ny] = (char)pl + '0';
      dist[nx][ny] = dist[cx][cy] + 1;
      q[pl].push({nx, ny});
      is_valid = 1;
      valid[cx][cy] = 1;
    }
  }
  return is_valid;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);


  // 세팅
  cin >> n >> m >> p;
  for(int i = 1; i <= p; i++) 
    cin >> s[i];
  
  for(int i = 0; i < n; i++)
    cin >> b[i];

  for(int i = 0; i < n; i++)
    fill(valid[i], valid[i] + m, 1);
  
  // 풀이
  bool is_valid;
  do  {
    is_valid = 0;
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++) {
        if(b[i][j] == '.' || b[i][j] == '#') continue;
        if(!valid[i][j]) continue;
        q[b[i][j] - '0'].push({i, j});
        dist[i][j] = 0;
      }
    for(int i = 1; i <= p; i++)
      if(solve(i)) is_valid = 1;
  } while(is_valid);

  // 답
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cnt[b[i][j] - '0']++;

  for(int i = 1; i <= p; i++)
    cout << cnt[i] << ' ';
}