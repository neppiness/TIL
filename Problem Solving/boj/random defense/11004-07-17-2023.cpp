#include <bits/stdc++.h>
using namespace std;

int a[5'000'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);
  cout << a[m - 1];
}