#include <bits/stdc++.h>
using namespace std;

const int MX = 250002;
int n, k;
bool vis[MX];
int d[] = {1, -1};
queue<int> q1, q2;

int solve() {
  int cur, cnt = 0;
  q1.push(n);
  while(1) {
    while(!q1.empty()) {
      cur = q1.front(); q1.pop();
      do {
        if(cur == k) return cnt;
        vis[cur] = 1;
        q2.push(cur);
        cur *= 2;
      } while(cur > 0 && cur < MX);
    }
    cnt++;
    while(!q2.empty()) {
      cur = q2.front(); q2.pop();
      for(int dir = 0; dir < 2; dir++) {
        int nxt = cur + d[dir];
        if(vis[nxt]) continue;
        if(nxt > MX || nxt < 0) continue;
        if(nxt == k) return cnt;
        vis[nxt] = 1;
        q1.push(nxt);
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  cout << solve();
}