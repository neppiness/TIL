#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b, c; cin >> a >> b >> c;
  c %= 2;
  for (int i = 0; i < c; i++) {
    a = (a^b);
  }
  cout << a;
}
