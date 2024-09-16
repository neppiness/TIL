#include <bits/stdc++.h>
using namespace std;

int sum[12];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n = 10;
  cin >> sum[0];
  for (int i = 1; i < n; i++) {
    int x; cin >> x;
    sum[i] = sum[i - 1] + x;
  }

  int diff = 100000;
  int ans = -1;
  for (int i = 0; i < n; i++) {
    int temp_diff = abs(sum[i] - 100);
    if (temp_diff > diff) continue;
    diff = temp_diff;
    ans = max(ans, sum[i]);
  }
  cout << ans;
}
