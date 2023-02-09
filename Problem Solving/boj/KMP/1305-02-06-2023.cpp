#include <bits/stdc++.h>
using namespace std;

const int MX = 1'000'000;
int f[MX + 2], mx;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; string s;
  cin >> n >> s;

  for(int i = 1; i < n; i++) {
    int j = f[i - 1];
    while(j > 0 && s[i] != s[j]) j = f[j - 1];
    if(s[i] == s[j]) f[i] = ++j;
  }
  cout << n - f[n - 1];
}