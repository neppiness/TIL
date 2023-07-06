#include <bits/stdc++.h>
using namespace std;

int n, m, gcnt, no;
int seq[100'002], gr[100'002], ind[100'002];
bool is_done[100'002];
vector<int> adj[100'002];
stack<int> st;

int scc(int cur) {
  st.push(cur); seq[cur] = ++no;
  int ret = seq[cur];
  for (int nxt : adj[cur]) {
    if (!seq[nxt]) ret = min(ret, scc(nxt));
    else if (!is_done[nxt]) ret = min(ret, seq[nxt]);
  }

  if (ret == seq[cur]) {
    gcnt++;
    while (1) {
      int tp = st.top(); st.pop();
      is_done[tp] = 1;
      gr[tp] = gcnt;
      if (tp == cur) break;
    }
  }
  return ret;
}

void solve() {
  for (int i = 0; i < n; i++)
    if (!seq[i]) scc(i);
  for (int cur = 0; cur < n; cur++) {
    for (int nxt : adj[cur]) {
      if (gr[nxt] == gr[cur]) continue;
      ind[gr[nxt]]++;
    }
  }
  int tmpg = -1;
  for (int g = 1; g <= gcnt; g++) {
    if (ind[g] == 0) {
      if (tmpg != -1) { cout << "Confused\n"; return; }
      tmpg = g;
    }
  }
  for (int i = 0; i < n; i++) {
    if (gr[i] != tmpg) continue;
    cout << i << '\n';
  }
}

void init() {
  gcnt = no = 0;
  memset(seq, 0, sizeof(seq));
  memset(gr, 0, sizeof(gr));
  memset(ind, 0, sizeof(ind));
  memset(is_done, 0, sizeof(is_done));

  cin >> n >> m;
  for (int i = 0; i < n; i++)
    adj[i].clear();
  
  while (m--) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    init();
    solve();
    cout << '\n';
  }
}