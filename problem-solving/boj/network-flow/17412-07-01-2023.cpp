#include <bits/stdc++.h>
using namespace std;

int n, m, st = 1, en = 2;

set<int> adj[402];
int cap[402][402], flow[402][402];
int p[402];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  while (m--) {
    int u, v; cin >> u >> v;
    adj[u].insert(v); adj[v].insert(u);
    cap[u][v]++;
  }

  int totflow = 0;
  while (1) {
    queue<int> q;
    memset(p, -1, sizeof(p));
    p[st] = -2; q.push(st);
    while (!q.empty() && p[en] == -1) {
      int cur = q.front(); q.pop();
      for (int nxt : adj[cur]) {
        if (p[nxt] != -1) continue;
        if (cap[cur][nxt] - flow[cur][nxt] <= 0) continue;
        p[nxt] = cur; q.push(nxt);
      }
    }
    if (p[en] == -1) break;

    int df = 0x7f7f7f7f;
    for (int cur = en; cur != st; cur = p[cur])
      df = min(df, cap[p[cur]][cur] - flow[p[cur]][cur]);

    for (int cur = en; cur != st; cur = p[cur]) {
      flow[p[cur]][cur] += df;
      flow[cur][p[cur]] -= df;
    }
    totflow += df;
  }
  cout << totflow;
}