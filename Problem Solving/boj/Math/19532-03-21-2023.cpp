#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  int det = a * e - b * d;
  int X = e * c - b * f;
  int Y = - d * c + a * f;

  cout << X / det << ' ' << Y / det;
}