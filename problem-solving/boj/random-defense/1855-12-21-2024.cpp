#include <bits/stdc++.h>
using namespace std;

char b[202][202];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  string s; cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if ((i / n) % 2) {
      b[i / n][n - 1 - i % n] = s[i];
    } else {
      b[i / n][i % n] = s[i];
    }
  }

  int m = s.size() / n;
  for (int j = 0; j < n; j++)
    for (int i = 0; i < m; i++)
      cout << b[i][j];
}
