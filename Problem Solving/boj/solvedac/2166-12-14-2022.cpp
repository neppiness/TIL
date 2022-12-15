#include <bits/stdc++.h>
using namespace std;
using ll = long long;

double solve(int n) {
  double ans = 0;
  ll ix, iy; cin >> ix >> iy;
  ll cx, cy, nx, ny;
  cx = ix; cy = iy;
  while(--n) {
    cin >> nx >> ny;
    ans += (cx * ny - nx * cy)/2.0;
    swap(cx, nx);
    swap(cy, ny);
  }
  ans += (cx * iy - ix * cy)/2.0;
  return abs(ans);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  cout << fixed << setprecision(1) << solve(n);
}