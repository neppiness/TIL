#include <bits/stdc++.h>
using namespace std;

int a[200'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);
  
  int x = n / 2;
  int mn = 0, mx = 0;
  for (int i = 0; i < x; i++)
    mn += a[i];
  for (int i = x; i < n; i++)
    mx += a[i];
  cout << mn << ' ' << mx;
}
