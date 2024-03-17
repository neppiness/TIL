#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  int pos = s.find(":");
  int a = stoi(s.substr(0, pos));
  int b = stoi(s.substr(pos + 1));
  cout << a / gcd(a, b) << ":" << b / gcd(a, b);
}
