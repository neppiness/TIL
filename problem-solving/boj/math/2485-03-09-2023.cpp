#include <bits/stdc++.h>
using namespace std;

const int MX = 100'000;
int a[MX + 2];
int gcd(int a, int b) { return (a ? gcd(b % a, a) : b); }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for(int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a + n);

  for(int i = 1; i < n; i++)
    a[i - 1] = a[i] - a[i - 1];
  
  int g = a[0];
  for(int i = 1; i < n - 1; i++)
    g = gcd(g, a[i]);

  int ans = 0;
  for(int i = 0; i < n - 1; i++)
    ans += (a[i] / g) - 1;
  cout << ans;
}