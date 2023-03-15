#include <bits/stdc++.h>
using namespace std;

const int MX = 50;
const int INF = 0x7f7f7f7f;

int n, m, ans = INF;
int wall_cnt, vacant_cnt, tar;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

vector<bool> comb;
vector<pair<int, int>> vi;
int b[MX + 2][MX + 2], dist[MX + 2][MX + 2];
queue<pair<int, int>> q;

bool oob(int x, int y) { return (x >= n || x < 0 || y >= n || y < 0); } 

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  vacant_cnt = n*n;

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
      cin >> b[i][j];
      if(b[i][j] == 1) wall_cnt++;
      else if(b[i][j] == 2) vi.push_back({i, j});
    }

  tar = vacant_cnt - wall_cnt;
  comb.resize(vi.size());
  fill(comb.begin(), comb.end(), 0);
  for(int i = vi.size() - m; i < vi.size(); i++)
    comb[i] = 1;

  do {
    int mx = 0, cnt = 0;
    memset(dist, -1, sizeof(dist));

    for(int i = 0; i < comb.size(); i++) {
      if(!comb[i]) continue;
      auto [x, y] =  vi[i];
      dist[x][y] = 0;
      q.push(vi[i]);
      cnt++;
    }

    while(!q.empty()) {
      auto [cx, cy] = q.front(); q.pop();
      mx = max(dist[cx][cy], mx);
      for(int dir = 0; dir < 4; dir++) {
        int nx = cx + dx[dir];
        int ny = cy + dy[dir];

        if(oob(nx, ny)) continue;
        if(b[nx][ny] == 1) continue;
        if(dist[nx][ny] != -1) continue;

        dist[nx][ny] = dist[cx][cy] + 1;
        cnt++;
        q.push({nx, ny});
      }
    }
    if(cnt != tar) continue;
    ans = min(mx, ans);
  } while(next_permutation(comb.begin(), comb.end()));

  if(ans == INF) ans = -1;
  cout << ans;
}