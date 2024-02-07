#include <bits/stdc++.h>
using namespace std;

int n, dp[102];
vector<pair<int, int>> a;

int solve(int idx) {
  int &ret = dp[idx];
  if (ret != -1) return ret;

  ret = 1;
  auto [cw, ch] = a[idx];
  for (int i = idx + 1; i < n; i++) {
    auto [nw, nh] = a[i];
    if (ch > nh) continue;
    ret = max(ret, 1 + solve(i));
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(dp, -1, sizeof(dp));

  cin >> n;
  for (int i = 0; i < n; i++) {
    int w, h; cin >> w >> h;
    a.push_back({min(w, h), max(w, h)});
  }
  sort(a.begin(), a.end());

  int ans = 0;
  for (int i = 0; i < n; i++) 
    ans = max(solve(i), ans);
  cout << ans;
}

