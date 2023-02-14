#include <bits/stdc++.h>
using namespace std;

const int MX = 10'000 + 2;
const int ROOT = 1;
int n; // the number of nodes

int val[MX], p[MX];
vector<int> adj[MX]; // adj[u] = {v1, v2, v3, ...}
set<int> ans;

bool is_used[MX];

int cache[MX][2]; // cache[node_no][pr_used], max size of independent set

void setP(int cur) {
  for(auto nxt : adj[cur]) {
    if(p[cur] == nxt) continue;
    p[nxt] = cur;
    setP(nxt);
  }
}

void trav(int cur) {
  if(is_used[cur]) {
    if(!is_used[p[cur]]) ans.insert(cur);
    else is_used[cur] = 0;
  }
  for(auto nxt : adj[cur]) {
    if(p[cur] == nxt) continue;
    trav(nxt);
  }
}

int solve(int cur, bool is_p_used) {
  int &ret = cache[cur][is_p_used];
  if(ret != -1) return ret;

  ret = 0;
  for(int nxt : adj[cur]) {
    if(nxt == p[cur]) continue;
    ret += solve(nxt, 0);
  }
  if(is_p_used) return ret;

  int tmp = val[cur];
  for(int nxt : adj[cur]) {
    if(nxt == p[cur]) continue;
    tmp += solve(nxt, 1);
  }
  if(tmp > ret) {
    is_used[cur] = 1;
    ret = tmp;
  }
  return ret = max(tmp, ret);
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
  p[ROOT] = 0;
  setP(ROOT);

  cout << solve(ROOT, 0) << '\n';

  trav(ROOT);
  for(int x : ans) cout << x << ' ';
}