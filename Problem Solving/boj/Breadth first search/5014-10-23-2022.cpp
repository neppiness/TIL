#include <bits/stdc++.h>
using namespace std;

int f, g, s, u, d;
int dist[1'000'002];

int solve() {
  queue<int> q;
  q.push(s);
  dist[s] = 1;

  int dx[] = {u, -d};
  int cur, nxt;
  while(!q.empty()) {
    cur = q.front(); q.pop();
    for(int dir : dx) {
      nxt = cur + dir;
      if(nxt < 1 || nxt > f) continue;
      if(dist[nxt]) continue;
      dist[nxt] = dist[cur] + 1;
      q.push(nxt);
    }
  }
  return dist[g];
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> f >> s >> g >> u >> d;
  int ans = solve();
  if(ans) cout << ans - 1;
  else cout << "use the stairs";
}