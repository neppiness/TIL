#include <bits/stdc++.h>
using namespace std;

int ps[1'000'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> ps[i];
    ps[i] += ps[i - 1];
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int en = i;
    int st = en - m;
    if (st < 0) st = 0;
    int ac = ps[en] - ps[st];
    ans += ((129 <= ac) && (ac <= 138));
  }
  cout << ans;
}
