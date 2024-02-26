#include <bits/stdc++.h>
using namespace std;

double mx[102];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k;
  cin >> n >> m >> k;

  cout << fixed;
  cout.precision(1);

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      int x; double sc;
      cin >> x >> sc;
      mx[x] = max(mx[x], sc);
    }
  }

  sort(mx + 1, mx + n + 1, greater<double>());
  double sum = 0;
  for (int i = 1; i <= k; i++)
    sum += mx[i];
  cout << sum;
}
