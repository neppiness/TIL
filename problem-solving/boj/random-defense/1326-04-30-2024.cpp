#include <bits/stdc++.h>
using namespace std;

int n; 
int board[10'002];
int dist[10'002];

bool oob(int x) {
  return x <= 0 || x > n;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dist, -1, sizeof(dist));

  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> board[i];
  int st, en; cin >> st >> en;

  queue<int> q;
  dist[st] = 0;
  q.push(st);

  while (!q.empty()) {
    int cur = q.front(); q.pop();
    for (int nxt = cur - board[cur]; !oob(nxt); nxt -= board[cur]) {
      if (dist[nxt] != -1) continue;
      dist[nxt] = dist[cur] + 1;
      q.push(nxt);
    }
    for (int nxt = cur + board[cur]; !oob(nxt); nxt += board[cur]) {
      if (dist[nxt] != -1) continue;
      dist[nxt] = dist[cur] + 1;
      q.push(nxt);
    }
  }
  cout << dist[en];
}
