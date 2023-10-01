#include <bits/stdc++.h>
using namespace std;

void solve() {
  vector<int> nodes[100'002];
  vector<pair<int, int>> order;
  vector<pair<int, int>> tmp;

  int n; cin >> n;
  tmp.resize(n);
  for (int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    tmp[i] = {x, y};
  }

  sort(tmp.begin(), tmp.end());
  for (auto [x, y] : tmp)
    nodes[x].push_back(y);

  order.push_back({0, 0});
  int id = 1;
  for (int x = 0; x <= 100'000; x++) {
    if (nodes[x].size() == 0) continue;
    if (order[id - 1].second == nodes[x][0]) {
      for (int i = 0; i < nodes[x].size(); i++)
        order.push_back({x, nodes[x][i]});
      id += nodes[x].size();
    } else {
      for (int i = nodes[x].size() - 1; i >= 0; i--)
        order.push_back({x, nodes[x][i]});
      id += nodes[x].size();
    }
  }

  int m; cin >> m;
  while (m--) {
    int q; cin >> q;
    cout << order[q].first << ' ';
    cout << order[q].second << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) solve();
}
