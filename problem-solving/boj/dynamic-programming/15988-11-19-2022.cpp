#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MX = 1'000'000;
const int D = 1'000'000'009;

ll ans[1'000'002];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ans[1] = 1;
  ans[2] = 2;
  ans[3] = 4;
  for(int i = 4; i <= MX; i++) {
    ans[i] = ans[i-1] % D + ans[i-2] % D + ans[i-3] % D;
    ans[i] %= D;
  }
  
  int t; cin >> t;
  int x;
  while(t--) {
    cin >> x;
    cout << ans[x] << '\n';
  }
}