#include <bits/stdc++.h>
using namespace std;

int f[42][2];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  f[0][0] = 1; f[0][1] = 0;
  f[1][0] = 0; f[1][1] = 1;
  for(int i = 2; i <= 40; i++){
    for(int j = 0; j <= 1; j++)
      f[i][j] = f[i-1][j] + f[i-2][j];
  }

  int n, x;
  cin >> n;
  while(n--){
    cin >> x;
    cout << f[x][0] << ' ' << f[x][1] << '\n';
  }
}