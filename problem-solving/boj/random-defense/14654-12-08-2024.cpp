#include <bits/stdc++.h>
using namespace std;

int ans;
int a[302], b[302];

bool game(int i, int cnt_a, int cnt_b) {
  if (a[i] == b[i]) {
    return cnt_a < cnt_b;
  }
  switch (a[i]) {
    case 1:
      return b[i] == 3;
    case 2:
      return b[i] == 1;
    default:
      return b[i] == 2;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];

  int cnt_a = 0, cnt_b = 0;
  for (int i = 0; i < n; i++) {
    bool is_a_win = game(i, cnt_a, cnt_b);
    cnt_a += is_a_win;
    cnt_b += !is_a_win;
    ans = max(ans, max(cnt_a, cnt_b));
    if (is_a_win) cnt_b = 0;
    else cnt_a = 0;
  }
  cout << ans;
}
