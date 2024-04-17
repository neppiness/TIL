#include <bits/stdc++.h>
using namespace std;

double a[10'000'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cout << fixed;
  cout.precision(3);

  int n; cin >> n;

  for (int i = 0; i < n; i++)
    cin >> a[i];

  sort(a, a + n);
  for (int i = 0; i < 7; i++)
    cout << a[i] << '\n';
}
