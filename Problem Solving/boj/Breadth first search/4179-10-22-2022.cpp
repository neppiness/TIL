#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7f7f7f7f;
int r, c; 
char b[1002][1002];
int jh[1002][1002], f[1002][1002];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int ans = INF;

void solve(int (&dist)[1002][1002], vector<pair<int,int>> &init, bool mod) {
  queue<pair<int,int>> q;
  
  int cx, cy;
  for(auto in : init) {
    int cx = in.first;
    int cy = in.second;
    dist[cx][cy] = 1;
    q.push({cx, cy});
    if(mod) if(cx == r - 1 || cx == 0 || cy == c - 1 || cy == 0) {
      ans = dist[cx][cy];
      return;
    }
  }
  int nx, ny;
  while(!q.empty()) {
    tie(cx, cy) = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++) {
      nx = cx + dx[dir];
      ny = cy + dy[dir];
      if(nx >= r || nx < 0) continue;
      if(ny >= c || ny < 0) continue;
      if(b[nx][ny] == '#') continue;
      if(dist[nx][ny]) continue;
      if(mod) if(dist[cx][cy] + 1 >= f[nx][ny]) continue;
      dist[nx][ny] = dist[cx][cy] + 1;
      if(mod) if(nx == r - 1 || nx == 0 || ny == c - 1 || ny == 0) {
        ans = dist[nx][ny];
        return;
      }
      q.push({nx, ny});
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  vector<pair<int,int>> jhcoord, fcoord;

  cin >> r >> c;
  for(int i = 0; i < r; i++)
    for(int j = 0; j < c; j++) {
      cin >> b[i][j];
      if(b[i][j] == 'J') jhcoord.push_back({i, j});
      else if(b[i][j] == 'F') fcoord.push_back({i, j});
    }
  
  solve(f, fcoord, 0);
  solve(jh, jhcoord, 1);
  
  if(ans == INF) cout << "IMPOSSIBLE";
  else cout << ans;
}