#include <bits/stdc++.h>
using namespace std;

const int MX = (1 << 21);

int n;
int val[MX], dp[MX];
long long tot;

int solve(int cur) {
  if (cur > n) return 0;
  int left = cur * 2;
  int right = cur * 2 + 1;

  int &ret = dp[cur];
  if (ret != -1) return ret;
  
  tot += abs(solve(left) - solve(right));
  return ret = max(solve(left), solve(right)) + val[cur];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  n = (1 << (n + 1)) - 1;
  for (int i = 2; i <= n; i++) {
    cin >> val[i];
    tot += val[i];
  }
  memset(dp, -1, sizeof(dp));
  solve(1);
  cout << tot;
}
