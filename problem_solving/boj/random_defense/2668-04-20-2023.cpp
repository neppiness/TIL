#include <bits/stdc++.h>
using namespace std;

const int MX = 100;

int n, adj[MX + 2];
bool vis[MX + 2];
set<int> ans;

void find(int root) {
  memset(vis, 0, sizeof(vis));
  vis[root] = 1;
  set<int> tmp; tmp.insert(root);

  int cur = root, nxt;
  while(1) {
    nxt = adj[cur];
    if(vis[nxt]) break;
    tmp.insert(nxt);
    vis[nxt] = 1;
    cur = nxt;
  }
  if(nxt != root) return;
  for(int t : tmp)
    ans.insert(t);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int u = 1; u <= n; u++) {
    int v; cin >> v;
    adj[u] = v;
  }

  for(int u = 1; u <= n; u++)
    find(u);

  cout << ans.size() << '\n';
  for(int a : ans) cout << a << '\n';
}