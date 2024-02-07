#include <bits/stdc++.h>
using namespace std;

int cache[50000][3];
int ps[50000];
int a[50000];

int n, m, mx;

int solve(int st, int lv) {
  if (lv == 3) return 0;

  int &ret = cache[st][lv];
  if (ret != -1) return ret;

  ret = 0;
  for (int i = st; i < m; i++)
    ret = max(ret, ps[st] + solve(i + mx, lv + 1));
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(cache, -1, sizeof(cache));
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  cin >> mx;

  m = n - mx + 1;
  for (int i = 0; i < mx; i++)
    ps[0] += a[i];

  for (int i = mx; i < n; i++)
    ps[i - mx + 1] = ps[i - mx] + a[i] - a[i - mx];

  int ans = 0;
  for (int i = 0; i < m; i++)
    ans = max(ans, solve(i, 0));

  cout << ans;
}