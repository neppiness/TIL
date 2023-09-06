#include <bits/stdc++.h>
using namespace std;

int p[52];
priority_queue< tuple<int, int, int>,
    vector<tuple<int, int, int>>,
    greater<tuple<int, int, int>> > pq;

int ctoi(char c) {
  if (c >= 'a') return c - 'a' + 1;
  return c - 'A' + 27;
}

int find(int cur) {
  if (p[cur] < 0) return cur;
  return p[cur] = find(p[cur]);
}

bool tryMerge(int u, int v) {
  u = find(u); v = find(v);
  if (u == v) return 0;
  if (p[u] > p[v]) swap(u, v);
  p[u] += p[v];
  p[v] = u;
  return 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(p, -1, sizeof(p));

  int n; cin >> n;
  int tot = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      char c; cin >> c;
      if (c == '0') continue;
      int co = ctoi(c);
      pq.push({co, i, j});
      tot += co;
    }

  int mst_co = 0;
  while (!pq.empty()) {
    auto [co, u, v] = pq.top(); pq.pop();
    if (tryMerge(u, v)) mst_co += co;
  }

  for (int v = 1; v < n; v++) {
    if (!tryMerge(0, v)) continue;
    cout << -1; return 0;
  }
  cout << tot - mst_co;
}
