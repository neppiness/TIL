#include <bits/stdc++.h>
using namespace std;

int a[102][102], b[102][102], c[102][102];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k;
  cin >> n >> m;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> a[i][j];

  cin >> m >> k;
  for(int i = 0; i < m; i++)
    for(int j = 0; j < k; j++)
      cin >> b[i][j];
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < k; j++)
      for(int x = 0; x < m; x++)
        c[i][j] += a[i][x] * b[x][j];

  for(int i = 0; i < n; i++)
    for(int j = 0; j < k; j++)
      cout << c[i][j] << " \n"[j + 1 == k];
}