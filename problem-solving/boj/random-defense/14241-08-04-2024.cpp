#include <bits/stdc++.h>
using namespace std;

int ans = 0;
int a[102];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);

  for (int i = n; i >= 1; i--) {
    ans += a[i] * a[i - 1];
    a[i - 1] = a[i] + a[i - 1];
  }
  cout << ans;
}
