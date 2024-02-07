#include <bits/stdc++.h>
using namespace std;

vector<int> adj[152];
int dist[152];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dist, -1, sizeof(dist));

  int n, k; cin >> n >> k;
  for (int i = 0; i < n; i++) {
    int j; cin >> j;
    adj[j].push_back(i);
  }
  
  queue<int> q;
  q.push(k);
  dist[k] = 0;
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    if (cur == 0) { cout << dist[0]; return 0; }
    for (int nxt : adj[cur]) {
      if (dist[nxt] != -1) continue;
      dist[nxt] = dist[cur] + 1;
      q.push(nxt);
    }
  }
  cout << -1;
}
