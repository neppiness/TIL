#include <bits/stdc++.h>
using namespace std;

int n;
int li[100002];
int vis[100002];
bool cycle[100002];

int solve() {
  fill(vis + 1, vis + n + 1, 0);
  fill(cycle + 1, cycle + n + 1, 0);

  int cur, nxt;
  queue<int> q;
  for(int i = 1; i <= n; i++) {
    if(cycle[i] || vis[i]) continue;
    q.push(i);
    vis[i] = i;
    while(!q.empty()) {
      cur = q.front(); q.pop();
      nxt = li[cur];
      if(cycle[nxt] || vis[nxt] != i) continue;
      if(vis[nxt] == i) cycle[nxt] = 1;
      q.push(nxt);
      vis[nxt] = i;
    }
  }
  int cnt = 0;
  for(int i = 1; i <= n; i++)
    if(!cycle[i]) cnt++;
  return cnt;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    cin >> n;
    for(int i = 1; i <= n; i++)
      cin >> li[i];
    cout << solve() << '\n';
  }
}