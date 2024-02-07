#include <bits/stdc++.h>
using namespace std;

int n, m, grno, ndno;

vector<int> adj[5002];
int gr[5002], seq[5002], outd[5002];
bool is_done[5002];

stack<int> st;

void init() {
  grno = ndno = 0;
  memset(gr, 0, sizeof(gr));
  memset(seq, 0, sizeof(seq));
  memset(is_done, 0, sizeof(is_done));
  memset(outd, 0, sizeof(outd));
  for (int i = 1; i <= n; i++)
    adj[i].clear();

  cin >> m;
  while (m--) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
  }
}

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
      gr[tp] = grno;
      is_done[tp] = 1;
      if (tp == cur) break;
    }
  }
  return ret;
}

void scc() {
  for (int i = 1; i <= n; i++)
    if (!seq[i]) scc(i);
}

void setup() {
  for (int i = 1; i <= n; i++) {
    for (int j : adj[i]) {
      if (gr[i] == gr[j]) continue;
      outd[gr[i]]++;
    }
  }
}

void check() {
  for (int i = 1; i <= n; i++)
    if (!outd[gr[i]]) cout << i << ' ';
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  while (n != 0) {
    init();
    scc();
    setup();
    check();
    cin >> n;
  }
}