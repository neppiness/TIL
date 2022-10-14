#include <bits/stdc++.h>
using namespace std;

int x[2], y[2], r[2];

void solve() {
  for(int i = 0; i < 2; i++)
    cin >> x[i] >> y[i] >> r[i];
  
  int d1 = (x[0] - x[1])*(x[0] - x[1]) + (y[0] - y[1])*(y[0] - y[1]);
  int d2 = r[0]*r[0] + r[1]*r[1] + 2*r[0]*r[1];
  int d3 = r[0]*r[0] + r[1]*r[1] - 2*r[0]*r[1];

  if(d1 == 0) {
    if(r[0] == r[1]) cout << -1;
    else cout << 0;
  }
  else if(d1 == d2) cout << 1;
  else if(d1 == d3) cout << 1;
  else if(d1 > d2) cout << 0;
  else if(d1 < d2) cout << 2;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    solve();
    cout << '\n';
  }
}