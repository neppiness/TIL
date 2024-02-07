#include <bits/stdc++.h>
using namespace std;

int len;
string s;

string solve(int x) {
  char a[len + 1] = {};
  for (int i = 0; i < len; i++)
    a[i] = s[i];
  int cnt = 0;
  do {
    if (++cnt == x) return string(a);
  } while (next_permutation(a, a + len));
  return "No permutation";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (cin >> s) {
    len = s.length();
    int x; cin >> x;
    cout << s << ' ' << x << " = ";
    cout << solve(x) << '\n';
  }
}