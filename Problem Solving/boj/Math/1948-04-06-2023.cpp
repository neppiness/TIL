#include <bits/stdc++.h>
using namespace std;

const int MX = 10'000;
const int INF = 0x7f7f7f7f;

int n, m, st, en;
// 시작 도시와 도착 도시에서부터 해당 도시까지의 {거리, 지나는 길의 수}
pair<int, int> d_st[MX + 2];
pair<int, int> d_en[MX + 2];

// adj[cur], inv_adj[cur] = {cost, nxt}
vector<pair<int, int>> adj[MX + 2];
vector<pair<int, int>> inv_adj[MX + 2];

// pq = {cost, no_of_paths, nxt}
priority_queue< tuple<int, int, int>,
    vector<tuple<int, int, int>>,
    greater<tuple<int, int, int>> > pq;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(d_st, 0x7f, sizeof(d_st));
  memset(d_en, 0x7f, sizeof(d_en));
  
  cin >> n >> m;
  while(m--) {
    int u, v, co; cin >> u >> v >> co;
    adj[u].push_back({co, v});
    inv_adj[v].push_back({co, u});
  }
  cin >> st >> en;
  d_st[st] = {0, 0}; d_en[en] = {0, 0};

  pq.push({0, 0, st});
  while(!pq.empty()) {
    auto [co, pa, cur] = pq.top(); pq.pop();
    if(d_st[cur] != pair<int, int>(co, pa)) continue;
    for(auto [dco, nxt] : adj[cur]) {
      dco += co;
      if(pair<int, int>(dco, pa + 1) >= d_st[nxt]) continue;
      d_st[nxt] = {dco, pa + 1};
      pq.push({dco, pa + 1, nxt});
    }
  }

  pq.push({0, 0, en});
  while(!pq.empty()) {
    auto [co, pa, cur] = pq.top(); pq.pop();
    if(d_en[cur] != pair<int, int>(co, pa)) continue;
    for(auto [dco, nxt] : inv_adj[cur]) {
      dco += co;
      if(pair<int, int>(dco, pa + 1) >= d_en[nxt]) continue;
      d_en[nxt] = {dco, pa + 1};
      pq.push({dco, pa + 1, nxt});
    }
  }

  int mx_co = 0;
  for(int i = 1; i <= n; i++) {
    int tmp_co = d_st[i].first + d_en[i].first;
    mx_co = max(mx_co, tmp_co);
  }

  int pas = 0;
  for(int i = 1; i <= n; i++) {
    int tmp_co = d_st[i].first + d_en[i].first;
    if(mx_co != tmp_co) continue;
    pas += d_st[i].second + d_en[i].second;
  }
  cout << mx_co << '\n' << pas;
}