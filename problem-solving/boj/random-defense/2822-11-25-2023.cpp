#include <bits/stdc++.h>
using namespace std;

pair<int, int> a[8];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 8; i++) {
    int x; cin >> x;
    a[i] = {x, i + 1};
  }
  sort(a, a + 8, greater<pair<int, int>>());
  int ans[8];
  int tot = 0;
  for (int i = 0; i < 5; i++) {
    auto [score, seq] = a[i];
    tot += score;
    ans[i] = seq;
  }
  sort(ans, ans + 5);
  cout << tot << '\n';
  for (int i = 0; i < 5; i++)
    cout << ans[i] << ' ';
}
