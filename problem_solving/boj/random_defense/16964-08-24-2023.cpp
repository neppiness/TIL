#include <bits/stdc++.h>
using namespace std;

int n;
set<int> adj[100'002];
queue<int> seq;

void dfs(int cur) {
  seq.pop();
  while (!seq.empty()) {
    int nxt = seq.front();
    auto pos = adj[cur].find(nxt);
    if (pos == adj[cur].end()) return;
    dfs(nxt);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    adj[u].insert(v);
    adj[v].insert(u);
  }
  
  while (n--) {
    int x; cin >> x;
    seq.push(x);
  }

  if (seq.front() != 1) {
    cout << 0; return 0;
  }

  dfs(1);
  cout << (seq.size() == 0);
}
