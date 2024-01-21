#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1'000'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, 0x7f, sizeof(dp));
  dp[0] = 0;

  cin >> n;
  int len = 0;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    int st = 0, en = n;
    while (st < en) {
      int mid = (st + en) / 2 + 1;
      if (dp[mid] > x) en = mid - 1;
      else st = mid;
    }
    if (dp[st] < x) {
      dp[st + 1] = x;
      len = max(len, st + 1);
    } else { 
      dp[st] = x;
      len = max(len, st);
    }
  }
  cout << n - len;
}
