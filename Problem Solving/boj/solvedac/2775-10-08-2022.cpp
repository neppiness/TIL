#include <bits/stdc++.h>
using namespace std;

long long b[15][15];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int j = 1; j <= 14; j++)
    b[0][j] = j;

  for(int i = 1; i <= 14; i++)
    b[i][1] = 1;

  for(int i = 1; i <= 14; i++)
    for(int j = 2; j <= 14; j++)
      b[i][j] = b[i - 1][j] + b[i][j - 1];

  int t, k, n;
  cin >> t;
  while(t--) {
    cin >> k >> n;
    cout << b[k][n] << '\n';
  }
}