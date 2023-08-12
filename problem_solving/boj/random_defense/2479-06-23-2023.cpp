#include <bits/stdc++.h>
using namespace std;

int n, k, st, en;

int prv[1002];
string code[1002];
vector<int> adj[1002];
queue<int> q;

void trace(int cur) {
  if (prv[cur]) trace(prv[cur]);
  cout << cur << ' ';
}

void genEdge(int u, int v) {
  int cnt = 0;
  for (int i = 0; i < k; i++)
    cnt += (code[u][i] != code[v][i]);
  if (cnt != 1) return;
  adj[u].push_back(v);
  adj[v].push_back(u);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(prv, -1, sizeof(prv));

  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> code[i];
  cin >> st >> en;

  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      genEdge(i, j);

  q.push(st); prv[st] = 0;
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    for (int nxt : adj[cur]) {
      if (prv[nxt] != -1) continue;
      prv[nxt] = cur;
      q.push(nxt);
    }
  }

  if (prv[en] == -1) cout << -1;
  else trace(en);
}