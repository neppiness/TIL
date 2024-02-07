#include <bits/stdc++.h>
using namespace std;

int dist[100'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dist, -1, sizeof(dist));

  int a, b, n, m;
  cin >> a >> b >> n >> m;

  dist[n] = 0;
  queue<int> q;
  q.push(n);

  while (!q.empty()) {
    int cur = q.front(); q.pop();
    for (int nxt : {cur + 1, cur - 1, cur + a, cur - a, cur + b, cur - b, cur * a, cur * b}) {
      if (nxt < 0 || nxt > 100'000) continue;
      if (dist[nxt] != -1) continue;
      dist[nxt] = dist[cur] + 1;
      q.push(nxt);
    } 
  }
  cout << dist[m];
}
