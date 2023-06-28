#include <bits/stdc++.h>
using namespace std;

const int kRoot = 1;
queue<int> q;

int n;
int seq[100'002];
int p[100'002];
vector<int> adj[100'002];

void TreeSetup(int cur) {
  for (int nxt : adj[cur]) {
    if (nxt == p[cur]) continue;
    p[nxt] = cur;
    TreeSetup(nxt);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(seq, -1, sizeof(seq));
  memset(p, -1, sizeof(p));

  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  TreeSetup(1);

  int psq = 1;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    seq[x] = i;
    if (p[x] == -1) continue;
    if (seq[p[x]] == -1 || seq[p[x]] < psq) {
      cout << 0; return 0;
    }
    psq = seq[p[x]];
  }
  cout << 1;
}