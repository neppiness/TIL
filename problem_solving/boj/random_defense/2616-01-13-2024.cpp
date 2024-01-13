#include <bits/stdc++.h>
using namespace std;

const int MINF = -10'000'000;

int n, len;
int a[50'002], sum[50'002];
int dp[50'002][4];

int solve(int idx, int no) { // 인자: 시작 인덱스, 선택해야 하는 객차 개수.
  if (no == 0) return 0;
  if (idx > n - len + 1) return MINF;

  int &ret = dp[idx][no];
  if (ret != -1) return ret;

  ret = MINF;
  for (int i = idx; i <= n - len + 1; i++) {
    ret = max(ret, a[i] + solve(i + len, no - 1));
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] += sum[i - 1] + a[i];
  }

  cin >> len;
  for (int i = 1; i <= n - len + 1; i++) {
    a[i] = sum[i + len - 1] - sum[i - 1];
  }

  cout << solve(1, 3);
}
