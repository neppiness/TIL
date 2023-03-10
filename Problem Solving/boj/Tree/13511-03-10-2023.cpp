#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// constant declaration
const int LMX = 17; // 2^17 = 131,072
const int MX = 100'000;
const int ROOT = 1;

// Tree info.
int p[MX + 2][LMX + 2];
ll dist[MX + 2];
int depth[MX + 2];
vector<int> adj[MX + 2]; // adj[cur] = {cost, nxt}

void treeSetup(int cur) {
  for(auto [cost, nxt] : adj[cur]) {
    if(p[cur][0] == nxt) continue;
    p[nxt][0] = cur;
    depth[nxt] = depth[cur] + 1;
    dist[nxt] = dist[cur] + cost; 
  }
}

void cost(int u, int v) {
  int w = lca(u, v);
  // (dist[u] - dist[w]) + (dist[v] - dist[w])를 출력하면 됨
}

void kthnode(int u, int v, int k) {
  int w = lca(u, v);
  // u에서 v로 가기 위한 총 이동 횟수를 tot이라 하자.
  // tot = (depth[u] - depth[w]) + (depth[v] - depth[w])
  // k가 1부터 depth[u] - depth[w]이하인 경우, u부터 w까지 k번 이동하면 됨
  // k가 depth[u] - depth[w] 초과인 경우, v부터 w까지 tot - k번 이동하면 됨
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 1; i < n; i++) {
    int u, v, cost;
    cin >> u >> v >> cost;
    adj[u].push_back({cost, v});
    adj[v].push_back({cost, u});
  }

  treeSetup(ROOT);

  while(m--) {
    int code, u, v;
    cin >> code >> u >> v;
    if(code == 1) {
      cost(u, v);
    } else {
      int k; cin >> k;
      kthnode(u, v, k);
    }
  }
}