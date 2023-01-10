#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) { return (a ? gcd(b % a, a) : b); }

int lcm(int a, int b) { return (a / gcd(a, b) * b); }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b, c, d;
  cin >> a >> b >> c >> d;

  int l = lcm(b, d);
  a = l / b * a;
  c = l / d * c;
  int sum = a + c;
  int g = gcd(l, sum);
  cout << sum / g << ' ' << l / g;
}