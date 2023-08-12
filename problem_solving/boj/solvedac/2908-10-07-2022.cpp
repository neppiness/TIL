#include <bits/stdc++.h>
using namespace std;

int rev(string s) {
  int res = 0, p10 = 1;
  for(char c : s) {
    res += (c - '0')*p10;
    p10 *= 10;
  }
  return res;
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string a, b;
  cin >> a >> b;
  int x = rev(a); int y = rev(b);
  cout << max(x, y);
}