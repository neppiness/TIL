#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) { return a ? gcd(b%a, a) : b; }

int lcm(int a, int b) { return a / gcd(a, b) * b; }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int a, b;
    cin >> a >> b;
    cout << lcm(a, b) << '\n';
  }
}