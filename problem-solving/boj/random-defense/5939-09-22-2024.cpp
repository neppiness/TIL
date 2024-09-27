#include <bits/stdc++.h>
using namespace std;

tuple<int, int, int> a[5002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    int h, m, s; cin >> h >> m >> s;
    a[i] = {h, m, s};
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    auto [h, m, s] = a[i];
    cout << h << ' ' << m << ' ' << s << '\n';
  }
}
