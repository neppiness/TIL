#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b;
  cin >> a >> b;
  a = b - a;

  if(a == 0) cout << 0;
  else if(a == b) cout << 1;
  else cout << a << ' ' << b;
}