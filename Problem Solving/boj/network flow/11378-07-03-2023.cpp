#include <bits/stdc++.h>
using namespace std;

const int src = 0, sink = 2001;

int n, m, k;
vector<int> adj[1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int u = 1; u <= n; u++) {
    int no; cin >> no;
    while (no--) {
      int v; cin >> v;
      v += n;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
  }

  for (int v = 1; v <= n; v++)
    adj[src].push_back(v);
  for (int u = n + 1; u <= n + m; u++)
    adj[u].push_back(sink);

  
}