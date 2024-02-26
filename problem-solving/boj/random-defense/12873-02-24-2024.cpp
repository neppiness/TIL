#include <bits/stdc++.h>
using namespace std;

int prv[5002];
int nxt[5002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  memset(prv, -1, sizeof(prv));
  memset(nxt, -1, sizeof(nxt));
  for (int i = 1; i <= n; i++) {
    nxt[i] = i + 1;
    prv[i] = i - 1;
  }
  nxt[n] = 1;
  prv[1] = n;

  int size = n;
  long long t = 1;
  int cur = 1;
  while (size > 1) {
    long long cnt = t * t * t - 1;
    cnt %= size;
    while (cnt--) {
      cur = nxt[cur];
    }
    prv[nxt[cur]] = prv[cur];
    nxt[prv[cur]] = nxt[cur];
    cur = nxt[cur];
    size--;
    t++;
  }
  cout << cur;
}
