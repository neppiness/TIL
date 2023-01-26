#include <bits/stdc++.h>
using namespace std;

const int MX = 100;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int n, m;
vector<pair<int, int>> door[26];
bool haskey[26] = {};
bool vis[MX + 2][MX + 2] = {};
char board[MX + 2][MX + 2];
string key;

void init() {
  cin >> n >> m;

  for(int i = 0; i < 26; i++)
    door[i].clear();

  fill(haskey, haskey + 26, 0);

  for(int i = 0; i <= n + 1; i++) {
    fill(vis[i], vis[i] + m + 2, 0);
    fill(board[i], board[i] + m + 2, '.');
  }

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
      cin >> board[i][j];

  cin >> key;
  if(key[0] != '0')
    for(char c : key) haskey[c - 'a'] = 1;
}

bool oob(int x, int y) { return (x > n + 1 || x < 0 || y > m + 1 || y < 0); }

void solve() {
  int ans = 0;
  queue<pair<int, int>> q;
  vis[0][0] = 1;
  q.push({0, 0});

  while(!q.empty()) {
    auto [cx, cy] = q.front(); q.pop();
    for(int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(oob(nx, ny)) continue;
      if(vis[nx][ny] || board[nx][ny] == '*') continue;
      vis[nx][ny] = 1;
      if(isupper(board[nx][ny]) && !haskey[board[nx][ny] - 'A']) {
        door[board[nx][ny] - 'A'].push_back({nx, ny});
        continue;
      }
      if(islower(board[nx][ny])) {
        haskey[board[nx][ny] - 'a'] = 1;
        for(auto [x, y] : door[board[nx][ny] - 'a'])
          q.push({x, y});
      }
      if(board[nx][ny] == '$') ans++;
      q.push({nx, ny});
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    init();
    solve();
  }
}