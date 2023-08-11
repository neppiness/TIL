#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
ll a[100'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += a[i - 1];
  }
  ll mx = 0;
  for (int i = m; i <= n; i++)
    mx = max(mx, a[i] - a[i - m]);
  cout << mx;
} 
