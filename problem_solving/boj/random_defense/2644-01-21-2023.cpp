#include <bits/stdc++.h>
using namespace std;

int n, p[102], cnt[102];
int a, b, ans = -1;

void trav(int cur) {
  int nxt = p[cur];
  if(nxt == -1) return;
  if(cnt[nxt] != -1) {
    ans = cnt[cur] + cnt[nxt] + 1;
    return;
  }
  cnt[nxt] = cnt[cur] + 1;
  trav(nxt);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(p, -1, sizeof(p));
  memset(cnt, -1, sizeof(cnt));

  cin >> n >> a >> b;
  int m; cin >> m;
  while(m--) {
    int u, v;
    cin >> u >> v;
    p[v] = u;
  }
  cnt[a] = 0; cnt[b] = 0;
  trav(a); trav(b);
  cout << ans;
}