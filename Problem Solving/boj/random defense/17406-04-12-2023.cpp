#include <bits/stdc++.h>
using namespace std;

const int MX = 52;
const int INF = 0x7f7f7f7f;

int n, m, k, ans = INF;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int A[MX][MX], a[MX][MX], b[MX][MX];

vector<tuple<int, int, int>> op;
vector<int> perm;

void rot(int x, int y, int s_lim) {
  for(int s = 1; s <= s_lim; s++) {
    int cx = x - s, cy = y - s;
    int dir = 0;
    while(dir != 4) {
      int nx = cx + dx[dir];
      int ny = cy + dy[dir];
      if(nx < x - s || ny < y - s) { dir++; continue; }
      if(nx > x + s || ny > y + s) { dir++; continue; }
      b[nx][ny] = a[cx][cy];
      swap(cx, nx); swap(cy, ny);
    }
  }
}

void solve() {
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      a[i][j] = b[i][j] = A[i][j];

  for(auto seq : perm) {
    auto [r, c, s] = op[seq];
    rot(r, c, s);
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        a[i][j] = b[i][j];
  }

  int tmp_ans = INF, tot;
  for(int i = 0; i < n; i++) {
    tot = 0;
    for(int j = 0; j < m; j++)
      tot += a[i][j];
    tmp_ans = min(tmp_ans, tot);
  }
  ans = min(tmp_ans, ans);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> A[i][j];

  perm.resize(k);
  op.resize(k);

  for(int i = 0; i < k; i++)
    perm[i] = i;
  
  for(int i = 0; i < k; i++) {
    int r, c, s;
    cin >> r >> c >> s;
    op[i] = {r - 1, c - 1, s};
  }

  do { solve(); } while(
      next_permutation(perm.begin(), perm.end())
  );
  cout << ans;
}