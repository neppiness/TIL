#include <bits/stdc++.h>
using namespace std;

const int MX = 500;

int a[MX + 2], ind[MX + 2];
bool adj[MX + 2][MX + 2]; // adj[cur][nxt];
vector<int> ans;

void solve() {
  memset(adj, 0, sizeof(adj));
  memset(ind, 0, sizeof(ind));
  ans.clear();

  int n; cin >> n;
  for(int i = 0; i < n; i++)
    cin >> a[i];

  for(int i = 0; i < n; i++)
    for(int j = i + 1; j < n; j++)
      adj[a[i]][a[j]] = 1;
  
  int m; cin >> m;
  while(m--) {
    int u, v; cin >> u >> v;
    adj[u][v] = !adj[u][v];
    adj[v][u] = !adj[v][u];
  }

  for(int ai = 1; ai <= n; ai++) {
    for(int aj = 1; aj <= n; aj++) {
      if(ai == aj) continue;
      ind[aj] += adj[ai][aj];
    }
  }

  queue<int> q;
  for(int ai = 1; ai <= n; ai++)
    if(!ind[ai]) q.push(ai);

  if(q.empty()) {
    cout << "IMPOSSIBLE\n";
    return;
  } else if(q.size() > 1) {
    cout << "?\n";
    return;
  }
  while(!q.empty()) {
    int cur = q.front(); q.pop();
    int cnt = 0;
    ans.push_back(cur);
    for(int nxt = 1; nxt <= n; nxt++) {
      if(cur == nxt) continue;
      if(adj[cur][nxt]) {
        ind[nxt]--;
        if(ind[nxt]) continue;
        q.push(nxt);
        cnt++;
      }
      if(cnt > 1) {
        cout << "?\n";
        return;
      }
    }
  }
  if(ans.size() != n)
    cout << "IMPOSSIBLE\n";
  else for(int i = 0; i < n; i++)
    cout << ans[i] << " \n"[i + 1 == n];
} 

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) solve();
}