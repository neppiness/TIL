#include <bits/stdc++.h>
using namespace std;

const int MX = 200'000;

int n, m, tot;
int p[MX + 2];
vector<tuple<int, int, int>> e;

int find(int x) {
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}

void merge(int u, int v) {
  if(u == v) return;
  if(p[u] > p[v]) swap(u, v);
  p[u] += p[v];
  p[v] = u;
}

void setup() {
  memset(p, -1, sizeof(p));
  e.clear();
  tot = 0;

  int u, v, dist;
  for(int i = 0; i < m; i++) {
    cin >> u >> v >> dist;
    e.push_back({dist, u, v});
    tot += dist;
  }
  sort(e.begin(), e.end());
}

void solve() {
  int mncost = 0, cnt = 0;
  for(auto [dist, u, v] : e) {
    int pu = find(u);
    int pv = find(v);
    if(pu == pv) continue;
    merge(pu, pv);
    mncost += dist;
    cnt++;
    if(cnt == n - 1) break;
  }
  cout << (long long)tot - mncost << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  while(n != 0 && m != 0) {
    setup();
    solve();
    cin >> n >> m;
  }
}