#include <bits/stdc++.h>
using namespace std;

int n, m;
int mc[102][102];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  
  for(int i = 0; i < n; i++)
    fill(mc[i], mc[i] + n, 987654321);

  for(int i = 0; i < n; i++) mc[i][i] = 0;

  while(m--) {
    int i, j, cost;
    cin >> i >> j >> cost;
    mc[i-1][j-1] = min(cost, mc[i-1][j-1]);
  }

  for(int k = 0; k < n; k++)
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        mc[i][j] = min(mc[i][j], mc[i][k] + mc[k][j]);

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(mc[i][j] == 987654321) cout << 0 << ' ';
      else cout << mc[i][j] << ' ';
    }
    cout << '\n';
  }
}