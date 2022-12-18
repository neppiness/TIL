#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int h, m; cin >> h >> m;

  int dm; cin >> dm;
  m += dm;

  int dh = m / 60;
  m %= 60;

  h += dh;
  h %= 24;

  cout << h << ' ' << m;
}