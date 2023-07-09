#include <bits/stdc++.h>
using namespace std;

int grno, ndno, n, m, s, e;
int seq[10'002], gr[10'002], cnt[10'002], tot[10'002];
bool is_done[10'002];

vector<int> adj[10'002];
vector<int> scc_adj[10'002];

stack<int> st;

int scc(int cur) {
  st.push(cur);
  seq[cur] = ++ndno;

  int ret = seq[cur];
  for (int nxt : adj[cur]) {
    if (!seq[nxt]) ret = min(ret, scc(nxt));
    else if (!is_done[nxt]) ret = min(ret, seq[nxt]);
  }

  if (ret == seq[cur]) {
    grno++;
    while (1) {
      int tp = st.top(); st.pop();
      is_done[tp] = 1;
      gr[tp] = grno;
      cnt[grno]++;
      if (tp == cur) break;
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> s >> e;
  while (m--) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
  }

  scc(s);
  if (seq[e] == 0) { cout << 0; return 0; }
  
  for (int i = 1; i <= n; i++) {
    if (gr[i] == 0) continue;
    for (int j : adj[i]) {
      if (gr[j] == gr[i]) continue;
      scc_adj[gr[i]].push_back(gr[j]);
    }
  }

  priority_queue<pair<int, int>> pq;
  pq.push({cnt[gr[s]], gr[s]});
  tot[gr[s]] = cnt[gr[s]];
  while (!pq.empty()) {
    auto [co, cur] = pq.top(); pq.pop();
    if (tot[cur] != co) continue;
    for (int nxt : scc_adj[cur]) {
      int nco = co + cnt[nxt];
      if (nco <= tot[nxt]) continue;
      tot[nxt] = nco;
      pq.push({nco, nxt});
    }
  }
  cout << tot[gr[e]];
}