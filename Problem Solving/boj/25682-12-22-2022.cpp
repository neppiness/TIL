#include <bits/stdc++.h>
using namespace std;

bool b[2002][2002]; // 1-indexed
int ps[2][2002][2002]; // 1-indexed

int n, m, p;
int mn = 0x7f7f7f7f;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> p;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++) {
      char c; cin >> c;
      b[i][j] = (c == 'B'); // W: 0, B: 1
    }

  for(int k = 0; k < 2; k++)
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= m; j++) {
        bool val = (b[i][j] == ((i + j) % 2 == k));
        ps[k][i][j] = val;
      }

  for(int k = 0; k < 2; k++) {
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= m; j++)
        ps[k][i][j] += ps[k][i][j - 1];
    for(int j = 1; j <= m; j++)
      for(int i = 1; i <= n; i++)
        ps[k][i][j] += ps[k][i - 1][j];
  }

  for(int k = 0; k < 2; k++)
    for(int i = 0; i <= n - p; i++)
      for(int j = 0; j <= m - p; j++) {
        int area = ps[k][i + p][j + p] - ps[k][i + p][j] - ps[k][i][j + p] + ps[k][i][j];
        mn = min(mn, area);
      }

  cout << mn;
}