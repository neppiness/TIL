#include <bits/stdc++.h>
using namespace std;

queue<pair<int, int>> q;
int dist[1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dist, -1, sizeof(dist));

  int a, b;
  cin >> a >> b;
  int n; cin >> n;
  q.push({a, 0});
  dist[a] = 0;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    q.push({x, 1});
    dist[x] = (dist[x] == -1);
  }

  while (!q.empty()) {
    auto [cur, d] = q.front(); q.pop();
    for (int nxt : {cur + 1, cur - 1}) {
      if (nxt < 1 || nxt >= 1000) continue;
      if (dist[nxt] != -1) continue;
      dist[nxt] = d + 1;
      q.push({nxt, d + 1});
    }
  }
  cout << dist[b];
}
