#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll a[53];
int n, ans;

bool solve(int x1, int x2) {
  if (x1 > x2) swap(x1, x2);
  ll y1 = a[x1]; ll y2 = a[x2];
  double slope = (y1 - y2) / (double)(x1 - x2);
  for (int i = x1 + 1; i < x2; i++) {
    double y = slope * (i - x1) + y1;
    if (y <= a[i]) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      cnt += solve(i, j);
    }
    ans = max(ans, cnt);
  }
  cout << ans;
}