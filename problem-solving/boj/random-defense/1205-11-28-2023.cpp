#include <bits/stdc++.h>
using namespace std;

pair<int, bool> a[52];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, score, p;
  cin >> n >> score >> p;
  a[n] = {score, 0};
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    a[i] = {x, 1};
  }

  sort(a, a + n + 1, greater<pair<int, bool>>());
  auto it1 = find(a, a + p, pair<int, bool>(score, 1));
  auto it2 = find(a, a + p, pair<int, bool>(score, 0));

  if (it2 == a + p) {
    cout << -1;
  } else {
    if (it1 == a + p) cout << it2 - a + 1;
    else cout << it1 - a + 1;
  }
}
