#include <bits/stdc++.h>
using namespace std;

int a[100'002], sum[100'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] += sum[i - 1] + a[i];
  }

  int ans = 0;
  for (int i = 2; i < n; i++) {
    int tmp = sum[n] - a[1] - a[n] + a[i];
    ans = max(tmp, ans);
  }
  for (int i = 2; i < n; i++) {
    int tmp1 = (sum[n] - a[n]) + (sum[i] - a[i]) - a[i];
    int tmp2 = (sum[n] - a[1]) + (sum[n] - sum[i]) - a[i];
    int tmp = max(tmp1, tmp2);
    ans = max(tmp, ans);
  }
  cout << ans;
}
