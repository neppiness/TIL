#include <bits/stdc++.h>
using namespace std;

int a[100'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++)
    cin >> a[i];

  sort(a, a + m);
  int cnt = 0, t = 0;
  for (int i = 0; i < m; i++) {
    if (t + a[i] > n) break;
    cnt++;
    t += a[i];
  }
  cout << cnt;
}
