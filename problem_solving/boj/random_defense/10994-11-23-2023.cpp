#include <bits/stdc++.h>
using namespace std;

int n;
char b[400][400];

void solve(int c, int lv) {
  if (lv == 0) return;

  int len = 2*lv - 2;
  int lb = c - len;
  int ub = c + len;

  for (int i = lb; i <= ub; i++) {
    b[i][lb] = '*';
    b[i][ub] = '*';
  }

  for (int j = lb; j <= ub; j++) {
    b[lb][j] = '*';
    b[ub][j] = '*';
  }
  
  solve(c, lv - 1);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for (int i = 0; i < 4*n - 3; i++)
    for (int j = 0; j < 4*n - 3; j++)
      b[i][j] = ' ';

  solve(2*n - 2, n);
  for (int i = 0; i < 4*n - 3; i++) {
    for (int j = 0; j < 4*n - 3; j++) {
      cout << b[i][j];
    }
    cout << '\n';
  }
}
