#include <bits/stdc++.h>
using namespace std;

const int NMX = 100'000;
const int LMX = 17; // (1 << 17) = 131072이며, 17번째 비트는 절대 켜질 수 없음.
const int ROOT = 1;

int n;
int pst[NMX + 2][LMX]; // parent sparse table, 1-indexed.
vector<int> adj[NMX + 2];

void setP(int cur) {
  for(int nxt : adj[cur]) {
    if(pst[cur][0] == nxt) continue;
    pst[nxt][0] = cur;
    setP(nxt);
  }
}

void setTable() {
  for(int lg = 0; lg < LMX - 1; lg++)
    for(int i = 1; i <= n; i++) {
      int cur = pst[i][lg];
      if(cur == -1) continue;
      pst[i][lg + 1] = pst[cur][lg];
    }
}

int move(int cur, int d) { // d만큼 이동 후 위치 반환
  for(int lg = LMX - 1; lg >= 0; lg--) {
    int chk = (1 << lg);
    if(d & chk) cur = pst[cur][lg];
  }
  return cur;
}

int dist(int cur) { // ROOT까지 거리 반환
  int d = 0;
  for(int lg = LMX - 1; lg >= 0; lg--) {
    if(pst[cur][lg] == -1) continue;
    cur = pst[cur][lg];
    d += (1 << lg);
  }
  return d;
}

int find(int u, int v) {
  int du = dist(u), dv = dist(v);
  if(du < dv) swap(u, v);
  int d = max(du, dv) - min(du, dv);
  u = move(u, d);

  d = min(du, dv);
  if(u == v) return u;
  for(int lg = LMX - 1; lg >= 0; lg--) {
    int pu = pst[u][lg], pv = pst[v][lg];
    if(pu == pv) continue; // 공통 조상이면 스킵
    u = pu; v = pv;
  }
  return pst[u][0];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(pst, -1, sizeof(pst));

  cin >> n;
  for(int i = 0; i < n - 1; i++) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  setP(ROOT);
  setTable();

  int m; cin >> m;
  while(m--) {
    int u, v; cin >> u >> v;
    cout << find(u, v) << '\n';
  }
}