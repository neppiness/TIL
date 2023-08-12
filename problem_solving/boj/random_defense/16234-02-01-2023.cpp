#include <bits/stdc++.h>
using namespace std;

const int MX = 50;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int n, l, r, ans;
int no[MX + 2][MX + 2]; // i, j 위치에 있는 노드 번호를 반환

int unused; // 총 노드 개수가 됨
int p[MX * MX + 2]; // 부모 노드 저장
int cnt[MX * MX + 2]; // 부모 노드를 공유하는 노드들의 총 인구수 저장
int tmp[MX * MX + 2]; // merge 과정 상 인구수 임시 저장

int find(int x) {
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}

void merge(int u, int v) {
  u = find(u); v = find(v);
  if(u == v) return;
  if(p[u] > p[v]) swap(u, v);
  p[u] += p[v];
  p[v] = u;
  tmp[u] += tmp[v];
}

bool oob(int x, int y) { return (x >= n || x < 0 || y >= n || y < 0); }

bool diffchk(int cur, int nxt) {
  int diff = abs(cnt[cur] - cnt[nxt]);
  return (l <= diff && r >= diff);
}

bool setup() {
  bool needspr = 0;
  for(int cx = 0; cx < n; cx++)
    for(int cy = 0; cy < n; cy++) {
      int cur = no[cx][cy];
      for(int dir = 0; dir < 4; dir++) {
        int nx = cx + dx[dir];
        int ny = cy + dy[dir];
        if(oob(nx, ny)) continue;
        int nxt = no[nx][ny];
        if(!diffchk(cur, nxt)) continue;
        needspr = 1;
        merge(cur, nxt);
      }
    }
  return needspr;
}

void spread() {
  for(int cx = 0; cx < n; cx++)
    for(int cy = 0; cy < n; cy++) {
      int cur = no[cx][cy];
      int pcur = find(cur);
      int sz = - p[pcur];
      cnt[cur] = tmp[pcur] / sz;
    }
}

void solve() {
  while(1) {
    memset(p, -1, sizeof(p));
    for(int i = 0; i < unused; i++)
      tmp[i] = cnt[i];

    bool needspr = setup();
    if(!needspr) return;
    ans++;
    spread();
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> l >> r;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++) {
      no[i][j] = unused++;
      cin >> cnt[no[i][j]];
    }
  solve();
  cout << ans << '\n';
}
