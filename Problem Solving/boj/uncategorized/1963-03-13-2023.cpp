#include <bits/stdc++.h>
using namespace std;

const int MX = 10'000;

bool is_pr[MX];
int dist[MX];
vector<int> adj[MX];


bool oob(int x) { return (x >= 10000 || x < 1000); }

void setPrime() {
  fill(is_pr + 2, is_pr + MX, 1);
  for(int i = 2; i < MX; i++) {
    if(!is_pr[i]) continue;
    for(int j = i; i*j < MX; j++)
      is_pr[i*j] = 0;
  }
}

void setAdj() {
  for(int cur = 1000; cur < MX; cur++) {
    if(!is_pr[cur]) continue;
    int tmp = cur;
    for(int i = 1; i < MX; i *= 10) {
      int no = tmp % 10;
      tmp /= 10;
      for(int j = 0; j < 10; j++) {
        if(j - no == 0) continue;
        int nxt = cur + i*(j - no);
        if(oob(nxt) || !is_pr[nxt]) continue;
        adj[cur].push_back(nxt);
      }
    }
  }
}

int solve() {
  memset(dist, -1, sizeof(dist));
  queue<int> q;

  int st, en; cin >> st >> en;
  q.push(st);
  dist[st] = 0;

  while(!q.empty()) {
    int cur = q.front(); q.pop();
    if(cur == en) return dist[en];
    for(int nxt : adj[cur]) {
      if(dist[nxt] != -1) continue;
      dist[nxt] = dist[cur] + 1;
      q.push(nxt);
    }
  }
  return -1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  setPrime();
  setAdj();

  int t; cin >> t;
  while(t--) {
    int ans = solve();
    if(ans == -1) cout << "Impossible\n";
    else cout << ans << '\n';
  }
}