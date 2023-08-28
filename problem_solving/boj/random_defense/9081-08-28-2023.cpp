#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s; cin >> s;
  char a[s.size()];
  for (int i = 0; i < s.size(); i++)
    a[i] = s[i];
  if (next_permutation(a, a + s.size())) {
    for (int i = 0; i < s.size(); i++)
      cout << a[i];
  } else {
    cout << s;
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) solve();
}
