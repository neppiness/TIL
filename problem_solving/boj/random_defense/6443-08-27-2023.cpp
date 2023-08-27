#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s; cin >> s;
  vector<char> c(s.size());
  for (int i = 0; i < s.size(); i++)
    c[i] = s[i];

  sort(c.begin(), c.end());
  do {
    for (char x : c) cout << x;
    cout << '\n';
  } while (next_permutation(c.begin(), c.end()));
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) solve();
}
