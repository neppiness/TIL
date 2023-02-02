#include <bits/stdc++.h>
using namespace std;

const int MX = 1000;

int n, m, p[MX +2];
vector<tuple<int, int, int>> edge;

int find(int x) {
  if(p[x] < 0) return x;
  return p[x] = find(p[x]);
}

void merge(int u, int v) {
  if(p[u] > p[v]) swap(u, v);
  p[u] += p[v];
  p[v] = u;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(p, -1, sizeof(p));

  cin >> n >> m;
  while(m--) {
    int u, v, cost;
    cin >> u >> v >> cost;
    edge.push_back({cost, u, v});
  }
  sort(edge.begin(), edge.end());

  int ans = 0, cnt = 0;
  for(auto [cost, u, v] : edge) {
    int pu = find(u);
    int pv = find(v);
    if(pu == pv) continue;
    merge(pu, pv);
    ans += cost;
    cnt++;
    if(cnt + 1 == n) break;
  }
  cout << ans;
}