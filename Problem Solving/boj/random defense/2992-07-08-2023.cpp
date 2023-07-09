#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  int sz = s.size();
  char c[sz + 1] = {};
  for (int i = 0; i < sz; i++)
    c[i] = s[i];

  bool is_valid = 0;
  int cnt = 0;

  do {
    if (cnt++ == 0) continue;
    string tmp(c);
    cout << tmp << '\n';
    is_valid = 1;
    break;
  } while (next_permutation(c, c + sz));
  if (!is_valid) cout << 0;
}