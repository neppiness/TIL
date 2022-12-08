#include <bits/stdc++.h>
using namespace std;

const int MX = 200'002;

int dist[MX], cnt[MX];
int n, k;

bool oob(int x) { return (x < 0 || x > MX); }

void solve() {
  cin >> n >> k;

  dist[n] = 0;
  cnt[n] = 1;
  if(n == k) return;

  queue<int> q;
  q.push(n);

  while(!q.empty()) {
    int cx = q.front(); q.pop();
    int nxs[] = {cx - 1, cx + 1, cx * 2};
    for(int d = 0; d < 3; d++) {
      int nx = nxs[d];
      if(oob(nx)) continue;
      if(dist[nx] != -1) {
        if(dist[nx] == dist[cx] + 1)
          cnt[nx] += cnt[cx];
        continue;
      }
      cnt[nx] += cnt[cx];
      dist[nx] = dist[cx] + 1;
      q.push(nx);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  fill(dist, dist + MX, -1);

  solve();
  cout << dist[k] << '\n' << cnt[k];
}