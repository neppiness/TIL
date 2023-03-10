#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int ROOT = 1;
const int LMX = 17; // 2^17 = 131,072
const int NMX = 100'000;

int n, m;

vector<pair<int, int>> adj[NMX + 2]; // adj[cur] = {cost, nxt}
int p[NMX + 2][LMX + 2];
int en[NMX + 2]; // given energy for an ant in ith node
ll req[NMX + 2]; // required energy to reach root node from ith node

void treeSetup(int cur) {
  for(auto [co, nxt] : adj[cur]) {
    if(p[cur][0] == nxt) continue;
    p[nxt][0] = cur;
    req[nxt] = req[cur] + co;
    treeSetup(nxt);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(p, -1, sizeof(p));

  cin >> n;
  for(int i = 1; i <= n; i++)
    cin >> en[i];
  
  for(int i = 1; i < n; i++) {
    int u, v, cost;
    cin >> u >> v >> cost;
    adj[u].push_back({cost, v});
    adj[v].push_back({cost, u});
  }

  treeSetup(ROOT);

  for(int j = 1; j < LMX; j++) {
    for(int i = 1; i <= n; i++) {
      int cur = p[i][j - 1];
      if(cur == -1) continue;
      p[i][j] = p[cur][j - 1];
    }
  }

  for(int i = 1; i <= n; i++) {
    int cur = i, e = en[i];
    for(int j = LMX - 1; j >= 0; j--) {
      int pcur = p[cur][j];
      int r = req[cur] - req[pcur];
      if(pcur == -1 || e < r) continue;
      cur = pcur;
      e -= r;
    }
    cout << cur << '\n';
  }
}