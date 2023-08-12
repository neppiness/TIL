#include <bits/stdc++.h>
using namespace std;

long long comb[102][102];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i = 1; i <= 100; i++)
    fill(comb[i], comb[i] + 101, 1);
  
  for(int i = 2; i <= 100; i++)
    for(int j = 1; j < i; j++)
      comb[i][j] = comb[i-1][j] + comb[i-1][j-1];

  int n, m; cin >> n >> m;
  cout << comb[n][m];
}