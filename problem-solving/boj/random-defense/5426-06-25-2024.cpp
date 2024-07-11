#include <bits/stdc++.h>
using namespace std;

char a[102][102];
char b[102][102];

void solve() {
  string s; cin >> s;
  int n = sqrt(s.size());

  int cnt = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      a[i][j] = s[cnt++];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      b[n - 1 - j][i] = a[i][j];

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cout << b[i][j];
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) solve();
}
