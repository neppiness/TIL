#include <bits/stdc++.h>
using namespace std;

const int src = 0, sink = 2001;

int n, m;
int cap[2003][2003], flow[2003][2003];
int prv[2003];
vector<int> adj[2003];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int u = 1; u <= n; u++) {
    int no; cin >> no;
    while (no--) {
      int v; cin >> v;
      v += n;
      adj[u].push_back(v);
      adj[v].push_back(u);
      cap[u][v] = 1;
    }
  }

  for (int u = 1; u <= n; u++) {
    cap[src][u] = 1;
    adj[src].push_back(u);
    adj[u].push_back(src);
  }

  for (int u = n + 1; u <= n + m; u++) {
    cap[u][sink] = 1;
    adj[sink].push_back(u);
    adj[u].push_back(sink);
  }

  int tot = 0;
  while (1) {
    memset(prv, -1, sizeof(prv));
    queue<int> q;

    q.push(src);
    prv[src] = -2;

    while (!q.empty() && prv[sink] == -1) {
      int cur = q.front(); q.pop();
      for (int nxt : adj[cur]) {
        if (prv[nxt] != -1) continue;
        if (cap[cur][nxt] - flow[cur][nxt] <= 0) continue;
        prv[nxt] = cur; q.push(nxt);
      }
    }
    if (prv[sink] == -1) break;

    int df = 0x7f7f7f7f;
    for (int cur = sink; cur != src; cur = prv[cur])
      df = min(df, cap[prv[cur]][cur] - flow[prv[cur]][cur]);
    for (int cur = sink; cur != src; cur = prv[cur]) {
      flow[prv[cur]][cur] += df;
      flow[cur][prv[cur]] -= df;
    }
    tot += df;
  }
  cout << tot;
}