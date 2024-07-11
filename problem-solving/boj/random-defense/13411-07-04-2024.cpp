#include <bits/stdc++.h>
using namespace std;

pair<double, int> d[100'002];
int r[100'002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    int x, y, v; cin >> x >> y >> v;
    d[i] = {sqrt(x * x + y * y) / v, i};
  }
  sort(d + 1, d + n + 1);

  for (int i = 1; i <= n; i++)
    r[i] = d[i].second;

  for (int i = 1; i <= n; i++)
    cout << r[i] << '\n';
}
