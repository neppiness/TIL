#include <bits/stdc++.h>
using namespace std;

int rev(string &x) {
  int ret = 0;
  for (int i = x.size() - 1; i >= 0; i--) {
    ret *= 10;
    ret += x[i] - '0';
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b; cin >> a >> b;
  string sa = to_string(a);
  string sb = to_string(b);
  int rev_a = rev(sa);
  int rev_b = rev(sb);
  string s_tot = to_string(rev_a + rev_b);
  cout << rev(s_tot);
}
