#include <bits/stdc++.h>
using namespace std;

const int NMX = 50 + 2;
const int MMX = 10 + 2;
const int INF = 0x7f7f7f7f;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int n, m;
int zerocnt, ans = INF;
int board[NMX][NMX];
int b[NMX][NMX], dist[NMX][NMX];

vector<pair<int, int>> cand;

void setup() {
  memset(dist, -1, sizeof(dist));
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      b[i][j] = board[i][j];
}

bool oob(int x, int y) { return (x >= n || x < 0 || y >= n || y < 0); }

void solve(vector<bool> &comb) {
  queue<pair<int, int>> q;
  int cnt = zerocnt;
  for(int i = 0; i < (int)comb.size(); i++) {
    if(!comb[i]) continue;
    auto [x, y] = cand[i];
    q.push({x, y});
    dist[x][y] = 0;
  }
  int mx = 0;
  while(!q.empty()) {
    auto [cx, cy] = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(oob(nx, ny) || dist[nx][ny] != -1) continue;
      if(b[nx][ny] == 1) continue;
      dist[nx][ny] = dist[cx][cy] + 1;
      if(b[nx][ny] == 0) cnt--;
      b[nx][ny] = 2;
      mx = max(mx, dist[nx][ny]);
      q.push({nx, ny});
      if(!cnt) { ans = min(ans, mx); return; }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
      cin >> board[i][j];
      if(board[i][j] == 2) cand.push_back({i, j});
      else if(!board[i][j]) zerocnt++;
    }
  vector<bool> comb(cand.size());
  auto it = comb.rbegin();
  for(int i = 0; i < m; i++) { (*it) = 1; it++; }

  if(zerocnt == 0) { cout << 0; return 0; }
  do {
    setup();
    solve(comb);
  } while(next_permutation(comb.begin(), comb.end()));

  if(ans == INF) cout << -1;
  else cout << ans;
}