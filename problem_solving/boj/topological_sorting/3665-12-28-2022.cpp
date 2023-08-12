#include <bits/stdc++.h>
using namespace std;

const int NMX = 502;

int n;
int ind[NMX];
bool adj[NMX][NMX]; // adj[u][v] = disconnected / connected
bool vis[NMX];

queue<int> q;
vector<int> ans;

void trav(int cur) {
  if(!ind[cur]) {
    ans.push_back(cur);
    vis[cur] = 1;
  }
  for(int nxt = 1; nxt <= n; nxt++) {
    if(!adj[cur][nxt]) continue;
    if(vis[nxt]) continue;
    ind[nxt]--;
    if(ind[nxt]) continue;
    trav(nxt);
  }
}

void solve() {
  fill(ind, ind + NMX, 0);
  for(int i = 1; i < NMX; i++)
    fill(adj[i], adj[i] + NMX, 0);
  fill(vis, vis + NMX, 0);

  ans.clear();

  cin >> n;
  int x, y;
  cin >> x;
  q.push(x);
  for(int i = 1; i < n; i++) {
    cin >> y;
    adj[x][y] = 1;
    ind[y]++;
    q.push(y);
    swap(x, y);
  }

  int m; cin >> m;
  bool isimpossible = 0;
  while(m--) {
    int u, v;
    cin >> u >> v;
    ind[v]++;
    if(adj[u][v]) isimpossible = 1;
    adj[u][v] = 1;
  }
  if(isimpossible) {
    cout << "IMPOSSIBLE\n";
    return;
  }

  while(!q.empty()) {
    int cur = q.front(); q.pop();
    if(vis[cur]) continue;
    trav(cur);
  }

  if(ans.size() != n) cout << "?";
  else for(int x : ans) cout << x << ' ';
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) solve();
}
