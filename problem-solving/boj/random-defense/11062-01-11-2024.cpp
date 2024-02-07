#include <bits/stdc++.h>
using namespace std;

int n; 
int a[1002];
int dp[1002][1002];

int solve(int st, int en) {
  int &ret = dp[st][en];
  if (ret != -1) return ret;
  if (en - st == 1 || en == st) {
    return ret = max(a[st], a[en]);
  }
  // st를 선택하는 경우: 범위는 st + 1, en
  if (solve(st + 2, en) > solve(st + 1, en - 1)) {
    ret = max(ret, solve(st + 1, en - 1) + a[st]);
  } else {
    ret = max(ret, solve(st + 2, en) + a[st]);
  }

  // en을 선택하는 경우: 범위는 st, en - 1
  if (solve(st + 1, en - 1) > solve(st, en - 2)) {
    ret = max(ret, solve(st, en - 2) + a[en]);
  } else {
    ret = max(ret, solve(st + 1, en - 1) + a[en]);
  }
  
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    cout << solve(0, n - 1) << '\n';
  }
}
