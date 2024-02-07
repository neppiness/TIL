#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7f7f7f7f;

int a[1'000'002];
int dp[1'000'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, 0x7f, sizeof(dp));

  int n; cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int &x = a[i];
    int st = 0, en = n;
    while (st < en) {
      int mid = (st + en) / 2;
      if (dp[mid] < x) st = mid + 1;
      else en = mid;
    }
    dp[st] = x;
    ans = max(ans, st + 1);
  }
  cout << ans;
}
