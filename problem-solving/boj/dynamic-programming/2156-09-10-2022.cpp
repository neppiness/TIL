#include <bits/stdc++.h>
using namespace std;

int n;
int wine[10002];
int drink[10002][2];

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++) cin >> wine[i];

  if(n == 1) {
    cout << max(wine[0], wine[1]);
    return 0;
  }

  drink[0][0] = wine[0];
  drink[1][0] = wine[1];
  drink[1][1] = wine[0] + wine[1];
  drink[2][0] = wine[0] + wine[2];
  drink[2][1] = wine[1] + wine[2];

  for(int i = 3; i < n; i++) {
    drink[i][1] = wine[i] + drink[i-1][0];

    int dmax1 = max(drink[i-2][1], drink[i-3][1]);
    int dmax2 = max(drink[i-2][0], drink[i-3][0]);
    drink[i][0] = wine[i] + max(dmax1, dmax2);
  }

  int max1 = max(drink[n-1][0], drink[n-1][1]);
  int max2 = drink[n-2][1];
  cout << max(max1, max2);
}