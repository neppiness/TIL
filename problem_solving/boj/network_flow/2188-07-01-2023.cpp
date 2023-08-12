#include <bits/stdc++.h>
using namespace std;

int n, m;
int st = 0, en = 401;

// 1~n까지는 소
// n + 1 ~ n + m까지는 축사
vector<int> adj[402];
int cap[402][402], flow[402][402];
int p[402];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int u = 1; u <= n; u++) {
    int x; cin >> x;
    while (x--) {
      int v; cin >> v;
      v += n;
      adj[u].push_back(v);
      adj[v].push_back(u);
      cap[u][v] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    cap[st][i] = 1;
    adj[st].push_back(i);
  }
  for (int i = 1; i <= m; i++) {
    cap[i + n][en] = 1;
    adj[i + n].push_back(en);
  }

  int ans = 0;
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
    ans += df;
  }
  cout << ans;
}