#include <bits/stdc++.h>
using namespace std;

const int NMX = 2'002; // maximum # of nodes
const int INF = 0x3f3f3f3f;
int dist[2][NMX];

vector<int> sus; // suspective end-point
vector<pair<int, int>> adj[NMX]; // adj[u] = {cost, v};

int n, m, t;
int st, g, h, ghcost;

void init() {
  for(int i = 0; i < 2; i++)
    fill(dist[i], dist[i] + NMX, INF);
  for(int i = 0; i < NMX; i++)
    adj[i].clear();
  sus.clear();

  cin >> n >> m >> t;
  cin >> st >> g >> h;

  while(m--) {
    int u, v, cost;
    cin >> u >> v >> cost;
    if((u == g && v == h) || (u == h && v == g)) {
      ghcost = cost;
      continue;
    }
    adj[u].push_back({cost, v});
    adj[v].push_back({cost, u});
  }
  while(t--) {
    int x; cin >> x;
    sus.push_back(x);
  }
  sort(sus.begin(), sus.end());
}

void adjust() {
  adj[g].push_back({ghcost, h});
  adj[h].push_back({ghcost, g});
}

void res() {
  for(int s : sus) {
    if(dist[0][s] == dist[1][s]) continue;
    cout << s << ' ';
  }
  cout << '\n';
}

void dijk(bool code) {
  priority_queue < pair<int, int>,
      vector<pair<int, int>>,
      greater<pair<int, int>> > pq;
  pq.push({0, st});
  dist[code][st] = 0;

  while(!pq.empty()) {
    auto [co, cur] = pq.top(); pq.pop();
    if(dist[code][cur] != co) continue;
    for(auto [dc, nxt] : adj[cur]) {
      if(dist[code][nxt] <= co + dc) continue;
      dist[code][nxt] = co + dc;
      pq.push({co + dc, nxt});
    }
  }
}

void solve() {
  init();
  dijk(0);
  adjust();
  dijk(1);
  res();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T; cin >> T;
  while(T--) solve();
}