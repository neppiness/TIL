#include <bits/stdc++.h>
using namespace std;

int a[500'002];

int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cout << fixed;
  cout.precision(9);

  int n; cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  long long sum = 0;
  int cnt = 0;
  
  int x; cin >> x;
  for (int i = 0; i < n; i++) {
    int g = gcd(a[i], x);
    if (g != 1) continue;
    cnt++; sum += a[i];
  }
  cout << sum / (double) cnt;
}

