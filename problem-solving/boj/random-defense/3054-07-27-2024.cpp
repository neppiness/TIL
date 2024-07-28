#include <bits/stdc++.h>
using namespace std;

char b[5][63];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 5; i++)
    fill(b[i], b[i] + 63, '.');

  string s; cin >> s;
  int n = s.size();

  int lim = 5 + 4 * (n - 1);
  for (int j = 0; j < n; j++)
    b[2][2 + 4 * j] = s[j];

  for (int j = 0; j < n; j++) {
    b[0][4 * j + 2] = '#';
    b[1][4 * j + 1] = '#';
    b[1][4 * j + 3] = '#';
    b[2][4 * j] = '#';
    b[2][4 * j + 4] = '#';
    b[3][4 * j + 1] = '#';
    b[3][4 * j + 3] = '#';
    b[4][4 * j + 2] = '#';
  }

  for (int j = 0; j < n; j++) {
    if (j % 3 != 2) continue;
    b[0][4 * j + 2] = '*';
    b[1][4 * j + 1] = '*';
    b[1][4 * j + 3] = '*';
    b[2][4 * j] = '*';
    b[2][4 * j + 4] = '*';
    b[3][4 * j + 1] = '*';
    b[3][4 * j + 3] = '*';
    b[4][4 * j + 2] = '*';
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5 + 4 * (n - 1); j++) {
      cout << b[i][j];
    }
    cout << '\n';
  }
}
