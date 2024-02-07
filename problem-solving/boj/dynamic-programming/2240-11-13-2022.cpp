#include <bits/stdc++.h>
using namespace std;

int d[32][1002][3];

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T, W;
  cin >> T >> W;

  int a;
  for(int t = 1; t <= T; t++) {
    cin >> a;
    d[0][t][1] = d[0][t - 1][1] + (a == 1);
    for(int w = 1; w <= W; w++) {
      if(t < w) break;
      d[w][t][1] = max(d[w - 1][t - 1][2], d[w][t - 1][1]) + (a == 1);
      d[w][t][2] = max(d[w - 1][t - 1][1], d[w][t - 1][2]) + (a == 2);
    }
  }
  int ans = 0;
  for(int w = 0; w <= W; w++)
    ans = max({ans, d[w][T][1], d[w][T][2]});
  cout << ans;
}