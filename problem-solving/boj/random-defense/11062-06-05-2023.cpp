#include <bits/stdc++.h>
using namespace std;

int cache[1002][1002]; // cache[i][j], 0: 근우, 1: 명우
int a[1002];

int calc(int st, int en) {
  int &ret = cache[st][en];
  if (ret != -1) return ret;
  if (st == en) return ret = a[st];
  if (st < en) return 0;

  ret = 0;
  ret = max(ret, a[st] + calc())
}

void solve() {
  memset(cache, -1, sizeof(cache));

  int n; cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  cout << calc(0, n - 1) << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) solve();
}