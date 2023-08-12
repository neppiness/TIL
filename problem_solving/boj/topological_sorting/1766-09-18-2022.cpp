#include <bits/stdc++.h>
using namespace std;

int n, m;
int u, v;
int maxlv;
bool vis[32002];
vector<int> adj[32002];
vector<int> lev[32002];

void tr(int cur, int lv) {
  for(int nxt : adj[cur]) {
    if(vis[nxt]) continue;
    vis[nxt] = 1;
    lev[lv].push_back(nxt);
    maxlv = max(maxlv, lv + 1);
    tr(nxt, lv + 1);
  }
}

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    cin >> u >> v;
    adj[v].push_back(u);
  }

  for(int i = 1; i <= n; i++) {
    maxlv = 1;
    if(vis[i]) continue;
    lev[0].push_back(i);
    vis[i] = 1;
    tr(i, 1);
    for(int lv = maxlv; lv >= 0; lv--) {
      if(lev[lv].empty()) continue;
      sort(lev[lv].begin(), lev[lv].end());
      for(int pr : lev[lv]) cout << pr << ' ';
      vector<int>().swap(lev[lv]);
    }
  }
}