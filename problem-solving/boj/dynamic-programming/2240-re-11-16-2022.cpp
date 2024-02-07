#include <bits/stdc++.h>
using namespace std;

int T, W;
int cnt[1002][2];
int plum[1002];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T >> W;

  for(int t = 1; t <= T; t++) {
    cin >> plum[t];
    plum[t]--;
  }
  
  bool cur, pDrop;
  for(int w = 0; w <= W; w++)
    for(int t = 1; t <= T; t++) {
      cur = w % 2;
      cnt[t][cur] = max(cnt[t - 1][cur], cnt[t - 1][!cur]) + (cur == plum[t]);
    }
  cout << max(cnt[T][0], cnt[T][1]);
}