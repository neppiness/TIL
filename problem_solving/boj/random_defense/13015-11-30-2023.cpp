#include <bits/stdc++.h>
using namespace std;

char b[200][400];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 200; i++)
    fill(b[i], b[i] + 400, ' ');

  int n; cin >> n;

  for (int c = 0; c < n; c++) {
    b[n - 1 - c][2*n - 2 - c] = '*';
    b[n - 1 + c][2*n - 2 - c] = '*';
    b[n - 1 - c][n - 1 - c] = '*';
    b[n - 1 + c][n - 1 - c] = '*';
    b[n - 1 - c][2*n - 2 + c] = '*';
    b[n - 1 + c][2*n - 2 + c] = '*';
    b[n - 1 - c][3*n - 3 + c] = '*';
    b[n - 1 + c][3*n - 3 + c] = '*';
  }

  for (int j = 3*n - 3; j < 4*n - 3; j++) {
    b[2*n - 2][j] = '*';
    b[0][j] = '*';
  }

  for (int j = 0; j < n; j++) {
    b[2*n - 2][j] = '*';
    b[0][j] = '*';
  }

  for (int i = 0; i < 2*n - 1; i++) {
    for (int j = 0; j < 3*n - 2 + abs(i - n + 1); j++)
      cout << b[i][j];
    if (i != 2*n - 2) cout << '\n';
  }
}
