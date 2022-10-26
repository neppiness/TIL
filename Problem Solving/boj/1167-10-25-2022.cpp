#include <bits/stdc++.h>
using namespace std;

const int MX = 100'002;

int ans = 0;
vector<pair<int, int>> adj[MX];
bool vis[MX];
int rel[MX];

int en, co;

void solve(int st, int len) {
  vis[st] = 1;
  for(auto nxt : adj[st]) {
    tie(en, co) = nxt;
    if(vis[en]) continue;
    ans = max(len + co, ans);
    solve(en, len + co);
  }
}

int findleaf() {
  for(int i = 1; i < MX; i++)
    if(rel[i] == 1) return i;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int u, v, cost;
  while(n--) {
    cin >> u >> v;
    while(v != -1) {
      cin >> cost;
      adj[u].push_back({v, cost});
      rel[u]++;
      cin >> v;
    }
  }
  int st = findleaf();
  solve(st, 0);
  cout << ans;
}