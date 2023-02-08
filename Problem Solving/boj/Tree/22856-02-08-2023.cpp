#include <bits/stdc++.h>
using namespace std;

const int MX = 100'000;
const int ROOT = 1;

int n;// # of nodes
int cnt, en;
int p[MX + 2], rc[MX + 2], lc[MX + 2];
bool vis[MX + 2];

void find(int cur) {
  int l = lc[cur];
  int r = rc[cur];
  if(l != -1 && !vis[l]) find(l);
  vis[cur] = 1;
  en = cur;
  if(r != -1 && !vis[r]) find(r);
}

void ptr(int cur) {
  cnt++;
  int l = lc[cur];
  int r = rc[cur];
  vis[cur] = 1;

  if(l != -1 && !vis[l]) ptr(l);
  else if(r != -1 && !vis[r]) ptr(r);
  else if(cur == en) { return; }
  else if(p[cur] != -1) ptr(p[cur]);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(p, -1, sizeof(p));
  memset(rc, -1, sizeof(rc));
  memset(lc, -1, sizeof(lc));

  cin >> n;
  for(int i = 0; i < n; i++) {
    int par, l, r;
    cin >> par >> l >> r;
    rc[par] = r; lc[par] = l;
    p[l] = par; p[r] = par;
  }

  find(ROOT);
  memset(vis, 0, sizeof(vis));
  ptr(ROOT);
  cout << cnt - 1;
}