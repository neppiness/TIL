#include <bits/stdc++.h>
using namespace std;

int n, m, no, cnt, mxsize;

vector<int> adj[10'002];
int seq[10'002];
int gr[10'002], sz[10'002], ind[10'002];
bool isdone[10'002];

stack<int> st;

int scc(int cur) {
  seq[cur] = ++no;
  st.push(cur);

  int ret = seq[cur];
  for (int nxt : adj[cur]) {
    if (seq[nxt] == 0) ret = min(ret, scc(nxt));
    else if (!isdone[nxt]) ret = min(ret, seq[nxt]);
  }
  if (ret == seq[cur]) {
    while (1) {
      int tp = st.top(); st.pop();
      isdone[tp] = 1;
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
    adj[v].push_back(u);
  }

  for (int i = 1; i <= n; i++)
    if (seq[i] == 0) scc(i);

}