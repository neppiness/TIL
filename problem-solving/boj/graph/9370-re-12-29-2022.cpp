#include <bits/stdc++.h>
using namespace std;

const int NMX = 2'002;
const int INF = 0x3f3f3f3f;
vector<int> ans;
vector<pair<int, int>> adj[NMX]; // adj[cur] = {cost, nxt}

int n, dist[3][NMX];
int s, g, h, ghcost;

void init() {
  for(int i = 1; i < NMX; i++)
    adj[i].clear();
  ans.clear();
  for(int i = 0; i < 3; i++)
    fill(dist[i], dist[i] + NMX, INF);
}

void setup() {
  int m, t;
  cin >> n >> m >> t;
  cin >> s >> g >> h;

  while(m--) {
    int u, v, cost;
    cin >> u >> v >> cost;
    adj[u].push_back({cost, v});
    adj[v].push_back({cost, u});
    if(u != g && v != g) continue; 
    if(u != h && v != h) continue; 
    ghcost = cost;
  }

  while(t--) {
    int x; cin >> x;
    ans.push_back(x);
  }
  sort(ans.begin(), ans.end());
}

void dijk(int st, int code) {
  priority_queue< pair<int, int>,
      vector<pair<int, int>>,
      greater<pair<int, int>> > pq; // {cost, curnode}
  dist[code][st] = 0;
  pq.push({0, st});
  while(!pq.empty()) {
    auto [co, cur] = pq.top(); pq.pop();
    if(co != dist[code][cur]) continue;
    for(auto [dco, nxt] : adj[cur]) {
      int cost = co + dco;
      if(dist[code][nxt] <= cost) continue;
      dist[code][nxt] = cost;
      pq.push({cost, nxt});
    }
  }
}

void solve() {
  init();
  setup();
  dijk(s, 0);
  dijk(g, 1);
  dijk(h, 2);

  for(int a : ans) {
    int d1 = dist[0][a]; // 시작점에서 ans중 하나로 가는 거리
    int d2 = dist[1][a] + dist[2][s];
    d2 = min(d2, dist[2][a] + dist[1][s]);
    d2 += ghcost;
    if(d1 == d2) cout << a << ' ';
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) solve();
}
