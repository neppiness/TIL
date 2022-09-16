#include <bits/stdc++.h>
using namespace std;

int n, r, q;
vector<int> adj[100'002];

int ans[100'002];
int u, cnt;

int solve(int cur) {
  ans[cur]++;
  for(int nxt : adj[cur]) {
    if(ans[nxt] != 0) continue;
    ans[cur] += solve(nxt);
  }
  return ans[cur];
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> r >> q;
  for(int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  solve(r);

  while(q--) {
    cin >> u;
    cout << ans[u] << '\n';
  }
}