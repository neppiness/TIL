#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int a, b, n;
  cin >> a >> b >> n;

  a %= b;
  for (int i = 1; i < n; i++) {
    a *= 10;
    a %= b;
  }
  cout << a * 10 / b;
}
