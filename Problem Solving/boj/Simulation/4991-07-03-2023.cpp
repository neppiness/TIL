#include <bits/stdc++.h>
using namespace std;

int m, n, seq;
bool has_inf_edge;

char b[22][22];
int dist[22][22];
int adj[12][12]; // adj[u][v] = cost from u to v
pair<int, int> coord[12];

queue<pair<int, int>> q;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool oob(int x, int y) {
  return (x >= n || x < 0 || y >= m || y < 0);
}

void bfs(int cur) {
  for (int i = 0; i < n; i++)
    fill(dist[i], dist[i] + m, -1);

  auto [x, y] = coord[cur];
  dist[x][y] = 0;
  q.push(coord[cur]);
  while (!q.empty()) {
    auto [cx, cy] = q.front(); q.pop();
    for (int dir = 0; dir < 4; dir++) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if (oob(nx, ny)) continue;
      if (dist[nx][ny] != -1) continue;
      if (b[nx][ny] == 'x') continue;
      dist[nx][ny] = dist[cx][cy] + 1;
      q.push({nx, ny});
    }
  }
}

int solve() {
  if (seq == 1) return 0;
  if (has_inf_edge) return -1;

  vector<int> perm(seq - 1);
  for (int i = 0; i < perm.size(); i++)
    perm[i] = i + 1;

  int ans = 0x7f7f7f7f;
  do {
    int tot = adj[0][perm[0]];
    for (int i = 1; i < perm.size(); i++)
      tot += adj[perm[i - 1]][perm[i]];
    ans = min(ans, tot);
  } while (next_permutation(perm.begin(), perm.end()));
  return ans;
}

void setedges() {
  for (int cur = 0; cur < seq; cur++) {
    bfs(cur);
    for (int nxt = cur + 1; nxt < seq; nxt++) {
      auto [nx, ny] = coord[nxt];
      adj[cur][nxt] = dist[nx][ny];
      adj[nxt][cur] = dist[nx][ny];
      if (dist[nx][ny] == -1) has_inf_edge = 1;
    }
  }
}

void getinput() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c; cin >> c;
      b[i][j] = c;
      if (c == '.') continue;
      if (c == 'o') coord[0] = {i, j};
      if (c == '*') coord[seq++] = {i, j};
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> m >> n;
  while (m != 0 || n != 0) {
    seq = 1; has_inf_edge = 0;
    getinput();
    setedges();
    cout << solve() << '\n';
    cin >> m >> n;
  }
}