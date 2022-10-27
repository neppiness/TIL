#include <bits/stdc++.h>
using namespace std;

int n, m;
int b[102][102];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m;
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> b[i][j];

  int d;

  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++) {
      cin >> d;
      b[i][j] += d;
    }

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++)
      cout << b[i][j] << ' '; 
    cout << '\n';
  }
}