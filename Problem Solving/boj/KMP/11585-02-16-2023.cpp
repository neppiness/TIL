#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000'000 + 2;

int n, f[MX];
char r[MX], m[MX];

int gcd(int a, int b) {
  if(a == 0) return b;
  return gcd(b % a, a);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++) cin >> r[i];
  for(int i = 0; i < n; i++) cin >> m[i];

  int j = 0;
  for(int i = 1; i < n; i++) {
    while(j > 0 && m[i] != m[j]) j = f[j - 1];
    if(m[i] == m[j]) f[i] = ++j;
  }

  int cnt = 0; j = 0;
  for(int i = 0; i < 2*n - 1; i++) {
    int ci = i;
    if(ci >= n) ci -= n;
    while(j > 0 && r[ci] != m[j]) j = f[j - 1];
    if(r[ci] == m[j]) j++;
    if(j == n) { cnt++; j = f[j - 1]; }
  }
  int g = gcd(cnt, n);
  cout << cnt / g << '/' << n / g;
}