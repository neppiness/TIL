#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int dep_mn = 100'000;
  int arr_mx = 0;
  for (int i = 0; i < n; i++) {
    int a, d; cin >> a >> d;
    dep_mn = min(dep_mn, d);
    arr_mx = max(arr_mx, a);
  }

  int ans = arr_mx - dep_mn;
  if (ans < 0) ans = 0;
  cout << ans;
}
