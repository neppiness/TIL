#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
ll all_co, tot;

int p[100'002];

priority_queue< tuple<ll, int, int>,
    vector<tuple<ll, int, int>>,
    greater<tuple<ll, int, int>> > pq; // pq = {cost, u, v}

int find(int x) {
  if (p[x] < 0) return x;
  return p[x] = find(p[x]);
}

bool try_merge(int u, int v) {
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

  cin >> n >> m;
  while (m--) {
    int u, v; ll cost;
    cin >> u >> v >> cost;
    pq.push({cost, u, v});
    all_co += cost;
  }

  int cnt = 0;
  while (!pq.empty()) {
    auto [co, u, v] = pq.top(); pq.pop();
    if (!try_merge(u, v)) continue;
    cnt++;
    tot += co;
    if (cnt == n - 1) break;
  }

  int u = 1;
  for (int v = 2; v <= n; v++) {
    if (!try_merge(u, v)) continue;
    cout << -1; return 0;
  }
  cout << all_co - tot;
}