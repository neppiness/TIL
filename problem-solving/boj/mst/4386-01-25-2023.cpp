#include <bits/stdc++.h>
using namespace std;

int p[100];
pair<double, double> st[100];
vector<tuple<double, int, int>> e;

int find(int cur) {
  if(p[cur] < 0) return cur;
  return p[cur] = find(p[cur]);
}

void merge(int u, int v) {
  if(p[u] > p[v]) swap(u, v);
  p[u] += p[v];
  p[v] = u;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cout.precision(2);
  cout << fixed;

  memset(p, -1, sizeof(p));

  int n; cin >> n;
  for(int i = 0; i < n; i++) {
    double x, y; cin >> x >> y;
    st[i] = {x, y};
  }
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      auto [xi, yi] = st[i];
      auto [xj, yj] = st[j];
      double xs = xi - xj;
      double ys = yi - yj;
      xs *= xs; ys *= ys;
      e.push_back({sqrt(xs + ys), i, j});
    }
  }
  sort(e.begin(), e.end());

  int cnt = 0;
  double ans = 0;
  for(auto [dist, u, v] : e) {
    u = find(u); v = find(v);
    if(u == v) continue;
    merge(u, v);
    ans += dist;
    cnt++;
    if(cnt == n - 1) break;
  }
  cout << ans;
}