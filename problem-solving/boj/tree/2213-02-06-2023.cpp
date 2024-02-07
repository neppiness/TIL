#include <bits/stdc++.h>
using namespace std;

const int MX = 10'000;
const int ROOT = 1;

bool used[MX + 2];
int p[MX + 2];
int val[MX + 2], cache[MX + 2][2]; // cache[node][parent_state];
vector<int> adj[MX + 2];

int n; 

void tr(int cur) {
  for(int nxt : adj[cur]) {
    if(p[nxt]) continue;
    p[nxt] = cur;
    tr(nxt);
  }
}

int solve(int cur, bool pst) {
  int &ret = cache[cur][pst];
  if(ret != -1) return ret;
  ret = 0;
  for(int nxt : adj[cur]) {
    if(nxt == p[cur]) continue;
    ret += solve(nxt, 0);
  }
  if(!pst) {
    int tmp = val[cur];
    for(int nxt : adj[cur]) {
      if(nxt == p[cur]) continue;
      tmp += solve(nxt, 1);
    }
    if(ret < tmp) {
      ret = tmp;
      for(int nxt : adj[cur]) used[nxt] = 0;
      used[cur] = 1;
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
  tr(ROOT);

  cout << solve(ROOT, 0) << '\n';

  for(int i = 1; i <= n; i++)
    if(used[i]) cout << i << ' ';
}