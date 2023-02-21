#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000'000 + 2;

int n;
char input[MX];

vector<int> failure(string &s) {
  vector<int> f(s.size());
  int j = 0;
  for(int i = 1; i < n; i++) {
    while(j > 0 && s[i] != s[j]) j = f[j - 1];
    if(s[i] == s[j]) f[i] = ++j;
  }
  return f;
}

int gcd(int a, int b) {
  if(a == 0) return b;
  return gcd(b % a, a);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++) cin >> input[i];
  string r(input);
  for(int i = 0; i < n; i++) cin >> input[i];
  string m(input);

  vector<int> f = failure(m);
  int cnt = 0, j = 0;
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