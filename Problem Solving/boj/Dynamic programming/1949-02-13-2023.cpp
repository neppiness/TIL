#include <bits/stdc++.h>
using namespace std;

const int MX = 10'000 + 2;
const int ROOT = 1;

int n, p[MX], pop[MX];
int cache[MX][2]; // cache[node_number][is_par_model_town];
vector<int> adj[MX]; // adj[u] = {v1, v2, v3, ...};

void set_par(int cur) {
  for(int nxt : adj[cur]) {
    if(nxt == p[cur]) continue;
    p[nxt] = cur;
    set_par(nxt);
  }
}

int solve(int cur, bool is_par_sel) {
  int &ret = cache[cur][is_par_sel];
  if(ret != -1) return ret;

  // 1. 현재 노드가 우수 마을이 아닌 경우
  ret = 0;
  for(int nxt : adj[cur]) {
    if(nxt == p[cur]) continue;
    ret += solve(nxt, 0);
  }
  if(is_par_sel) return ret;
  
  // 2. 현재 노드가 우수 마을일 경우
  int tmp = pop[cur];
  for(int nxt : adj[cur]) {
    if(nxt == p[cur]) continue;
    tmp += solve(nxt, 1);
  }
  return ret = max(ret, tmp);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(cache, -1, sizeof(cache));

  cin >> n;
  for(int i = 1; i <= n; i++)
    cin >> pop[i];
  while(--n) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  p[ROOT] = -1;
  set_par(ROOT);

  cout << max(solve(ROOT, 0), solve(ROOT, 1));
}