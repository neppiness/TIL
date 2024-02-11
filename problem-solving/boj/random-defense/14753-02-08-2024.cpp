#include <bits/stdc++.h>
using namespace std;

int a[10'000];
int ans = -1'234'567'890;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  sort(a, a + n);
  ans = max(ans, a[0] * a[1]);
  ans = max(ans, a[n - 1] * a[n - 2]);
  ans = max(ans, a[0] * a[1] * a[n - 1]);
  ans = max(ans, a[n - 1] * a[n - 2] * a[n - 3]);
  cout << ans;
}
