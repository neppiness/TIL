#include <bits/stdc++.h>
using namespace std;

const int MX = 300'002;

int n, k;
int dist[MX];
int par[MX];

int ntoidx(int num) {
  return num + 100000;
}

int solve() {
  queue<int> q;
  q.push(n);
  if(n == k) return 0;

  int cur, nxtidx, next[3];
  while(!q.empty()) {
    cur = q.front(); q.pop();
    next[0] = cur + 1;
    next[1] = cur - 1;
    next[2] = cur*2;
    for(int nxt : next) {
      nxtidx = ntoidx(nxt);
      if(nxtidx > MX || nxtidx < 0) continue;
      if(dist[nxtidx] != -1) continue;

      par[nxtidx] = cur;
      dist[nxtidx] = dist[ntoidx(cur)] + 1;
      q.push(nxt);
      if(nxt == k) return dist[ntoidx(cur)] + 1;
    }
  }
  return 0;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;

  fill(dist, dist + MX, -1);
  dist[ntoidx(n)] = 0;

  cout << solve() << '\n';

  stack<int> st;
  int p, cur = k;
  while(cur != n) {
    st.push(cur);
    cur = par[ntoidx(cur)];
  }

  cout << n << ' ';
  while(!st.empty()) {
    cout << st.top() << ' ';
    st.pop();
  }
}