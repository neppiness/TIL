#include <bits/stdc++.h>
using namespace std;

int a[300'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  if (n == 0) { cout << 0; return 0; }
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);

  // 15 곱하고 100으로 나눌 것.
  int wn = n * 15;
  if (wn % 100 >= 50) {
    wn += 100 - wn % 100;
  } else {
    wn -= wn % 100;
  }
  wn /= 100;

  int tot = 0;
  // 0부터 wn - 1까지는 wn개
  // n - wn부터 n - 1까지는 wn개
  for (int i = 0; i < n; i++)
    if (i >= wn && i < n - wn)
      tot += a[i];

  int no = n - 2*wn;
  long long ans = tot;
  ans *= 1000;
  ans /= no;
  if (ans % 1000 >= 500) {
    ans += 1000 - ans % 1000;
  } else {
    ans -= ans % 1000;
  }
  cout << ans / 1000;
}
