#include <bits/stdc++.h>
using namespace std;

const int MX = 10'000 + 2;
const int ROOT = 1;
int n; // the number of nodes

// the node number is 1-indexed
int val[MX], p[MX];
bool is_used[MX];
vector<int> adj[MX]; // adj[u] = {v1, v2, v3, ...}
int cache[MX][2]; // cache[node_no][pr_used], max size of independent set

void setP(int cur) {
  for(auto nxt : adj[cur]) {
    if(p[cur] == nxt) continue;
    p[nxt] = cur;
    setP(nxt);
  }
}

int solve(int cur, bool is_p_used) {
  int &ret = cache[cur][is_p_used];
  if(ret != -1) return ret;

  ret = 0;
  // 부모노드가 활용이 됐든 안 됐든 주변에 현 노드를 안 쓰는 경우의 최댓값은 구해야 함.
  for(int nxt : adj[cur]) {
    if(nxt == p[cur]) continue;
    ret += solve(nxt, 0);
  }

  if(!is_p_used) {
    int tmp = val[cur];
    for(int nxt : adj[cur]) {
      if(nxt == p[cur]) continue;
      tmp += solve(nxt, 1);
    }
    if(tmp > ret) {
      ret = tmp;
      is_used[cur] = 1;
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(cache, -1, sizeof(cache));

  cin >> n;
  for(int i = 1; i <= n; i++)
    cin >> val[i];
  for(int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  p[ROOT] = -1;
  setP(ROOT);

  cout << solve(ROOT, 0) << '\n';
  for(int i = 1; i <= n; i++)
    if(is_used[i]) cout << i << ' ';
}