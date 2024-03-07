#include <bits/stdc++.h>
using namespace std;

vector<int> adj[2002];
bool is_visited[2002];

bool dfs(int cur, int dep) {
  if (dep == 4) return 1;
  for (int nxt : adj[cur]) {
    
  }

  return 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, m;
  cin >> n >> m;

  while (m--) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int i = 0; i < n; i++) {
    memset(is_visited, 0, sizeof(is_visited));
    if (!dfs(i, 0)) continue;
    cout << 1;
    return 0;
  }
  cout << 0;
}
