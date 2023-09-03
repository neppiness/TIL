#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adj[100'002];
pair<int, int> coord[100'002];
int dist[100'002][2];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int no = 1; no <= n; no++) {
    int x, y; cin >> x >> y;
    coord[no] = {x, y};
  }

  for (int no = 1; no <= n; no++) {
    for (int nno : {no + 1, no + 2}) {
      if (nno > n) continue;
      int d1 = abs(coord[no].first - coord[nno].first);
      int d2 = abs(coord[no].second - coord[nno].second);
      int dist = d1 + d2;
      adj[no].push_back({dist, nno});
    }
  }

  memset(dist, 0x3f, sizeof(dist));

  dist[1][0] = 0;
  queue<pair<int, bool>> q;
  q.push({1, 0});

  while (!q.empty()) {
    auto [cur, skip_used] = q.front(); q.pop();
    int d = dist[cur][skip_used];
    for (auto [dd, nxt] : adj[cur]) {
      bool is_skip = (nxt - cur == 2);
      if (is_skip && skip_used) continue;

      bool skip_st = is_skip || skip_used;
      if (dist[nxt][skip_st] <= dd + d) continue;
      dist[nxt][skip_st] = dd + d;
      q.push({nxt, skip_st});
    }
  }
  int ans = min(dist[n][0], dist[n][1]);
  cout << ans;
}
