#include <bits/stdc++.h>
using namespace std;

const int MX = 200;

int p[MX + 2];

int find(int cur) {
  if(p[cur] < 0) return cur;
  return p[cur] = find(p[cur]);
}

void merge(int u, int v) {
  u = find(u); v = find(v);
  if(p[u] < p[v]) swap(u, v);
  p[u] += p[v];
  p[v] = u;
}

bool isdiffgr(int u, int v) {
  u = find(u); v = find(v);
  return u != v;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(p, -1, sizeof(p));

  int n, m;
  cin >> n >> m;
  
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++) {
      bool con; cin >> con;
      if(con && isdiffgr(i, j)) merge(i, j);
    }
  
  int u, v;
  cin >> u;
  while(--m) {
    cin >> v;
    if(!isdiffgr(u, v)) {
      swap(u, v);
      continue;
    }
    cout << "NO";
    return 0;
  }
  cout << "YES";
}