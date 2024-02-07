#include <bits/stdc++.h>
using namespace std;

int ops[1'000'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, k;
  cin >> a >> k;

  memset(ops, -1, sizeof(ops));
  
  queue<int> q;
  q.push(a);
  ops[a] = 0;
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    for (int nxt : {cur + 1, cur * 2}) {
      if (nxt > 1e6) continue;
      if (ops[nxt] != -1) continue;
      ops[nxt] = ops[cur] + 1;
      if (nxt == k) {
        cout << ops[nxt];
        return 0;
      }
      q.push(nxt);
    }
  }
}
