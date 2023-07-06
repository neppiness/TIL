#include <bits/stdc++.h>
using namespace std;

int n, m, no;

stack<int> st;
vector<int> adj[10'002];
int seq[10'002];
bool is_finished[10'002];

vector<set<int>> ans;

int scc(int cur) {
  seq[cur] = ++no;
  st.push(cur);

  int res = seq[cur];
  for (int nxt : adj[cur]) {
    if (!seq[nxt]) res = min(res, scc(nxt));
    else if (!is_finished[nxt]) res = min(res, seq[nxt]);
  }

  if (res == seq[cur]) {
    set<int> tmp;
    while (1) {
      int s = st.top(); st.pop();
      is_finished[s] = 1;
      tmp.insert(s);
      if (s == cur) break;
    }
    ans.push_back(tmp);
  }
  return res;
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

  sort(ans.begin(), ans.end());

  cout << ans.size() << '\n';
  for (auto a : ans) {
    for (int x : a) cout << x << ' ';
    cout << -1 << '\n';
  }
}