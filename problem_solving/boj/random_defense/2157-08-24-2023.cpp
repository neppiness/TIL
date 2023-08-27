#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7f7f7f7f;

int n, k, m;
int tot[302][302];
vector<pair<int, int>> adj[302]; // adj[cur] = {po, prv};

int solve(int cur, int no) {
  if (no > k) return - INF;
  if (cur == 1) return 0;

  int &ret = tot[cur][no];
  if (ret != -1) return ret;
  
  ret = - INF;
  for (auto [po, prv] : adj[cur]) 
    ret = max(ret, po + solve(prv, no + 1));
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  memset(tot, -1, sizeof(tot));

  cin >> n >> k >> m;
  while (m--) {
    int u, v, po;
    cin >> u >> v >> po;
    if (u > v) continue;
    adj[v].push_back({po, u});
  }

  cout << solve(n, 1);
}

