#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int h, m, s; cin >> h >> m >> s;
  int ds; cin >> ds;
  int a = h * 3600 + m * 60 + s + ds;
  a %= 86400;
  cout << a / 3600 << ' ' << (a % 3600) / 60 << ' ' << a % 60;
}
