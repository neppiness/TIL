#include <bits/stdc++.h>
using namespace std;

int n, m;
int ndno, grno;

int seq[20'002], gr[20'002];
bool is_done[20'002];

vector<int> adj[20'002];
stack<int> st;

int rev(int cur) {
  if (cur > n) return cur - n;
  return cur + n;
}

int scc(int cur) {
  st.push(cur);
  seq[cur] = ++ndno;
  
  int ret = seq[cur];
  for (int nxt : adj[cur]) {
    if (seq[nxt] == 0) ret = min(ret, scc(nxt));
    else if (!is_done[nxt]) ret = min(ret, seq[nxt]);
  }

  if (ret == seq[cur]) {
    grno++;
    while (1) {
      int tp = st.top(); st.pop();
      is_done[tp] = 1;
      gr[tp] = grno;
      if (tp == cur) break;
    }
  }
  return ret;
}

bool chk() {
  for (int i = 1; i <= n; i++)
    if (gr[i] == gr[rev(i)]) return 0;
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  while (m--) {
    int u, v; cin >> u >> v;
    if (u < 0) u = -u + n;
    if (v < 0) v = -v + n;
    adj[rev(u)].push_back(v);
    adj[rev(v)].push_back(u);
  }

  for (int i = 1; i <= 2*n; i++)
    if (seq[i] == 0) scc(i);

  cout << chk();
}