#include <bits/stdc++.h>
using namespace std;

int inc(int x) {
  x++;
  if (x > 25) return 1;
  return x;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  cin.ignore();
  string s; getline(cin, s);
  n--;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] < 'a' || s[i] > 'z') {
      cout << s[i];
      continue;
    }
    n = inc(n);
    s[i] -= n;
    if (s[i] < 'a') {
      s[i] = s[i] + 'z' - 'a' + 1;
    }
    cout << s[i];
  }
}
