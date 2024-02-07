#include <bits/stdc++.h>
using namespace std;

int b[102], dist[102];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  int x, y;
  while(n--) {
    cin >> x >> y;
    b[x] = y;
  }
  while(m--) {
    cin >> x >> y;
    b[x] = y;
  }
  fill(dist + 1, dist + 101, -1);

  queue<int> q;
  dist[1] = 0;
  q.push(1);
  int cur, nxt, nnxt;
  while(!q.empty()) {
    cur = q.front(); q.pop();
    for(int dx = 1; dx <= 6; dx++) {
      nxt = cur + dx;
      if(nxt > 100) continue;
      if(dist[nxt] != -1) continue;
      dist[nxt] = dist[cur] + 1;

      if(b[nxt]) {
        nnxt = b[nxt];
        if(dist[nnxt] == -1) {
          dist[nnxt] = dist[nxt];
          q.push(nnxt);
        }
      } else q.push(nxt);
      
      if(dist[100] != -1) {
        cout << dist[100];
        return 0;
      }
    }
  }
}