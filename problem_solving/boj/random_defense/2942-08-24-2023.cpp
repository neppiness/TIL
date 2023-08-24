#include <bits/stdc++.h>
using namespace std;

set<int> g_set;

int gcd(int a, int b) {
  return a ? gcd(b % a, a) : b;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b; cin >> a >> b;
  int g = gcd(a, b);
  for (int i = 1; i * i <= g; i++) {
    if (g % i) continue;
    g_set.insert(g / i);
    g_set.insert(i);
  }
  for (int s : g_set) {
    cout << s << ' ';
    cout << a / s << ' ';
    cout << b / s << '\n';
  } 
}
