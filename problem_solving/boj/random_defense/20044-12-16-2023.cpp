#include <bits/stdc++.h>
using namespace std;

int n, a[10002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < 2*n; i++)
    cin >> a[i];
  sort(a, a + 2*n);

  int mn = 200'000;
  for (int i = 0; i < n; i++)
    mn = min(mn, a[i] + a[2*n - 1 - i]);
  cout << mn;
}
