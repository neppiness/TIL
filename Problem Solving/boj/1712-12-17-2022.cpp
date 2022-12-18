#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b, c;
  cin >> a >> b >> c;
  if(c - b <= 0) cout << -1;
  else cout << a / (c - b) + 1;
}