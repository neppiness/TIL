#include <bits/stdc++.h>
using namespace std;

int cnt, no, n, m;
stack<int> st;
bool is_fin[100'002];
vector<int> adj[100'002];
int seq[100'002];
int ind[100'002];
int gr[100'002];

void init() {
  memset(is_fin, 0, sizeof(is_fin));
  memset(seq, 0, sizeof(seq));
  memset(ind, 0, sizeof(ind));
  memset(gr, 0, sizeof(gr));

  cnt = no = 0;
  for (int i = 1; i <= n; i++)
    adj[i].clear();

  while (m--) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
  }
}

int scc(int cur) {
  st.push(cur);
  seq[cur] = ++no;

  int ret = seq[cur];
  for (int nxt : adj[cur]) {
    if (!seq[nxt]) ret = min(ret, scc(nxt));
    else if (!is_fin[nxt]) ret = min(ret, seq[nxt]);
  }

  if (ret == seq[cur]) {
    while (1) {
      int s = st.top(); st.pop();
      is_fin[s] = 1;
      gr[s] = cnt;
      if (s == cur) break;
    }
    cnt++;
  }
  return ret;
}

void solve() {
  cin >> n >> m;
  init();
  for (int i = 1; i <= n; i++)
    if (!seq[i]) scc(i);

  for (int cur = 1; cur <= n; cur++) {
    int cgr = gr[cur];
    for (int nxt : adj[cur]) {
      int ngr = gr[nxt];
      if (cgr == ngr) continue;
      ind[gr[nxt]]++;
    }
  }
  
  int ans = 0;
  for (int i = 0; i < cnt; i++)
    ans += (!ind[i]);
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) solve();
}