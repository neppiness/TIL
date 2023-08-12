#include <bits/stdc++.h>
using namespace std;

const int c_to_n = 1e7;

int x, n;
int a[1'000'002];

void solve() {
  sort(a, a + n);
  int st = 0, en = 0;
  for (; st < n; st++) {
    while (en < n && a[st] + a[en] < x) en++;
    if (en == n) break;
    if (st != en && a[st] + a[en] == x) {
      cout << "yes " << a[st] << ' ' << a[en] << '\n';
      return;
    }
  }
  cout << "danger\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (cin >> x) {
    x *= c_to_n;
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    solve();
  }
}