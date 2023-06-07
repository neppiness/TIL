#include <bits/stdc++.h>
using namespace std;

const int kInf = 0x7f7f7f7f;

vector<tuple<int, int, int>> adj[502]; //adj[cur] = {cost, nxt, id};
bool is_used[10002];
int dist[502];

int n, m, st, en;
priority_queue< tuple<int, int, int>,
    vector<tuple<int, int, int>>,
    greater<tuple<int, int, int>> > pq;

void setup() {
  for (int i = 0; i < n; i++) adj[i].clear();
  memset(dist, 0x7f, sizeof(dist));
  memset(is_used, 0, sizeof(is_used));

  st, en; cin >> st >> en;
  for (int id = 0; id < m; id++) {
    int u, v, cost;
    cin >> u >> v >> cost;
    adj[u].push_back({cost, v, id});
    adj[v].push_back({cost, u, id});
  }
}

void solve() {
  dist[st] = 0;
  pq.push({0, 0, m}); // m번 간선은 가상의 간선으로 활용되지 않는다.
  while (!pq.empty()) {
    auto [co, cur, cid] = pq.top(); pq.pop();
    if (dist[cur] != co) continue;
    for (auto [dco, nxt, nid] : adj[cur]) {

    }
  }

}

void trace() {

}

void solve2() {

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  while (n != 0 || m != 0) {
    setup();
    solve();
    trace();
    solve2();
    cin >> n >> m;
  }
}
/*
pq는 모든 값이 빠질 때까지 다익스트라를 돌리기 때문에 초기화를 따로 하지 않는다.
*/