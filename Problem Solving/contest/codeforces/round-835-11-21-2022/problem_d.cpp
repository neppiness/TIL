#include <bits/stdc++.h>
using namespace std;

int a[200002];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    fill(a, a + n + 1, 0);
    a[0] = -1;
    a[n] = 1;
    int cnt = 0;

    int x, y; cin >> x;
    for(int i = 1; i < n; i++) {
      cin >> y;
      if(y - x < 0) a[i] = -1;
      else if(y - x > 0) a[i] = 1;
      else a[i] = a[i - 1];
      swap(x, y);
    }

    for(int i = 1; i <= n; i++)
      if(a[i - 1] < a[i]) cnt++;

    if(cnt == 1) cout << "YES" << '\n';
    else cout << "NO" << '\n';
  }
}