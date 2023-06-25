#include <bits/stdc++.h>
using namespace std;

int n, a[1002];

void solve() {
  cin >> n;
  int tot = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    tot += a[i]; a[i] *= n;
  }
  int cnt = 0;
  for (int i = 0; i < n; i++)
    cnt += (a[i] > tot);
  cnt *= 1000000;
  cnt /= n;

  int rest = (cnt % 10);
  cnt -= rest;
  if (rest >= 5) cnt += 10;
  cout << cnt / (double)10000 << "%\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cout.precision(3);
  cout << fixed;

  int t; cin >> t;
  while (t--) solve();
}