#include <bits/stdc++.h>
using namespace std;

pair<int, int> a[1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    int r = x*x + y*y;
    a[i] = {-r, i + 1};
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    cout << a[i].second << '\n';
  }
}
