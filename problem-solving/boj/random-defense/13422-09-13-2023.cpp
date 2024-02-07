#include <bits/stdc++.h>
using namespace std;

int a[200'002];

int solve() {
  int n, m, k;
  cin >> n >> m >> k;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i + n] = a[i];
    a[i] += a[i - 1];
  }
  for (int i = n + 1; i <= 2*n; i++) 
    a[i] += a[i - 1];

  if (n == m) 
    return a[n] < k;

  int cnt = 0;
  for (int i = m; i < n + m; i++) {
    int tot = a[i] - a[i - m];
    cnt += tot < k;
  }
  return cnt;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int t; cin >> t;
  while (t--)
    cout << solve() << '\n';
}
