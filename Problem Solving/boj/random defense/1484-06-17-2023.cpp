#include <bits/stdc++.h>
using namespace std;

set<int> ans;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int g; cin >> g;

  for (int i = 1; i * i < g; i++) {
    if (g % i) continue;
    int j = g / i;
    int x = i + j;
    if (x % 2) continue;
    x /= 2;
    ans.insert(x);
  }

  if (!ans.size()) { cout << -1; return 0; }
  for (int x : ans) cout << x << '\n';
}