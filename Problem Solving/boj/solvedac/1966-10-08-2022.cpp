#include <bits/stdc++.h>
using namespace std;

int imp[10];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  queue<int> q;
  queue<bool> chk;

  int t; cin >> t;

  while(t--) {
    int n, m;
    cin >> n >> m;

    int x;
    for(int i = 0; i < n; i++) {
      cin >> x;
      q.push(x);
      imp[x]++;
      chk.push((i == m));
    }
    int ans, cnt = 0;
    while(!q.empty()) {
      int cur = q.front(); q.pop();
      bool st = chk.front(); chk.pop();

      int i;
      for(i = cur + 1; i < 10; i++)
        if(imp[i]) break;
      if(i == 10) {
        imp[cur]--;
        cnt++;
        if(st) ans = cnt;
      } else {
        q.push(cur);
        chk.push(st);
      }
    }
    cout << ans << '\n';

    fill(imp, imp + 10, 0);
  }
}