#include <bits/stdc++.h>
using namespace std;

int n, m, t;
priority_queue< tuple<int, int, int>, 
    vector<tuple<int, int, int>>,
    greater<tuple<int, int, int>> > pq;

bool is_in_group[10'002];
vector<pair<int, int>> adj[10'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> t;
  while (m--) {
    int u, v, co;
    cin >> u >> v >> co;
    adj[u].push_back({co, v});
    adj[v].push_back({co, u});
  }

  is_in_group[1] = 1;
  for (auto [co, nxt] : adj[1]) 
    pq.push({co, nxt, 1});

  int ans = 0, cnt = 0;
  while (!pq.empty()) {
    auto [co, u, v] = pq.top(); pq.pop();
    if (is_in_group[u] && is_in_group[v]) continue;
    if (is_in_group[v]) swap(u, v); // 항상 v는 그룹에 속하지 않은 노드
    is_in_group[v] = 1;
    ans += co + t * cnt++;
    for (auto [vco, w] : adj[v]) {
      if (is_in_group[w]) continue;
      pq.push({vco, w, v});
    }
  }
  cout << ans;
}
