#include <bits/stdc++.h>
using namespace std;

int n, m, grno, ndno;

bool is_done[10'002];
int seq[10'002], gr[10'002]; // for nodes
int ind[10'002], coms[10'002]; // for sccs

vector<int> adj[10'002], scc_adj[10'002];
stack<int> st;

int scc(int cur) {
  seq[cur] = ++ndno;
  st.push(cur);

  int ret = seq[cur];
  for (int nxt : adj[cur])
    if (!seq[nxt]) ret = min(ret, scc(nxt));
    else if (!is_done[nxt]) ret = min(ret, seq[nxt]);

  if (ret == seq[cur]) {
    grno++;
    while (1) {
      int tp = st.top(); st.pop();
      gr[tp] = grno;
      is_done[tp] = 1;
      if (tp == cur) break;
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  while (m--) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
  }

  for (int i = 1; i <= n; i++)
    if (!seq[i]) scc(i);

  for (int i = 1; i <= n; i++) {
    coms[gr[i]]++;
    for (int j : adj[i]) {
      if (gr[i] == gr[j]) continue;
      scc_adj[gr[i]].push_back(gr[j]);
      ind[gr[j]]++;
    }
  }

  queue<int> q;
  for (int i = 1; i <= grno; i++)
    if (ind[i] == 0) q.push(i);

  int mx = 0;
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    for (int nxt : scc_adj[cur]) {
      coms[nxt] += coms[cur];
      ind[nxt]--;
      if (ind[nxt] == 0) q.push(nxt);
    }
  }

  for (int i = 1; i <= grno; i++)
    mx = max(mx, coms[i]);

  for (int i = 1; i <= n; i++)
    if (coms[gr[i]] == mx) cout << i << ' ';
}