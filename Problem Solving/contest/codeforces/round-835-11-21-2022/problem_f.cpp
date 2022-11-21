#include <bits/stdc++.h>
using namespace std;

int a[200'002];

void solve() {
  int n, c, d;
  cin >> n >> c >> d;

  for(int i = 0; i < n; i++) cin >> a[i];

  sort(a, a + n, greater<int>());

  int mxcn = 0;
  for(int i = 0; i < min(n, d); i++)
    mxcn += a[i];

  if(c / a[0] > d) {cout << "Impossible" << '\n'; return;}
  if(mxcn > c) {cout << "Infinity" << '\n'; return;}

  int mk = 0;
  for(int k = 0; k <= d; k++) {
    mxcn = 0;
    for(int i = 0; i <= min(n - 1, k); i++)
      mxcn += a[i];
    
    c -= mxcn * (d/(k + 1));

    int rest;
    for(int i = 0; i < d % (k + 1); i++)
      rest += a[i];
    if(c > 0) return;
    else mk = max(mk, k);
  }

}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) solve();
}