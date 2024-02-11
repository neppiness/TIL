#include <bits/stdc++.h>
using namespace std;

int solve() {
  int v, e; cin >> v >> e;
  return 2 + e - v;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--)
    cout << solve() << '\n';
}
