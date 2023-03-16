#include <bits/stdc++.h>
using namespace std;

const int MX = 2000;

int n, m;
vector<int> adj[MX + 2];
int d[MX + 2];

int dfs(int cur) {
  int mx = d[cur];
  for(int nxt : adj[cur]) {
    if(d[nxt] != -1) continue;
    d[nxt] = d[cur] + 1;
    mx = max(mx, dfs(nxt));
  }
  return mx;
} 

bool solve(int root) {
  vector<int> ans;
  memset(d, -1, sizeof(d));

  d[root] = 0;

  for(int nxt : adj[root]) {
    if(d[nxt] != -1) continue;
    d[nxt] = 1;
    ans.push_back(dfs(nxt));
  }

  if(ans.size() == 0) return 0;
  sort(ans.rbegin(), ans.rend());
  
  int sum = 0;
  for(int i = 0; i < min(2, (int)ans.size()); i++)
    sum += ans[i];
  return sum >= 4;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  while(m--) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for(int i = 0; i < n; i++) {
    if(!solve(i)) continue;
    cout << 1; return 0;
  }
  cout << 0;
}