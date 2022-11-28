#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[10][10], b[10][10];
bool vis[10][10];

vector<pair<int,int>> ps, vps;
vector<bool> comb;

int mx;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void spread() {
  queue<pair<int, int>> q;

  for(auto [x, y] : vps) {
    q.push({x, y});
    vis[x][y] = 1;
  }

  while(!q.empty()) {
    int cx, cy;
    tie(cx, cy) = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(nx >= n || nx < 0 || ny >= m || ny < 0) continue;
      if(vis[nx][ny]) continue;
      if(b[nx][ny] == 1) continue;
      vis[nx][ny] = 1;
      b[nx][ny] = 2;
      q.push({nx, ny});
    }
  }
}

void getarea() {
  int cnt = 0;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cnt += (!b[i][j]);

  mx = max(cnt, mx);
}

void solve() {
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      b[i][j] = board[i][j];

  for(int i = 0; i < n; i++)
    fill(vis[i], vis[i] + m, 0);

  for(int idx = 0; idx < comb.size(); idx++) {
    if(!comb[idx]) continue;
    int x, y;
    tie(x, y) = ps[idx];
    b[x][y] = 1;
  }
  spread();
  getarea();
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int cnt = 0;

  cin >> n >> m;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) {
      cin >> board[i][j];
      if(!board[i][j]) {
        ps.push_back({i, j});
        cnt++;
      } else if(board[i][j] == 2)
        vps.push_back({i, j});
    }

  for(int i = 0; i < cnt - 3; i++)
    comb.push_back(0);
  for(int i = 0; i < 3; i++)
    comb.push_back(1);

  do solve();
  while(next_permutation(comb.begin(), comb.end()));

  cout << mx;
}