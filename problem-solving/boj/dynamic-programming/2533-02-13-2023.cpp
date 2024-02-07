#include <bits/stdc++.h>
using namespace std;

const int ROOT = 1;
const int MX = 1'000'000 + 2;

int n, p[MX], cache[MX][2];
vector<int> adj[MX];

void set_par(int cur) {
  for(int nxt : adj[cur]) {
    if(p[cur] == nxt) continue;
    p[nxt] = cur;
    set_par(nxt);
  }
}

int solve(int cur, bool is_p_ea) {
  int &ret = cache[cur][is_p_ea];
  if(ret != -1) return ret;

  // 1. 자신이 얼리어답터인 경우
  ret = 1;
  for(int nxt : adj[cur]) {
    if(nxt == p[cur]) continue;
    ret += solve(nxt, 1);
  }
  if(!is_p_ea) return ret;

  // 2. 부모가 얼리어답터여서 자신이 얼리어답터가 아니어도 되는 경우
  int tmp = 0;
  for(int nxt : adj[cur]) {
    if(nxt == p[cur]) continue;
    tmp += solve(nxt, 0);
  }
  ret = min(ret, tmp);
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(p, -1, sizeof(p));
  memset(cache, -1, sizeof(cache));

  cin >> n;
  for(int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  set_par(ROOT);
  cout << min(solve(ROOT, 0), solve(ROOT, 1));
}