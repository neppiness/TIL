#include <bits/stdc++.h>
using namespace std;

int n, m;
int cnt;
int par[502];
vector<int> adj[502];

bool check(int r) {
  queue<int> q;
  q.push(r);
  par[r] = 0;
  while(!q.empty()) {
    int cur = q.front(); q.pop();
    for(int nxt : adj[cur]) {
      if(nxt == par[cur]) continue;
      else if(par[nxt] != -1) return false;
      par[nxt] = cur;
      q.push(nxt);
    }
  }
  return true;
}

void solve() {
  cnt++;
  fill(par + 1, par + n + 1, -1);
  
  int t = 0;
  for(int i = 1; i <= n; i++)
    if(par[i] == -1) t += check(i);
  cout << "Case " << cnt << ": ";
  if(t == 0) cout << "No trees.\n";
  else if(t == 1) cout << "There is one tree.\n";
  else cout << "A forest of " << t << " trees.\n";
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  while(n != 0 || m != 0) {
    for(int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    solve();

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
      vector<int>().swap(adj[i]);
  }
}