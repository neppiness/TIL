#include <bits/stdc++.h>
using namespace std;

const int MX = 50;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, ans = 0x7f7f7f7f;
bool b[MX + 2][MX + 2];
bool vis[MX + 2][MX + 2];

priority_queue< tuple<int, int, int>,
    vector<tuple<int, int, int>>,
    greater<tuple<int, int, int>> > pq; // {cnt, cx, cy}

bool oob(int x, int y) {
  return (x >= n || x < 0 || y >= n || y < 0);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
      char x; cin >> x;
      b[i][j] = x - '0';
    }
  
  pq.push({0, 0, 0});
  vis[0][0] = 1;

  while(!pq.empty()) {
    auto [cnt, cx, cy] = pq.top(); pq.pop();
    for(int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(oob(nx, ny) || vis[nx][ny]) continue;
      pq.push({cnt + !b[nx][ny], nx, ny});
      vis[nx][ny] = 1;
      if(nx == n - 1 && ny == n - 1) ans = min(cnt, ans);
    }
  }
  cout << ans;
}